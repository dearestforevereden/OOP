#include <regex> // 정규 표현식 사용을 위한 헤더 파일
#include <iomanip> // 출력 형식을 지정하기 위한 헤더 파일
#include <iostream> // 표준 입출력을 위한 헤더 파일
#include <string> // 문자열을 다루기 위한 헤더 파일

// 정규 표현식과 텍스트를 입력으로 받아 캡처 그룹을 보여주는 함수
void showCaptureGroups(const std::string& regEx, const std::string& text){

  // 정규 표현식을 저장하는 객체 생성
  std::regex rgx(regEx);

  // 일치하는 결과를 저장하는 객체 생성
  std::smatch smatch;

  // 정규 표현식에 대한 일치 여부 확인
  if (std::regex_search(text, smatch, rgx)){
    // 캡처 그룹을 출력
    std::cout << std::setw(14) << regEx << std::setw(12) << text 
              << std::setw(12) << smatch[0] << std::setw(10) << smatch[1] 
              << std::setw(10) << smatch[2] << std::setw(10) << smatch[3] 
              << std::setw(10) << smatch[4] << std::endl;
  }
  
  // std::setw()는 출력 폭(너비)를 지정.
  // 예를 들면 std::setw(12)는 smatch[0]의 출력 폭을 12칸으로 설정.

}

// 메인 함수
int main(){

  std::cout << std::endl;

  // 출력 형식 지정
  std::cout << std::setw(14) << "reg Expr" << std::setw(12) << "text" 
            << std::setw(12) << "smatch[0]" << std::setw(10) << "smatch[1]" 
            << std::setw(10) << "smatch[2]" << std::setw(10) << "smatch[3]" 
            << std::setw(10) << "smatch[4]" << std::endl;

  // 각각의 정규 표현식에 대해 캡처 그룹 출력
  showCaptureGroups("abc+", "abccccc");
  // "ab" 다음에 하나 이상의 "c"
  showCaptureGroups("(a+)(b+)(c+)", "aaabccc");
  // "a", "b", "c" 각각 한 번 이상 반복
  showCaptureGroups("((a+)(b+)(c+))", "aaabccc");
  // 이전과 같은 패턴이지만, 전체 패턴에 대해서도 캡처 그룹을 설정
  showCaptureGroups("(ab)(abc)+", "ababcabc");
  //  "ab" 다음에 "abc"가 한 번 이상 반복

  std::cout << std::endl;
  
}
//캡쳐 그룹: 소괄호로 둘러쌓인 부분의 패턴, 정규표현식 분석을 도와주고 
// 일치하는 텍스트의 일부를 추출하거나 그룹화하는 데 사용된다.

