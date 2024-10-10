#include <regex>
#include <iomanip>
#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::string future{"Future"};
  int len = sizeof(future);

  const std::string unofficial{"unofficial, C++0x"};
  const std::string official{"official, C++11"};

  // 정규 표현식을 정의합니다.
  std::regex regValues{"(.*), (.*)"};

  // 표준 텍스트 템플릿을 정의합니다.
  std::string standardText{"The $1 name of the new C++ standard is $2."};

  // std::regex_replace를 사용하여 대체된 문자열을 생성합니다.
  std::string textNow = std::regex_replace(unofficial, regValues, standardText);
  std::cout << std::setw(len) << std::left << "Now: " << textNow << std::endl;

  // std::match_results를 사용하여 대체된 문자열을 생성합니다.
  std::smatch smatch;
  if (std::regex_match(official, smatch, regValues)){
    std::string textFuture = smatch.format(standardText);
    std::cout << std::setw(len) << std::left << "Future: " << textFuture << std::endl;
  }

  std::cout << std::endl;
}

