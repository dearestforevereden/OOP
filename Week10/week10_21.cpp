#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

// 절대값 기준으로 비교하는 함수
bool isLessAbs(int a, int b){
  return std::abs(a) < std::abs(b);
}

int main(){

  // 부울린 값을 true/false로 출력
  std::cout << std::boolalpha << std::endl;

  // 정수 벡터 초기화
  std::vector<int> vec{-3, 0, -3, 2, -3, 5, -3, 7, -0, 6, -3, 5, -6, 8, 9, 0, 8, 7, -7, 8, 9, -6, 3, -3, 2};

  // 벡터의 초기 값 출력
  for (auto v: vec) 
    std::cout << v << " ";

  // 벡터를 절대값 기준으로 정렬
  std::sort(vec.begin(), vec.end(), isLessAbs);
  std::cout << std::endl;
  
  // 정렬된 벡터 출력
  for (auto v: vec) 
    std::cout << v << " ";
  
  std::cout << std::endl;
  std::cout << std::endl;

  // 절대값 기준으로 이진 탐색
  std::cout << "std::binary_search(vec.begin(), vec.end(), -5, isLessAbs): " << std::binary_search(vec.begin(), vec.end(), -5, isLessAbs) << std::endl;
  std::cout << "std::binary_search(vec.begin(), vec.end(), 5, isLessAbs): " << std::binary_search(vec.begin(), vec.end(), 5, isLessAbs) << std::endl;
  
  // 절대값 3에 대한 범위 찾기
  auto pair = std::equal_range(vec.begin(), vec.end(), 3, isLessAbs);
  
  std::cout << std::endl;
  
  // 절대값 3의 첫 번째 위치와 마지막 위치 출력
  std::cout << "Position of first 3: " << std::distance(vec.begin(), pair.first) << std::endl;
  std::cout << "Position of last 3: " << std::distance(vec.begin(), pair.second) - 1 << std::endl;
  
  // 절대값 3인 요소들 출력
  for (auto threeIt = pair.first; threeIt != pair.second; ++threeIt) 
    std::cout << *threeIt << " ";
  
  std::cout << "\n\n";

}

