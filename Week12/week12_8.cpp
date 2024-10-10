#include <iostream>
#include <limits>
#include <string>

int main(){

  std::cout << std::endl;
  
  std::cout << "to_string, to_wstring" << std::endl;
  
  // 최대 long long 값의 문자열 변환
  std::string maxLongLongString = std::to_string(std::numeric_limits<long long>::max());
  std::wstring maxLongLongWstring = std::to_wstring(std::numeric_limits<long long>::max());
  
  // 최대 long long 값 출력
  std::cout << std::numeric_limits<long long>::max() << std::endl; // Expected: 9223372036854775807
  std::cout << maxLongLongString << std::endl; // Expected: 9223372036854775807
  std::wcout << maxLongLongWstring << std::endl; // Expected: 9223372036854775807
  
  std::cout << std::endl;
  
  std::cout << "ato* " << std::endl;
  
  // 문자열을 정수로 변환하는 예제
  std::string str("10010101");
  
  std::cout << std::stoi(str) << std::endl; // 기본 10진수로 변환, Expected: 10010101
  std::cout << std::stoi(str, nullptr, 16) << std::endl; // 16진수로 변환, Expected: 268500353
  std::cout << std::stoi(str, nullptr, 8) << std::endl; // 8진수로 변환, Expected: 210457
  std::cout << std::stoi(str, nullptr, 2) << std::endl; // 2진수로 변환, Expected: 149
  
  std::cout << std::endl;
  
  std::size_t idx;
  // 문자열을 실수로 변환하는 예제
  std::cout << std::stod("   3.5 km", &idx) << std::endl; // 공백 제거 후 실수 변환, Expected: 3.5
  std::cout << "Not numeric char at position " << idx << "." << std::endl; //first non numeric 위치 출력, Expected: 5 (km의 k)
  
  std::cout << std::endl;
  
  try{
    // 문자열을 정수로 변환 시도 (예외 발생)
    std::cout << std::stoi("   3.5 km") << std::endl; // 실수 문자열을 정수로 변환 시도 (예외 발생)
    std::cout << std::stoi("   3.5 km", nullptr, 2) << std::endl; // 2진수로 변환 시도 (예외 발생)
    
  }
  catch (const std::exception& e){
    // 예외 메시지 출력
    std::cerr << e.what() << std::endl; // Expected: stoi: no conversion 또는 stoi: invalid stoi argument because it's not int
  }
  
  std::cout << std::endl;

}

