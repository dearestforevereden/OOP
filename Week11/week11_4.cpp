#include <array>
#include <iostream>
#include <numeric>
#include <vector>

int main() {

  std::cout << std::endl;

  // 정적 배열 초기화
  std::array<int, 9> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};

  // std::accumulate 함수는 배열의 모든 요소를 합산한다.
  std::cout << "std::accumulate(arr.begin(), arr.end(), 0): " << std::accumulate(arr.begin(), arr.end(), 0) << std::endl;
  // 출력: std::accumulate(arr.begin(), arr.end(), 0): 45

  // std::accumulate 함수는 배열의 모든 요소를 곱한 값을 반환한다.
  std::cout << "std::accumulate(arr.begin(), arr.end(), 1, [](int a, int b){ return a * b; }): " << std::accumulate(arr.begin(), arr.end(), 1, [](int a, int b){ return a * b; }) << std::endl;
  // 출력: std::accumulate(arr.begin(), arr.end(), 1, [](int a, int b){ return a * b; }): 362880

  std::cout << std::endl;

  // 벡터 초기화
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> myVec;

  // std::adjacent_difference 함수는 입력 범위의 인접한 요소들의 차이 또는 주어진 이진 연산의 결과를 계산한다.
  std::cout << "adjacent_difference: " << std::endl;
  std::adjacent_difference(vec.begin(), vec.end(), std::back_inserter(myVec), [](int a, int b){ return a * b; });
  for (auto v: vec) std::cout << v << " ";
  std::cout << std::endl;
  for (auto v: myVec) std::cout << v << " ";
  // 출력:
  // vec: 1 2 3 4 5 6 7 8 9 
  // myVec: 1 2 6 12 20 30 42 56 72 

  std::cout << "\n\n";

  // std::inner_product 함수는 두 입력 범위의 내적을 계산한다.
  std::cout << "std::inner_product(vec.begin(), vec.end(), arr.begin(), 0): " << std::inner_product(vec.begin(), vec.end(), arr.begin(), 0) << std::endl;
  // 출력: std::inner_product(vec.begin(), vec.end(), arr.begin(), 0): 285

  std::cout << std::endl;

  myVec = {};
  // std::partial_sum 함수는 입력 범위의 부분합을 계산한다.
  std::partial_sum(vec.begin(), vec.end(), std::back_inserter(myVec));
  std::cout << "partial_sum: ";
  for (auto v: myVec) std::cout << v << " ";
  // 출력: partial_sum: 1 3 6 10 15 21 28 36 45 

  std::cout << "\n\n";

  // std::iota 함수는 시작값에서 시작하여 연속적인 값을 채운다.
  std::cout << "iota: ";
  std::vector<int> myLongVec(100);
  std::iota(myLongVec.begin(), myLongVec.end(), 2000);
  for (auto v: myLongVec) std::cout << v << " ";
  // 출력: iota: 2000 2001 2002 2003 ... 2098 2099

  std::cout << "\n\n";

}

