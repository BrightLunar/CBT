#pragma once
#include "Question.h"
#include <vector>
#include <random>
#include <algorithm>

class CBTManager {
private:
    std::vector<Question> sessionQuestions;
    size_t currentIndex = 0;
    bool answerRevealed = false;

public:
    // 필터링된 풀에서 겹치지 않게 문제 추출 및 세션 초기화
    void startNewSession(std::vector<Question> filteredPool, int requestCount) {
        if (filteredPool.empty()) {
            sessionQuestions.clear();
            return;
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(filteredPool.begin(), filteredPool.end(), g);

        size_t actualCount = std::min(static_cast<size_t>(requestCount), filteredPool.size());
        sessionQuestions.assign(filteredPool.begin(), filteredPool.begin() + actualCount);
        
        currentIndex = 0;
        answerRevealed = false;
    }

    // 현재 문제 객체 반환
    const Question* getCurrentQuestion() const {
        if (currentIndex < sessionQuestions.size()) return &sessionQuestions[currentIndex];
        return nullptr;
    }

    // 진행 상황 반환 (예: return {3, 10} -> 10문제 중 3번 문제)
    std::pair<int, int> getProgress() const {
        return { static_cast<int>(currentIndex + 1), static_cast<int>(sessionQuestions.size()) };
    }

    void revealAnswer() { answerRevealed = true; }
    bool isRevealed() const { return answerRevealed; }
    
    // 다음 문제로 이동. 더 이상 문제가 없으면 false 반환
    bool goToNext() {
        if (currentIndex + 1 < sessionQuestions.size()) {
            currentIndex++;
            answerRevealed = false; // 새 문제이므로 정답 가리기
            return true;
        }
        return false;
    }
    
    bool isSessionEmpty() const { return sessionQuestions.empty(); }
};