// string_view.cpp

#include <iostream>
#include <string>
#include <string_view>

int main(){
    
  // 공백이 있는 문자열 생성
  std::string str = "   A lot of space";
  
  // std::string_view를 통해 str을 참조
  std::string_view strView = str;
  
  // 앞쪽 공백을 제거하기 위해 remove_prefix 사용
  strView.remove_prefix(std::min(strView.find_first_not_of(" "), strView.size()));
  
  // 원래 문자열과 공백이 제거된 문자열 뷰를 출력
  std::cout << "str      : " << str << std::endl 
            << "strView  : " << strView << std::endl;
                 
  std::cout << std::endl;

  // 공백과 널 문자가 포함된 배열 생성
  char arr[] = {'A', ' ', 'l', 'o', 't', ' ', 'o', 'f', ' ', 's', 'p', 'a', 'c', 'e', '\0',  '\0',  '\0'};
  
  // 배열을 참조하는 std::string_view 생성
  std::string_view strView2(arr, sizeof arr);
  
  // 널 문자 위치를 찾아서 그 이후를 제거
  auto trimPos = strView2.find('\0');
  if(trimPos != strView2.npos) strView2.remove_suffix(strView2.size() - trimPos);
  
  // 배열과 널 문자를 제거한 문자열 뷰를 출력
  std::cout << "arr     : " << arr << ", size=" << sizeof arr << std::endl
            << "strView2: " << strView2 << ", size=" << strView2.size() << std::endl;
              
}

