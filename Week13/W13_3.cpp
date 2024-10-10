#include <iostream>
#include <regex>
#include <string>

int main(){

  std::cout << std::endl;

  std::string theQuestion="C++ or c++, that's the question.";

  // regular expression for c++
  std::string regExprStr(R"(c\+\+)"); // c++을 그대로 찾으라는 R

  // regular expression object searching for c++
  std::regex rgx(regExprStr);

  // search result holder
  std::smatch smatch;

  std::cout << theQuestion << std::endl;

  // looking for a partial match (case sensitive)
  if (std::regex_search(theQuestion, smatch, rgx)){
  // theQuestion에서 rgx찾으면 그 결과를 smatch에 저장.

    std::cout << std::endl;
    std::cout << "The answer is case sensitive: " << smatch[0] <<  std::endl;

  } // 대소문자 구분하는 정규표현식 rgx 사용 -> c++

  // regular expression object (case insensitive)
  std::regex rgxIn(regExprStr, std::regex_constants::ECMAScript|std::regex_constants::icase);

  // looking for a partial match (case sensitive)
  if (std::regex_search(theQuestion, smatch, rgxIn)){

    std::cout << std::endl;
    std::cout << "The answer is case insensitive: " << smatch[0] << std::endl;

  } // 대소문자 구분 안하는 정규표현식 rgxIn 사용 -> C++

  std::cout << std::endl;

}
