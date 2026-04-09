#pragma once
#include "Question.h"
#include <vector>
#include <iostream>
#include <unordered_set>

struct CategoryStats {
    int totalCount = 0;
    std::unordered_map<std::string, int> subjectCounts;
    std::unordered_map<std::string, std::unordered_map<std::string, int>> unitCounts;
};

class QuestionDB {
private:
    std::vector<Question> allQuestions;
    CategoryStats stats;

public:
    void initialize(const fs::path& sourceDir) {
        allQuestions.clear();
        stats = CategoryStats();

        if (!fs::exists(sourceDir)) {
            fs::create_directories(sourceDir); // 폴더가 없으면 자동 생성
            return;
        }

        std::unordered_map<std::string, fs::path> questionFiles;
        std::unordered_map<std::string, fs::path> answerFiles;

        // 1. 디렉토리 내 파일 고속 스캔
        for (const auto& entry : fs::directory_iterator(sourceDir)) {
            if (!entry.is_regular_file()) continue;

            std::string filename = entry.path().stem().string(); 
            // 파일명 규칙 검증: 00_00_00_0000_Q (총 15글자)
            if (filename.length() != 15) continue; 

            char type = filename.back(); 
            std::string idPart = filename.substr(0, 13); // "00_00_00_0000" 추출

            if (type == 'Q') questionFiles[idPart] = entry.path();
            else if (type == 'A') answerFiles[idPart] = entry.path();
        }

        // 2. Q와 A가 매칭되는 파일만 DB 등록 및 통계 산출
        allQuestions.reserve(questionFiles.size()); // 메모리 재할당 방지 최적화
        
        for (auto const& [id, qPath] : questionFiles) {
            if (answerFiles.count(id)) {
                Question q;
                q.subjectCode  = id.substr(0, 2);
                q.unitCode     = id.substr(3, 2);
                q.problemCode  = id.substr(6, 2);
                q.year         = std::stoi(id.substr(9, 4));
                q.questionPath = qPath;
                q.answerPath   = answerFiles.at(id);

                allQuestions.push_back(q);

                stats.totalCount++;
                stats.subjectCounts[q.subjectCode]++;
                stats.unitCounts[q.subjectCode][q.unitCode]++;
            }
        }
    }

    // 통계 Getter (GUI 범위 선택 시 개수 표기용)
    int getTotalCount() const { return stats.totalCount; }
    int getSubjectCount(const std::string& subCode) const {
        return stats.subjectCounts.count(subCode) ? stats.subjectCounts.at(subCode) : 0;
    }
    int getUnitCount(const std::string& subCode, const std::string& unitCode) const {
        if (stats.unitCounts.count(subCode) && stats.unitCounts.at(subCode).count(unitCode))
            return stats.unitCounts.at(subCode).at(unitCode);
        return 0;
    }

    // 조건에 맞는 문제 풀(Pool) 필터링
    // 조건에 맞는 문제 풀(Pool) 필터링 (다중 선택 지원)
    std::vector<Question> getFilteredPool(const std::unordered_set<std::string>& selectedUnits, 
                                          int startYear, int endYear) const {
        std::vector<Question> pool;
        for (const auto& q : allQuestions) {
            // "00_01" 형태로 조합하여 선택 목록에 있는지 확인
            std::string code = q.subjectCode + "_" + q.unitCode;
            bool unitMatch = selectedUnits.count(code) > 0;
            
            // 연도가 범위 안에 있거나, 연도혼합(0)인 경우 포함
            bool yearMatch = false;
            
            // 만약 사용자가 하한선(2000)을 선택했다면, 연도가 0이거나 2000 이하인 모든 예외/테스트 문제를 포함
            if (startYear == 2000 && q.year <= 2000) {
                yearMatch = true;
            } 
            // 그 외의 일반적인 연도 범위 필터링
            else if (q.year >= startYear && q.year <= endYear) {
                yearMatch = true;
            }
            if (unitMatch && yearMatch) {
                pool.push_back(q);
            }
        }
        return pool;
    }
};