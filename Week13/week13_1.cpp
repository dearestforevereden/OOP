#include <regex>
#include <iomanip>
#include <iostream>
#include <string>

// 캡처 그룹을 출력하는 함수
void showCaptureGroups(const std::string& regEx, const std::string& text){

  // 정규 표현식 객체
  std::regex rgx(regEx);

  // 검색 결과를 담을 객체
  std::smatch smatch;

  // 정규 표현식을 사용하여 텍스트에서 검색
  if (std::regex_search(text, smatch, rgx)){
    // 검색 결과 및 캡처 그룹 출력
    std::cout << std::setw(14) << regEx 
              << std::setw(12) << text 
              << std::setw(12) << smatch[0]  
              << std::setw(10) << smatch[1] 
              << std::setw(10) << smatch[2] 
              << std::setw(10) << smatch[3] 
              << std::setw(10) << smatch[4] 
              << std::endl;
  }
}

int main(){

  std::cout << std::endl;

  // 출력 헤더
  std::cout << std::setw(14) << "reg Expr" 
            << std::setw(12) << "text" 
            << std::setw(12) << "smatch[0]" 
            << std::setw(10) << "smatch[1]" 
            << std::setw(10) << "smatch[2]" 
            << std::setw(10) << "smatch[3]" 
            << std::setw(10) << "smatch[4]" 
            << std::endl;

  // 각각의 정규 표현식을 사용하여 텍스트에서 캡처 그룹을 출력
  showCaptureGroups("abc+", "abccccc");            // 정규 표현식: abc+ / 텍스트: abccccc / 캡처 그룹: abccccc, c, (빈 값), (빈 값), (빈 값)
  showCaptureGroups("(a+)(b+)(c+)", "aaabccc");    // 정규 표현식: (a+)(b+)(c+) / 텍스트: aaabccc / 캡처 그룹: aaabccc, aaa, b, c, (빈 값)
  showCaptureGroups("((a+)(b+)(c+))", "aaabccc");  // 정규 표현식: ((a+)(b+)(c+)) / 텍스트: aaabccc / 캡처 그룹: aaabccc, aaabccc, aaa, b, c
  showCaptureGroups("(ab)(abc)+", "ababcabc");     // 정규 표현식: (ab)(abc)+ / 텍스트: ababcabc / 캡처 그룹: ababcabc, ab, abc, (빈 값), (빈 값)

  std::cout << std::endl;
  
}

