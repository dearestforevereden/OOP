#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(){
  // 프로그램 실행 시 줄 바꿈
  std::cout << std::endl;
  
  // 정수형 벡터 myVec 초기화
  std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 9};
  // 크기가 10인 정수형 벡터 myVec2 초기화
  std::vector<int> myVec2(10);

  // myVec에서 홀수인 원소들만 myVec2의 시작 위치 + 3 부터 복사
  std::copy_if(myVec.begin(), myVec.end(), myVec2.begin() + 3, [](int a){ return a % 2; });
  for (auto v: myVec2) std::cout << v << " ";

  // 줄 바꿈 및 출력
  std::cout << "\n\n";
  
  // 문자열 str 초기화
  std::string str{"abcdefghijklmnop"};
  // 길이가 21인 문자열 str2 초기화, 모두 '-' 문자로 구성
  std::string str2{"---------------------"};
  
  // str2 출력
  std::cout << str2 << std::endl;
  // str의 모든 문자들을 str2의 끝에서부터 역방향으로 복사
  std::copy_backward(str.begin(), str.end(), str2.end());
  // 결과 출력
  std::cout << str2 << std::endl;
  
  // 줄 바꿈 및 출력
  std::cout << std::endl;
  
  // 원본 문자열 str 출력
  std::cout << str << std::endl;
  // str의 처음 5개의 문자를 str의 끝에서부터 역방향으로 복사
  std::copy_backward(str.begin(), str.begin() + 5, str.end());
  // 결과 출력
  std::cout << str << std::endl;
  
  // 줄 바꿈 및 출력
  std::cout << std::endl;
}

