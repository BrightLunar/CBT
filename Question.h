#pragma once
#include <string>
#include <filesystem>
#include <unordered_map>

namespace fs = std::filesystem;

// [대분류] 과목 코드 맵핑 (탐색 최적화를 위해 unordered_map 사용)
inline std::unordered_map<std::string, std::string> subjectMap = {
    {"00", "미적분학 (Calculus)"},
    {"01", "해석학 (Real Analysis)"},
    {"02", "현대대수학 (Abstract Algebra)"},
    {"03", "위상수학 (Topology)"},
    {"04", "복소함수론 (Complex Analysis)"},
    {"05", "미분기하학 (Differential Geometry)"},
    {"06", "정수론 (Number Theory)"},
    {"07", "선형대수학 (Linear Algebra)"},
    {"08", "이산수학 (Discrete Mathematics)"},
    {"09", "확률과 통계 (Probability & Statistics)"}
};

// [소분류] (이전 대화에서 확정한 모든 소분류 + "기타(Others)"가 포함된 전체 목록 적용)
inline std::unordered_map<std::string, std::unordered_map<std::string, std::string>> unitMap = {
    // 00: 미적분학
    {"00", {
        {"00", "이중적분 (Double Integral)"},
        {"01", "그린 정리 (Green's Thm)"},
        {"02", "삼중적분 (Triple Integral)"},
        {"03", "기타 (Others)"}
    }},
    // 01: 해석학
    {"01", {
        {"00", "실수의 완비성 (Completeness of Real Numbers)"},
        {"01", "수열 (Seq)"},
        {"02", "상극한, 하극한 (Limsup, Liminf)"},
        {"03", "연속 (Continuity)"},
        {"04", "균등 연속 (Uniform Continuity)"},
        {"05", "단조 함수와 역함수 (Monotone Ft & Inverse Ft)"},
        {"06", "미분 (Differentiation)"},
        {"07", "평균값 정리 (MVT)"},
        {"08", "Darboux 정리 (Darboux's Thm)"},
        {"09", "코시 평균값 정리 (CMVT)"},
        {"10", "로피탈의 정리 (L'Hopital's Rule)"},
        {"11", "테일러 정리 (Taylor's Thm)"},
        {"12", "볼록 함수 (Convex Ft)"},
        {"13", "적분 (Integration)"},
        {"14", "이상 적분 (Improper Integral)"},
        {"15", "함수열 (Seq of Fts)"},
        {"16", "함수항 급수 (Series of Fts)"},
        {"17", "급수 (Series)"},
        {"18", "멱급수의 수렴 반경과 수렴 구간 (ROC & IOC of Power Series)"},
        {"19", "기타 (Others)"}
    }},
    // 02: 현대대수학
    {"02", {
        {"00", "군의 기본 정리 (Fundamental Thm of Groups)"},
        {"01", "부분군 (Subgroup)"},
        {"02", "순환군 (Cyclic Group)"},
        {"03", "동형 사상과 준동형 사상 (Isomorphism & Homomorphism)"},
        {"04", "Lagrange 정리 (Lagrange's Thm)"},
        {"05", "정규 부분군 (Normal Subgroup)"},
        {"06", "상군 (Quotient Group)"},
        {"07", "상군과 준동형 사상 (Quotient Group & Homomorphism)"},
        {"08", "대칭군과 교대군 (Symmetric & Alternating Group)"},
        {"09", "유한 가환군 (Finite Abelian Group)"},
        {"10", "실로우 정리 (Sylow Thm)"},
        {"11", "환 (Ring)"},
        {"12", "아이디얼 (Ideal)"},
        {"13", "환 준동형 사상 (Ring Homomorphism)"},
        {"14", "소, 극대 아이디얼 (Prime & Maximal Ideal)"},
        {"15", "F[x]에서의 연산 (Operations in F[x])"},
        {"16", "근, 기약성 (Roots & Irreducibility)"},
        {"17", "F[x]/<f(x)>의 구조 (Structure of F[x]/<f(x)>)"},
        {"18", "정역에서의 연산 (Operations in Integral Domain)"},
        {"19", "ED, PID, UFD, 분수체 (ED, PID, UFD, Field of Fractions)"},
        {"20", "확대체 (Field Extension)"},
        {"21", "유한체 (Finite Field)"},
        {"22", "Galois 이론 (Galois Theory)"},
        {"23", "작도 가능성 (Constructibility)"},
        {"24", "기타 (Others)"}
    }},
    // 03: 위상수학
    {"03", {
        {"00", "집합 및 함수 (Sets & Fts)"},
        {"01", "동치 관계 (Equivalence Relation)"},
        {"02", "근방 (Neighborhood)"},
        {"03", "내부, 외부, 폐포, 경계 (Int, Ext, Cl, Bd)"},
        {"04", "수렴성 (Convergence)"},
        {"05", "연속 (Continuity)"},
        {"06", "위상 동형 (Homeomorphism)"},
        {"07", "약위상 (Weak Topology)"},
        {"08", "상위상 (Quotient Topology)"},
        {"09", "거리 공간 (Metric Space)"},
        {"10", "가산 공리 (Countability Axioms)"},
        {"11", "분리 공리 (Separation Axioms)"},
        {"12", "컴팩트 (Compactness)"},
        {"13", "연결 (Connectedness)"},
        {"14", "연결 성분 (Connected Components)"},
        {"15", "기타 (Others)"}
    }},
    // 04: 복소함수론
    {"04", {
        {"00", "복소수 (Complex Numbers)"},
        {"01", "지수 형식 (Exponential Form)"},
        {"02", "선형 분수 변환 (LFT)"},
        {"03", "해석 함수 (Analytic Ft)"},
        {"04", "적분 (Integration)"},
        {"05", "리우빌 정리 (Liouville's Thm)"},
        {"06", "가우스 평균값 정리 (Gauss's MVT)"},
        {"07", "최대 절댓값 정리 (Maximum Modulus Thm)"},
        {"08", "급수 (Series)"},
        {"09", "유수 정리 (Residue Thm)"},
        {"10", "m차 극의 유수 (Residue at Pole of Order m)"},
        {"11", "단순 극의 유수 (Residue at Simple Pole)"},
        {"12", "세 가지 고립 특이점 (Three Isolated Singularities)"},
        {"13", "유수의 응용 (Applications of Residues)"},
        {"14", "조르당 보조정리 (Jordan's Lemma)"},
        {"15", "편각 원리 (Argument Principle)"},
        {"16", "루셰 정리 (Rouche's Thm)"},
        {"17", "기타 (Others)"}
    }},
    // 05: 미분기하학
    {"05", {
        {"00", "곡선 (Curves)"},
        {"01", "곡률과 열률 (Curvature & Torsion)"},
        {"02", "곡면 (Surfaces)"},
        {"03", "법곡률 (Normal Curvature)"},
        {"04", "면적분 (Surface Integral)"},
        {"05", "등장 사상 (Isometry)"},
        {"06", "곡면의 대역 이론 (Global Theory of Surfaces)"},
        {"07", "측지 곡률 (Geodesic Curvature)"},
        {"08", "Gauss-Bonnet 정리 (Gauss-Bonnet Thm)"},
        {"09", "기타 (Others)"}
    }},
    // 06: 정수론
    {"06", {
        {"00", "정수론 기초 (Basics of Number Theory)"},
        {"01", "디오판투스 방정식 (Diophantine Equations)"},
        {"02", "팩토리얼의 소인수의 지수 (Legendre's Formula)"},
        {"03", "선형 합동식 (Linear Congruence)"},
        {"04", "중국인의 나머지 정리 (CRT)"},
        {"05", "페르마의 소정리 (Fermat's Little Thm)"},
        {"06", "윌슨의 정리 (Wilson's Thm)"},
        {"07", "오일러의 정리 (Euler's Thm)"},
        {"08", "위수 (Order)"},
        {"09", "원시근 (Primitive Root)"},
        {"10", "이차 합동식 (Quadratic Congruence)"},
        {"11", "기타 (Others)"}
    }},
    // 07: 선형대수학
    {"07", {
        {"00", "행렬식 (Determinant)"},
        {"01", "부분공간 (Subspace)"},
        {"02", "1차 독립과 1차 종속 (Linear Independence & Dependence)"},
        {"03", "차원 (Dimension)"},
        {"04", "내적 공간 (Inner Product Space)"},
        {"05", "선형 변환 (Linear Ft)"},
        {"06", "고윳값과 고유 벡터 (Eigenvalue & Eigenvector)"},
        {"07", "이차 형식 (Quadratic Form)"},
        {"08", "기타 (Others)"}
    }},
    // 08: 이산수학
    {"08", {
        {"00", "기본적 계수법 (Basic Counting)"},
        {"01", "순열 (Permutation)"},
        {"02", "조합 (Combination)"},
        {"03", "이항계수 (Binomial Coefficient)"},
        {"04", "포함-배제의 원리 (Inclusion-Exclusion Principle)"},
        {"05", "점화식과 특성 방정식 (Recurrence Relation & Characteristic Equation)"},
        {"06", "생성 함수 (Generating Ft)"},
        {"07", "그래프 (Graph)"},
        {"08", "평면 그래프 (Planar Graph)"},
        {"09", "색칠 문제 (Coloring Problem)"},
        {"10", "행렬과 그래프 (Matrix & Graph)"},
        {"11", "기타 (Others)"}
    }},
    // 09: 확률과 통계
    {"09", {
        {"00", "확률 (Prob)"},
        {"01", "조건부 확률 (Conditional Prob)"},
        {"02", "확률 변수와 확률 분포 (RV & Prob Distribution)"},
        {"03", "결합 확률 변수와 확률 분포 (Joint RV & Prob Distribution)"},
        {"04", "변수 변환 (Transformation of Variables)"},
        {"05", "조건부 분포 (Conditional Distribution)"},
        {"06", "기댓값 (Expectation)"},
        {"07", "조건부 기댓값 (Conditional Expectation)"},
        {"08", "분산과 공분산 (Var & Cov)"},
        {"09", "적률 생성 함수 (MGF)"},
        {"10", "이산형 확률 분포 (Discrete Prob Distribution)"},
        {"11", "연속형 확률 분포 (Continuous Prob Distribution)"},
        {"12", "확률 표본과 표본 분포 (Random Sample & Sampling Distribution)"},
        {"13", "모평균의 추정 (Estimation of Population Mean)"},
        {"14", "모비율의 추정 (Estimation of Population Proportion)"},
        {"15", "검정 (Hypothesis Testing)"},
        {"16", "기타 (Others)"}
    }}
};

struct Question {
    std::string subjectCode; // 00
    std::string unitCode;    // 00
    std::string problemCode; // 00
    int year;                // 0000
    fs::path questionPath;
    fs::path answerPath;

    // GUI 출력용 포맷팅 함수 (예: "[2026] 현대대수학 - 갈루아 이론")
    std::string getDisplayName() const {
        std::string subName = subjectMap.count(subjectCode) ? subjectMap.at(subjectCode) : "알 수 없음";
        std::string unitName = (unitMap.count(subjectCode) && unitMap.at(subjectCode).count(unitCode)) 
                            ? unitMap.at(subjectCode).at(unitCode) : "알 수 없음";
        
        // 연도가 1900을 초과하는 기출문제들
        if(year > 1900) {
            return "[" + std::to_string(year) + "] " + subName + " - " + unitName;
        } 
        else if(year == 0000) {
            return "[테스트케이스] " + subName + " - " + unitName;
        }
        // 1900 이하 (테스트케이스, 연도혼합 등)
        else {
            return "[연도혼합/기타] " + subName + " - " + unitName;
        }
    }
};