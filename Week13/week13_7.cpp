#include <regex>
#include <iostream>
#include <string>
#include <vector>

int main(){

  std::cout << std::endl;

  // 몇 권의 책
  std::string text{"Pete Becker, The C++ Standard Library Extensions, 2006:Nicolai Josuttis, The C++ Standard Library, 1999:Andrei Alexandrescu, Modern C++ Design, 2001"};

  // 책을 위한 정규 표현식
  std::regex regBook(R"((\w+)\s(\w+), ([\w\s\+]*), (\d{4}))");

  // 텍스트에서 모든 책 가져오기
  std::sregex_token_iterator bookItBegin(text.begin(), text.end(), regBook);
  const std::sregex_token_iterator bookItEnd;

  std::cout << "##### std::match_results ######" << "\n\n";
  while ( bookItBegin != bookItEnd){
    std::cout << *bookItBegin++ << std::endl;
  }

  std::cout << "\n\n" << "##### last name,  date of publication ######" << "\n\n";

  // 각 항목의 마지막 이름과 발행일 가져오기
  std::sregex_token_iterator bookItNameIssueBegin(text.begin(), text.end(), regBook, {{2, 4}});
  const std::sregex_token_iterator bookItNameIssueEnd;
  while ( bookItNameIssueBegin != bookItNameIssueEnd){
      std::cout << *bookItNameIssueBegin++ << ", ";
      std::cout << *bookItNameIssueBegin++ << std::endl;
  }

  // 책을 위한 정규 표현식, 부정적 검색 사용
  std::regex regBookNeg(":");

  std::cout << "\n\n" << "##### get each entry, using negativ search  ######" << "\n\n";

  // ":"만 정규 표현식으로 사용하여 모든 항목 가져오기
  std::sregex_token_iterator bookItNegBegin(text.begin(), text.end(), regBookNeg, -1);
  const std::sregex_token_iterator bookItNegEnd;
   while ( bookItNegBegin != bookItNegEnd){
       std::cout << *bookItNegBegin++ << std::endl;
   }

  std::cout << std::endl;

}

