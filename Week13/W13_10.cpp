//13_10

#include <regex> // 정규 표현식 사용을 위한 헤더 파일

#include <iostream> // 표준 입출력 헤더 파일
#include <string> // 문자열 헤더 파일
#include <vector> // 벡터 헤더 파일

int main(){

  std::cout << std::endl; // 개행

  // 몇 권의 책 정보를 담은 문자열
  std::string text{"Pete Becker, The C++ Standard Library Extensions, 2006:Nicolai Josuttis, The C++ Standard Library, 1999:Andrei Alexandrescu, Modern C++ Design, 2001"};

  // 책 정보를 위한 정규 표현식
  std::regex regBook(R"((\w+)\s(\w+), ([\w\s\+]*), (\d{4}))");
  
  // 정규 표현식을 R"()" 구문을 사용하여 raw string literal로 표기했습니다.
  // 이 구문은 백슬래시(\)를 이스케이프 문자로 처리하지 않고 있는 것을 의미합니다.
  // (\w+)\s(\w+): 책 제목과 저자를 추출하는 그룹입니다. \w는 단어 문자를 의미하며, \s는 공백 문자를 의미합니다.
  // ([\w\s\+]*)\s: 책의 부제목을 추출하는 그룹입니다. [\w\s\+]*는 단어 문자, 공백, 플러스 기호를 포함한 문자열을 의미합니다.
  // (\d{4}): 출판 연도를 추출하는 그룹입니다. \d는 숫자를 의미하며, {4}는 앞의 패턴이 4번 반복되는 것을 의미합니다.

  // 텍스트에서 모든 책 정보 추출
  std::sregex_token_iterator bookItBegin(text.begin(), text.end(), regBook);
  const std::sregex_token_iterator bookItEnd;

  std::cout << "##### std::match_results ######" << "\n\n";

  // 모든 책 정보 출력
  while ( bookItBegin != bookItEnd){
    std::cout << *bookItBegin++ << std::endl;
  }

  std::cout << "\n\n" << "##### last name,  date of publication ######" << "\n\n";

  // 각 책의 저자와 출판년도(2,4번째 캡쳐그룹)만 추출 
  std::sregex_token_iterator bookItNameIssueBegin(text.begin(), text.end(), regBook, {{2, 4}});
  const std::sregex_token_iterator bookItNameIssueEnd;

  // 각 책의 저자와 출판년도 출력
  while ( bookItNameIssueBegin != bookItNameIssueEnd){
      std::cout << *bookItNameIssueBegin++ << ", ";
      std::cout << *bookItNameIssueBegin++ << std::endl;
  }

  // 책 정보를 ":"을 기준으로 추출하는 정규 표현식
  std::regex regBookNeg(":");

  std::cout << "\n\n" << "##### get each entry, using negativ search  ######" << "\n\n";

  // ":"을 기준으로 모든 항목 추출
  std::sregex_token_iterator bookItNegBegin(text.begin(), text.end(), regBookNeg, -1);
  // -1은 최대 분할 횟수를 가능한 모든 위치에서 분할하도록 지정.
  // 따라서 이 코드에서 `-1`을 사용하면 콜론(`:`)으로 구분된 모든 항목을 추출.
  const std::sregex_token_iterator bookItNegEnd;

  // 모든 항목 출력
  while ( bookItNegBegin != bookItNegEnd){
       std::cout << *bookItNegBegin++ << std::endl;
   }

  std::cout << std::endl; // 개행

}

