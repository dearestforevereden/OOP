#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main(){

  std::cout << std::endl;

  // 숫자를 나타내는 정규 표현식 (지수는 제외)
  std::string numberRegEx(R"([-+]?([0-9]*\.[0-9]+|[0-9]+))");

  // 정규 표현식 객체
  std::regex rgx(numberRegEx);

  // const char* 사용
  const char* numChar{"2011"};
  if (std::regex_match(numChar, rgx)){
    std::cout << numChar << " is a number." << std::endl;
  }

  // std::string 사용
  const std::string numStr{"3.14159265359"};
  if (std::regex_match(numStr, rgx)){
    std::cout << numStr << " is a number." << std::endl;
  }

  // bidirectional iterator 사용
  const std::vector<char> numVec{{'-', '2', '.', '7', '1', '8', '2', '8', '1', '8', '2', '8'}};
  if (std::regex_match(numVec.begin(), numVec.end(), rgx)){
    for (auto c: numVec){ std::cout << c ;};
    std::cout << " is a number." << std::endl;
  }

  std::cout << std::endl;

}

