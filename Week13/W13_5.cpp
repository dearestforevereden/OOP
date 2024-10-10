#include <algorithm> // 알고리즘 헤더 파일
#include <iomanip> // 입력/출력 조작 헤더 파일
#include <iostream> // 표준 입출력 헤더 파일
#include <regex> // 정규 표현식 헤더 파일
#include <string> // 문자열 헤더 파일

int main(){

  std::cout << std::endl; 

  std::string privateAddress = "192.168.178.21"; // IP 주소 문자열
  
  // IP4 주소를 위한 정규 표현식 1자리부터 3자리까지의 숫자가 3번 반복되고 각 숫자 사이에 마침표가 있음을 의미
  std::string ip4RegEx(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");

  // 정규 표현식 객체 생성
  std::regex rgx(ip4RegEx);

  // 검색 결과를 저장하는 객체
  std::smatch smatch;

  // 정확한 일치를 찾음 exact match
  if (std::regex_match(privateAddress, smatch, rgx)){

    // 각 캡처 그룹에 대해 반복문 실행
    for (auto cap : smatch){

      // 캡처 그룹 출력
      std::cout << "capture group: " << cap << std::endl;
      if (cap.matched){

        // 각 문자를 16진수로 출력
        std::cout << "hex: ";
        std::for_each(cap.first, cap.second, [](int v){std::cout << std::showbase << std::hex << v << " ";});
        std::cout << "\n\n";
        // std::showbase: 출력시에 수의 기본 진법을 표시하는 플래그, hex: 16진수로 출력

      }

    }

  }

}

