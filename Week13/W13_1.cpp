// string_view.cpp

#include <iostream>
#include <string>
#include <string_view>

int main(){
    
  std::string str = "   A lot of space";
  std::string_view strView = str;
  strView.remove_prefix(std::min(strView.find_first_not_of(" "), strView.size())); 
  // 공백이 아닌 첫번째, 즉 A의 위치, 전체 크기 중 작은 것: 당연히 A의 위치 앞을 다 지워라.
  // 원래 스트링은 내용이 안 바뀌고 스트링뷰에서 앞 공백을 지우고 보기만 하는 것.
  std::cout << "str      :  " << str << std::endl 
            << "strView  : " << strView << std::endl;
                 
  std::cout << std::endl;

  char arr[] = {'A', ' ', 'l', 'o', 't', ' ', 'o', 'f', ' ', 's', 'p', 'a', 'c', 'e', '\0',  '\0',  '\0'};

// char 배열을 사용하여 std::string_view를 생성합니다.
std::string_view strView2(arr, sizeof arr);

// '\0' 문자의 위치를 찾습니다.
auto trimPos = strView2.find('\0');

// '\0' 문자가 발견되었을 경우, 해당 위치 이후의 문자들을 제거합니다.
if (trimPos != strView2.npos)
    strView2.remove_suffix(strView2.size() - trimPos);

// 결과를 출력합니다.
std::cout << "arr     : " << arr << ", size=" << sizeof arr << std::endl
          << "strView2: " << strView2 << ", size=" << strView2.size() << std::endl;

}
