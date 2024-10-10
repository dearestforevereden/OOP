#include <iostream>
#include <string>
#include <utility>

int main(){

  std::cout << std::endl;

  std::string defaultString; // 기본 생성자를 사용하여 빈 문자열을 초기화합니다.
  
  std::cout << "C-스트링에서 생성" << std::endl;

  std::string other{"123456789"}; // C 스타일 문자열로부터 초기화합니다.
  std::cout << "other: " << other << std::endl;
  
  std::cout << std::endl;

  std::cout << "C++ 문자열로부터 생성" << std::endl;

  // 다른 문자열로부터 생성합니다.
  std::string str1(other); // 복사 생성자
  std::string tmp(other);
  std::string str2(std::move(tmp)); // 이동 생성자
  std::string str3(other.begin(), other.end()); // 범위 생성자
  std::string str4(other, 2); // 위치를 이용한 생성자
  std::string str5(other, 2, 5); // 위치와 길이를 이용한 생성자
  
  std::cout << "str1: " << str1 << std::endl;
  std::cout << "str2: " << str2 << std::endl;
  std::cout << "str3: " << str3 << std::endl;
  std::cout << "str4: " << str4 << std::endl;
  std::cout << "str5: " << str5 << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "C-스트링으로부터 생성" << std::endl;

  std::string str6("123456789", 5); // C 스타일 문자열을 이용한 생성자
  std::string str7(5, '1'); // 문자열을 반복하여 생성합니다.
  std::string str8({'1', '2', '3', '4', '5', '6', '7', '8', '9'}); // 초기화 리스트를 이용한 생성자
  
  std::cout << "str6: " << str6 << std::endl;
  std::cout << "str7: " << str7 << std::endl;
  std::cout << "str8: " << str8 << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "C++ 문자열의 일부로 생성" << std::endl;
  std::cout << "str6.substr(): "  << str6.substr() << std::endl; // 부분 문자열 생성
  std::cout << "str6.substr(1): "  << str6.substr(1) << std::endl; // 지정된 위치부터의 부분 문자열 생성
  std::cout << "str6.substr(1, 2): "  << str6.substr(1, 2) << std::endl; // 지정된 위치와 길이로 부분 문자열 생성
  
  std::cout << std::endl;

}

