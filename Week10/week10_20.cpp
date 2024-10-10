#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {

    // 부울린 값을 true/false로 출력
    std::cout << std::boolalpha << std::endl;
    
    // 문자열 초기화
    std::string str{"RUdAjdDkaACsdfjwldXmnEiVSEZTiepfgOIkue"};
    
    // 초기 문자열 출력
    std::cout << str << std::endl;

    // 문자열이 정렬되어 있는지 확인
    std::cout << "std::is_sorted(str.begin(), str.end()): " << std::is_sorted(str.begin(), str.end()) << std::endl;
    
    std::cout << std::endl;
    
    // 문자열의 앞 30자를 정렬
    std::partial_sort(str.begin(), str.begin() + 30, str.end());
    std::cout << str << std::endl;

    // 문자열이 정렬되어 있는 부분의 끝을 찾음
    auto sortUntil = std::is_sorted_until(str.begin(), str.end());
    std::cout << "Sorted until: " << *sortUntil << std::endl;
    
    // 정렬된 부분 출력
    for (auto charIt = str.begin(); charIt != sortUntil; ++charIt) 
        std::cout << *charIt;
    
    std::cout << "\n\n";
    
    // 정수 벡터 초기화
    std::vector<int> vec{1, 0, 4, 3, 5};
    
    // 벡터의 각 요소에 대해 nth_element를 사용하여 부분 정렬
    auto vecIt = vec.begin();
    while (vecIt != vec.end()) {
        std::nth_element(vec.begin(), vecIt++, vec.end());
        
        // 현재 요소가 몇 번째인지 출력
        std::cout << std::distance(vec.begin(), vecIt) << "-th ";
        
        // 부분 정렬된 벡터 출력
        for (auto v: vec) 
            std::cout << v;
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}

