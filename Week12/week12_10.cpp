#include <cassert>
#include <iostream>
#include <string>
#include <string_view>

// 메모리 할당 시 몇 바이트를 할당하는지 출력하는 사용자 정의 new 연산자
void* operator new(std::size_t count){
    std::cout << "   " << count << " bytes" << std::endl;
    return malloc(count);
}

// std::string을 인자로 받는 함수
void getString(const std::string& str){}

// std::string_view를 인자로 받는 함수
void getStringView(std::string_view strView){}

int main() {

    std::cout << std::endl;

    std::cout << "std::string" << std::endl;

    // 큰 문자열을 생성하고 그로부터 부분 문자열을 추출
    std::string large = "0123456789-123456789-123456789-123456789";
    std::string substr = large.substr(10);

    std::cout << std::endl;

    std::cout << "std::string_view" << std::endl;

    // large 문자열을 가리키는 std::string_view 생성 후 처음 10자를 제거
    std::string_view largeStringView{large.c_str(), large.size()};
    largeStringView.remove_prefix(10);

    // substr와 largeStringView가 같은지 확인
    assert(substr == largeStringView);

    std::cout << std::endl;

    std::cout << "getString" << std::endl;

    // getString 함수를 호출하여 문자열을 전달
    getString(large);
    getString("0123456789-123456789-123456789-123456789");
    const char message []= "0123456789-123456789-123456789-123456789";
    getString(message);

    std::cout << std::endl;

    std::cout << "getStringView" << std::endl;

    // getStringView 함수를 호출하여 문자열 뷰를 전달
    getStringView(large);
    getStringView("0123456789-123456789-123456789-123456789");
    getStringView(message);

    std::cout << std::endl;

}


