#include <iostream>
#include <regex>
#include <string>

int main(){

  std::cout << std::endl;

  // 시간을 나타내는 정규 표현식 홀더
  std::regex crgx("([01]?[0-9]|2[0-3]):[0-5][0-9]");

  // const char* 사용 예시
  std::cout << "const char*" << std::endl;
  std::cmatch cmatch;

  const char* ctime{"Now it is 23:10."};

  if (std::regex_search(ctime, cmatch, crgx)){
     std::cout << ctime << std::endl;
     std::cout << "Time: " << cmatch[0] << std::endl;
  }

  std::cout << std::endl;

  // std::string 사용 예시
  std::cout << "std::string" << std::endl;
  std::smatch smatch;

  std::string stime{"Now it is 23:25."};
  if (std::regex_search(stime, smatch, crgx)){
    std::cout << stime << std::endl;
    std::cout << "Time: " << smatch[0] << std::endl;
  }

  std::cout << std::endl;

  // 시간을 나타내는 정규 표현식 홀더 (wide string용)
  std::wregex wrgx(L"([01]?[0-9]|2[0-3]):[0-5][0-9]");

  // const wchar_t* 사용 예시
  std::cout << "const wchar_t* " << std::endl;
  std::wcmatch wcmatch;

  const wchar_t* wctime{L"Now it is 23:47."};

  if (std::regex_search(wctime, wcmatch, wrgx)){
       std::wcout << wctime << std::endl;
       std::wcout << "Time: " << wcmatch[0] << std::endl;
  }

  std::cout << std::endl;

  // std::wstring 사용 예시
  std::cout << "std::wstring" << std::endl;
  std::wsmatch wsmatch;

  std::wstring wstime{L"Now it is 00:03."};

  if (std::regex_search(wstime, wsmatch, wrgx)){
    std::wcout << wstime << std::endl;
    std::wcout << "Time: " << wsmatch[0] << std::endl;
  }

  std::cout << std::endl;

}

