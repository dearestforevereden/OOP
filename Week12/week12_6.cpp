#include <iostream>
#include <string>

int main() {

  std::string str;

  // find 함수는 문자열에서 특정 문자열 또는 문자의 위치를 찾습니다.
  // 만약 해당 문자열 또는 문자가 존재하지 않으면 std::string::npos를 반환합니다.
  auto idx= str.find("no");
  if (idx == std::string::npos) std::cout << "not found";  // not found

  str= "dkeu84kf8k48kdj39kdj74945du942";
  std::string str2{"84"};
  std::cout << std:: endl;

  // find 함수는 주어진 문자열 또는 문자의 첫 번째 등장 위치를 반환합니다.
  std::cout << str.find('8');                              // 4
  std::cout << std:: endl; 
  std::cout << str.rfind('8');                             // 11
  std::cout << std:: endl;
  std::cout << str.find('8', 10);                          // 11  8을 10번째 인덱스부터 찾아라
  std::cout << std:: endl;  
  std::cout << str.find(str2);                             // 4
  std::cout << std:: endl;  
  std::cout << str.rfind(str2);                            // 4
  std::cout << std:: endl;
  std::cout << str.find(str2, 10);                         // 18446744073709551615 (std::string::npos)

  str2="0123456789";

  // find_first_of 함수는 문자열에서 특정 문자 집합 중에서 첫 번째로 등장하는 문자의 위치를 반환합니다.
  std::cout << str.find_first_of("678");                   // 4
  std::cout << std:: endl;
  std::cout << str.find_last_of("678");                    // 20
  std::cout << std:: endl;
  std::cout << str.find_first_of("678", 10);               // 11
  std::cout << std:: endl;
  std::cout << str.find_first_of(str2);                    // 4
  std::cout << std:: endl;
  std::cout << str.find_last_of(str2);                     // 29
  std::cout << std:: endl;
  std::cout << str.find_first_of(str2, 10);                // 10
  std::cout << std:: endl;
  std::cout << str.find_first_not_of("678");               // 0
  std::cout << std:: endl;
  std::cout << str.find_last_not_of("678");                // 29
  std::cout << std:: endl;
  std::cout << str.find_first_not_of("678", 10);           // 10
  std::cout << std:: endl;
  std::cout << str.find_first_not_of(str2);                // 0
  std::cout << std:: endl;
  std::cout << str.find_last_not_of(str2);                 // 26
  std::cout << std:: endl;
  std::cout << str.find_first_not_of(str2, 10);            // 12
}

