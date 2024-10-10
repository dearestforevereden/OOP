#include <iostream>
#include <string>

// 함수 선언
void showStringInfo(const std::string& s);

int main(){

  std::string str;
  showStringInfo(str);
  
  str += "12345"; // 문자열에 "12345"를 추가합니다.
  showStringInfo(str);
  
  str.resize(30); // 문자열의 크기를 30으로 조정합니다.
  showStringInfo(str);

  str.reserve(1000); // 문자열의 용량을 1000으로 설정합니다.
  showStringInfo(str);
  
  str.shrink_to_fit(); // 필요한 용량만큼 메모리를 할당합니다.
  showStringInfo(str);

}

// 문자열 정보 출력 함수 정의
void showStringInfo(const std::string& s){

  std::cout << s << std::endl;
  std::cout << "s.size(): " << s.size() << std::endl; // 문자열의 길이를 출력합니다.
  std::cout << "s.capacity(): " << s.capacity() << std::endl; // 문자열의 용량을 출력합니다.
  std::cout << "s.max_size(): " << s.max_size() << std::endl; // 문자열이 가질 수 있는 최대 크기를 출력합니다.
  std::cout << std::endl;

}

