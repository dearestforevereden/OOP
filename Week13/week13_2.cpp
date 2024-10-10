#include <algorithm>
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

int main(){

  std::cout << std::endl;

  std::string privateAddress="192.168.178.21";

  // IPv4 주소에 대한 정규 표현식
  std::string ip4RegEx(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");

  // 정규 표현식 객체 생성
  std::regex rgx(ip4RegEx);

  // 검색 결과를 담을 객체
  std::smatch smatch;

  // 정규 표현식을 사용하여 정확히 일치하는지 검사
  if (std::regex_match(privateAddress, smatch, rgx)){

    // 각 캡처 그룹 출력
    for ( auto cap: smatch ){

      std::cout << "capture group: " << cap << std::endl;
      if (cap.matched){

        // 각 문자를 16진수로 출력 (기본 포함)
        std::cout << "hex: ";
        std::for_each(cap.first, cap.second, [](int v){std::cout << std::showbase << std::hex << v << " ";});
        std::cout << "\n\n";

      }

    }

  }

}

