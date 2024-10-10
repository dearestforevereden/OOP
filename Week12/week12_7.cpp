#include <iostream>
#include <string>

int main(){

  std::cout << std::endl;

  std::cout << "ASSIGN: " << std::endl;

  std::string str{"New String"};
  std::string str2{"Other String"};
  std::cout << "str: " << str << std::endl;
  
  str.assign(str2, 4, std::string::npos); // 'Other String'의 4번째 인덱스부터 끝까지 대입
  std::cout << str << std::endl; // Expected output: "r String"

  str.assign(5, '-'); // '-' 문자를 5번 대입
  std::cout << str << std::endl; // Expected output: "-----"
  std::cout << std::endl;

  std::cout << "DELETE" << std::endl;
  
  str={"0123456789"};
  std::cout << "str: " << str << std::endl;
  str.erase(7, 2); // 인덱스 7부터 2개의 문자를 삭제
  std::cout << str << std::endl; // Expected output: "01234569"
  
  str.erase(str.begin()+2, str.end()-2); // 인덱스 2부터 끝에서 2번째 전까지의 문자를 삭제
  std::cout << str << std::endl; // Expected output: "01"

  str={"0123456789"}; // 'str'를 다시 초기화
  str.erase(str.begin()+2, str.end()); // 인덱스 2부터 끝까지의 문자를 삭제
  std::cout << str << std::endl; // Expected output: "01"
  
  str.pop_back(); // 마지막 문자를 삭제
  std::cout << str << std::endl; // Expected output: "0"
  
  str.erase(); // 문자열을 모두 삭제
  std::cout << str << std::endl; // Expected output: ""
  
  std::cout << "APPEND" << std::endl;
  
  str="01234";
  std::cout << "str: " << str << std::endl;
  
  str+="56"; // "56"을 추가
  std::cout << str << std::endl; // Expected output: "0123456"
  
  str+='7'; // '7'을 추가
  std::cout << str << std::endl; // Expected output: "01234567"
  
  str+={'8', '9'}; // '8'과 '9'를 추가
  std::cout << str << std::endl; // Expected output: "0123456789"
  
  str.append(str); // 자기 자신을 추가
  std::cout << str << std::endl; // Expected output: "01234567890123456789"
  
  str.append(str, 2, 4); // 인덱스 2부터 길이 4의 부분 문자열을 추가
  std::cout << str << std::endl; // Expected output: "012345678901234567892345"
  
  str.append(10, '0'); // '0'을 10번 추가
  std::cout << str << std::endl; // Expected output: "0123456789012345678923450000000000"
  
  str.append(str, 10, 10); // 인덱스 10부터 길이 10의 부분 문자열을 추가
  std::cout << str << std::endl; // Expected output: "01234567890123456789234500000000006789012345"
  
  str.push_back('9'); // '9'를 추가
  std::cout << str << std::endl; // Expected output: "012345678901234567892345000000000067890123459"
  
  std::cout << std::endl;
  
  std::cout << "INSERT" << std::endl;
  str={"345"};
  std::cout << "str: " << str << std::endl;
  
  str.insert(3, "6789"); // 인덱스 3에 "6789"를 삽입
  std::cout << str << std::endl; // Expected output: "3456789"
  
  str.insert(0, "012"); // 인덱스 0에 "012"를 삽입
  std::cout << str << std::endl; // Expected output: "0123456789"
  
  std::cout << std::endl;
  
  std::cout <<  "REPLACE" << std::endl;
  str={"only for testing purpose."};
  std::cout << "str: " << str << std::endl;
  
  str.replace(0, 0, "O"); // 인덱스 0에 "O"를 삽입
  std::cout <<  str << std::endl; // Expected output: "Oonly for testing purpose."
  
  str.replace(0, 5, "Only", 0, 4); // 인덱스 0부터 5까지의 부분을 "Only"로 교체
  std::cout << str << std::endl; // Expected output: "Only for testing purpose."
  
  str.replace(16, 8, ""); // 인덱스 16부터 8개의 문자를 삭제
  std::cout << str << std::endl; // Expected output: "Only for testing"
  
  str.replace(4, 0, 5, 'y'); // 인덱스 4에 'y'를 5번 삽입
  std::cout << str << std::endl; // Expected output: "Onlyyyyyy for testing"
  
  str.replace(str.begin(), str.end(), "Only for testing purpose."); // 전체 문자열을 "Only for testing purpose."로 교체
  std::cout << str << std::endl; // Expected output: "Only for testing purpose."
  
  str.replace(str.begin()+4, str.end()-8, 10, '#'); // 인덱스 4부터 끝에서 8까지의 문자를 '#' 10개로 교체
  std::cout << str << std::endl; // Expected output: "Only##########purpose."
  
  std::cout << std::endl;

}

