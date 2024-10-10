#include <iostream>
#include <regex>
#include <string>

int main(){

  std::cout << std::endl;

  // 문자열 정의
  std::string theQuestion="C++ or c++, that's the question.";

  // 정규 표현식 문자열 (c++)
  std::string regExprStr(R"(c\+\+)");

  // 정규 표현식 객체 생성
  std::regex rgx(regExprStr);

  // 검색 결과를 담을 객체
  std::smatch smatch;

  std::cout << theQuestion << std::endl;

  // 부분 일치를 찾기 위해 정규 표현식 검색 (대소문자 구분)
  if (std::regex_search(theQuestion, smatch, rgx)){

    std::cout << std::endl;
    // 검색된 부분 문자열 출력 (대소문자 구분)
    std::cout << "The answer is case sensitive: " << smatch[0] <<  std::endl;

  }

  // 정규 표현식 객체 생성 (대소문자 구분 없음)
  std::regex rgxIn(regExprStr, std::regex_constants::ECMAScript|std::regex_constants::icase);

  // 부분 일치를 찾기 위해 정규 표현식 검색 (대소문자 구분 없음)
  if (std::regex_search(theQuestion, smatch, rgxIn)){

    std::cout << std::endl;
    // 검색된 부분 문자열 출력 (대소문자 구분 없음)
    std::cout << "The answer is case insensitive: " << smatch[0] << std::endl;

  }

  std::cout << std::endl;

}

