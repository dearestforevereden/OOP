#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

// 홀수인지 확인하는 함수
bool isOdd(int i){ 
    return (i % 2); 
}

int main() {
    // 부울린 값을 true/false로 출력
    std::cout << std::boolalpha << std::endl;

    // 정수 벡터 초기화
    std::vector<int> vec{1, 4, 3, 4, 5, 6, 7, 3, 4, 5, 6, 0, 4, 8, 4, 6, 6, 5, 8, 8, 3, 9, 3, 7, 6, 4, 8};

    // 벡터의 초기 값 출력
    for (auto v: vec) 
        std::cout << v << " ";
    std::cout << "\n\n";

    // 벡터를 홀수와 짝수로 분할, 반환된 반복자는 첫 번째 짝수를 가리킴
    auto parPoint = std::partition(vec.begin(), vec.end(), isOdd);
    
    // 분할된 벡터 출력
    for (auto v: vec) 
        std::cout << v << " ";
    std::cout << std::endl;
    
    // 분할된 벡터의 홀수 부분 출력
    for (auto v = vec.begin(); v != parPoint; ++v) 
        std::cout << *v << " ";
    std::cout << std::endl;
    
    // 분할된 벡터의 짝수 부분 출력
    for (auto v = parPoint; v != vec.end(); ++v) 
        std::cout << *v << " ";
    std::cout << std::endl;
    
    std::cout << std::endl;

    // 벡터가 isOdd 함수에 따라 분할되었는지 확인
    std::cout << "std::is_partitioned(vec.begin(), vec.end(), isOdd): " << std::is_partitioned(vec.begin(), vec.end(), isOdd) << std::endl;

    // partition_point와 parPoint가 같은지 확인
    std::cout << "std::partition_point(vec.begin(), vec.end(), isOdd) == parPoint: " << (std::partition_point(vec.begin(), vec.end(), isOdd) == parPoint) << std::endl;

    std::cout << std::endl;
    
    // 5보다 작은 요소들을 새로운 리스트 'li'에 복사, 나머지는 'de'에 복사
    std::list<int> li;
    std::list<int> de;
    std::partition_copy(vec.begin(), vec.end(), std::back_inserter(li), std::back_inserter(de), [](int i) { return i < 5; });
    
    // 'li' 리스트 출력
    for (auto v: li) 
        std::cout << v << " ";
    std::cout << std::endl;
    
    // 'de' 리스트 출력
    for (auto v: de) 
        std::cout << v << " "; 
    
    std::cout << "\n\n";
}

