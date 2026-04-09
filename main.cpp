#include "httplib.h"
#include "json.hpp"
#include "QuestionDB.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <algorithm> // std::shuffle

using json = nlohmann::json;

int main() {
    httplib::Server svr;
    QuestionDB db;

    db.initialize("./questions");

    svr.set_mount_point("/", "./web");
    svr.set_mount_point("/images", "./questions");

    // API 1: 전체 과목/단원 정보 넘겨주기 (기존과 동일)
    svr.Get("/api/info", [&](const httplib::Request&, httplib::Response& res) {
        json j = json::array();
        std::map<std::string, std::string> orderedSubjects(subjectMap.begin(), subjectMap.end());
        for (const auto& [subCode, subName] : orderedSubjects) {
            json units = json::array();
            if (unitMap.count(subCode)) {
                std::map<std::string, std::string> orderedUnits(unitMap.at(subCode).begin(), unitMap.at(subCode).end());
                for (const auto& [uCode, uName] : orderedUnits) {
                    units.push_back({{"code", uCode}, {"name", uName}});
                }
            }
            j.push_back({ {"code", subCode}, {"name", subName}, {"units", units} });
        }
        res.set_content(j.dump(), "application/json");
    });

    // 💡 API 2: 시험 시작 (문제 목록 전체를 프론트엔드로 전송 - Stateless 핵심)
    svr.Post("/api/start", [&](const httplib::Request& req, httplib::Response& res) {
        auto data = json::parse(req.body);
        
        std::unordered_set<std::string> selectedUnits;
        for (const auto& item : data["units"]) {
            selectedUnits.insert(item.get<std::string>());
        }

        // 조건에 맞는 문제 풀(Pool) 가져오기
        auto pool = db.getFilteredPool(selectedUnits, data["startY"], data["endY"]);
        
        // 1. 문제 섞기 (랜덤 셔플)
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(pool.begin(), pool.end(), g);

        // 2. 사용자가 요청한 개수만큼 자르기
        int requestCount = data["count"];
        size_t actualCount = std::min(static_cast<size_t>(requestCount), pool.size());

        // 3. 반환할 JSON 배열 만들기
        json questionList = json::array();
        for (size_t i = 0; i < actualCount; ++i) {
            questionList.push_back({
                {"displayName", pool[i].getDisplayName()},
                {"qPath", "/images/" + pool[i].questionPath.filename().string()},
                {"aPath", "/images/" + pool[i].answerPath.filename().string()}
            });
        }

        // 결과 응답
        json response = { 
            {"status", "ok"}, 
            {"poolSize", pool.size()}, 
            {"questions", questionList} // 이 안에 이번 시험의 모든 데이터가 들어갑니다!
        };
        res.set_content(response.dump(), "application/json");
    });

    svr.listen("0.0.0.0", 8080);

    return 0;
}