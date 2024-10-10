#include <algorithm>
#include <iostream>
#include <vector>

int main() {

    // 부울린 값을 true/false로 출력
    std::cout << std::boolalpha << std::endl;

    // 정수 벡터 초기화
    std::vector<int> vec{4, 3, 2, 1, 5, 6, 7, 9, 10};
    for (auto v : vec) std::cout << v << " ";
    std::cout << std::endl;

    // 벡터를 힙으로 만듦
    std::make_heap(vec.begin(), vec.end());
    for (auto v : vec) std::cout << v << " ";
    std::cout << std::endl;

    // 벡터가 힙인지 확인
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl;

    std::cout << std::endl;

    // 벡터에 100 추가
    vec.push_back(100);
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl;

    // 힙이 아닌 부분의 첫 번째 요소 출력
    std::cout << "*std::is_heap_until(vec.begin(), vec.end()): " << *std::is_heap_until(vec.begin(), vec.end()) << std::endl;
    for (auto v : vec) std::cout << v << " ";
    std::cout << std::endl;

    // 힙 속성을 다시 유지하도록 함
    std::push_heap(vec.begin(), vec.end());
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl;
    for (auto v : vec) std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "\n\n";

    // 힙의 루트 요소를 벡터의 끝으로 이동
    std::pop_heap(vec.begin(), vec.end());
    for (auto v : vec) std::cout << v << " ";
    std::cout << std::endl;

    // 힙이 아닌 부분의 첫 번째 요소 출력
    std::cout << "*std::is_heap_until(vec.begin(), vec.end()): " << *std::is_heap_until(vec.begin(), vec.end()) << std::endl;

    // 마지막 요소를 제거하여 벡터 크기 조정
    vec.resize(vec.size() - 1);
    std::cout << "std::is_heap(vec.begin(), vec.end()): " << std::is_heap(vec.begin(), vec.end()) << std::endl;

    std::cout << std::endl;

    // 힙의 루트 요소 출력
    std::cout << "vec.front(): " << vec.front() << std::endl;

    std::cout << std::endl;
}

