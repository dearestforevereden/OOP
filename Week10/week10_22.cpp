#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

int main() {

    // 부울린 값을 true/false로 출력
    std::cout << std::boolalpha << std::endl;

    // 두 개의 정수 벡터 초기화
    std::vector<int> vec1{1, 1, 4, 3, 5, 8, 6, 7, 9, 2};
    std::vector<int> vec2{1, 2, 3};
    
    // vec1 정렬
    std::sort(vec1.begin(), vec1.end());
    std::vector<int> vec(vec1);  // vec1을 복사하여 vec 생성
 
    // vec1이 vec2를 포함하는지 확인
    std::cout << "std::includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()): " << std::includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()) << std::endl;
    // 결과: true (vec1이 vec2를 포함함)
    
    std::cout << std::endl;

    // vec1에 vec2의 요소를 추가
    vec1.reserve(vec1.size() + vec2.size());
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    for (auto v: vec1) 
        std::cout << v << " ";
    // vec1: 1 1 1 2 2 3 3 4 5 6 7 8 9 (vec2의 요소가 추가된 상태)
    
    std::cout << std::endl;
    
    // vec1을 병합하여 정렬
    std::inplace_merge(vec1.begin(), vec1.end() - vec2.size(), vec1.end());  
    for (auto v: vec1) 
        std::cout << v << " ";
    // 결과: 1 1 1 2 2 3 3 4 5 6 7 8 9 (병합 후 정렬된 상태)
    
    std::cout << "\n\n";
    
    // vec2에 10 추가
    vec2.push_back(10);
    
    // vec와 vec2 출력
    std::cout << "vec:                      ";
    for (auto v: vec) 
        std::cout << v << " ";
    std::cout << std::endl;
    // vec: 1 1 2 3 4 5 6 7 8 9
    
    std::cout << "vec2:                     ";
    for (auto v: vec2) 
        std::cout << v << " ";
    // vec2: 1 2 3 10

    // 두 벡터의 합집합 계산
    std::vector<int> res;
    std::set_union(vec.begin(), vec.end(), vec2.begin(), vec2.end(), std::back_inserter(res));
    std::cout << "\n" << "set_union:                ";
    for (auto v : res) 
        std::cout << v << " ";
    // 결과: 1 1 2 3 4 5 6 7 8 9 10
    
    // 두 벡터의 교집합 계산
    res = {};
    std::set_intersection(vec.begin(), vec.end(), vec2.begin(), vec2.end(), std::back_inserter(res));
    std::cout << "\n" << "set_intersection:         ";
    for (auto v : res) 
        std::cout << v << " ";
    // 결과: 1 2 3
    
    // vec에서 vec2를 뺀 차집합 계산
    res = {};
    std::set_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(), std::back_inserter(res));
    std::cout << "\n" << "set_difference:           ";
    for (auto v : res) 
        std::cout << v << " ";
    // 결과: 1 4 5 6 7 8 9
    
    // 두 벡터의 대칭 차집합 계산
    res = {};
    std::set_symmetric_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(), std::back_inserter(res));
    std::cout << "\n" << "set_symmetric_difference: ";
    for (auto v : res) 
        std::cout << v << " ";
    // 결과: 1 4 5 6 7 8 9 10

    std::cout << "\n\n";
}

