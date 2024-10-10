#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// 정수를 문자열로 변환하는 함수
std::string toString(int i){
  std::stringstream buff;
  buff.str("");
  buff << i;
  std::string val = buff.str();
  return val;
}

// 문자열을 정수로 변환하는 함수
int toInt(const std::string& s){
  std::stringstream buff;
  buff.str("");
  buff << s;
  int value;
  buff >> value;
  return value;
}

int main() {

  std::cout << std::endl;

  // 문자열 벡터 초기화
  std::vector<int> myInts;
  std::vector<std::string> myStrings{"94", "5", "39", "-4", "-49", "1001", "-77", "23", "0", "84", "59", "96", "6", "-94", "87"};
  
  // 문자열을 정수로 변환하여 정수 벡터에 삽입
  std::transform(myStrings.begin(), myStrings.end(), std::back_inserter(myInts), toInt);
  
  // 정수 벡터 출력
  for (auto i: myInts) std::cout << i << " ";
  std::cout << "\n\n"; // 출력: 94 5 39 -4 -49 1001 -77 23 0 84 59 96 6 -94 87 

  // 정수 벡터의 최소, 최대 요소 찾기
  auto paInt = std::minmax_element(myInts.begin(), myInts.end());
  std::cout << "std::minmax_element(myInts.begin(), myInts.end()): " << "(" << *paInt.first << ", " << *paInt.second << ")" << std::endl;
  // 출력: std::minmax_element(myInts.begin(), myInts.end()): (-94, 1001)

  // 문자열 벡터의 사전식 최소, 최대 요소 찾기
  auto paStr = std::minmax_element(myStrings.begin(), myStrings.end());
  std::cout << "std::minmax_element(myStrings.begin(), myStrings.end()): " << "(" << *paStr.first << ", " << *paStr.second << ")" << std::endl;
  // 출력: std::minmax_element(myStrings.begin(), myStrings.end()): (-4, 96)

  // 문자열을 정수로 변환하여 비교한 최소, 최대 요소 찾기
  auto paStrAsInt = std::minmax_element(myStrings.begin(), myStrings.end(), [](std::string a, std::string b){ return toInt(a) < toInt(b); });
  std::cout << "std::minmax_element(myStrings.begin(), myStrings.end()): " << "(" << *paStrAsInt.first << ", " << *paStrAsInt.second << ")" << std::endl;
  // 출력: std::minmax_element(myStrings.begin(), myStrings.end()): (-94, 1001)

  std::cout << std::endl;

}

