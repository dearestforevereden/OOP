// stringView.cpp

#include <cassert>
#include <iostream>
#include <string>

#include <string_view>

// 사용자 정의 new 연산자를 통해 메모리 할당 시 할당된 메모리 크기를 출력하는 함수
void* operator new(std::size_t count){
    std::cout << "   " << count << " bytes" << std::endl;
    return malloc(count);
}

// std::string을 인자로 받는 함수
void getString(const std::string& str){} // 참조 연산자(&)를 사용하여 값 자체를 넘김

// std::string_view를 인자로 받는 함수
void getStringView(std::string_view strView){} // std::string_view는 자체적으로 넘김

int main() {

    std::cout << std::endl;

    // std::string을 사용한 문자열 조작
    std::cout << "std::string" << std::endl;

    // 큰 문자열 생성
    std::string large = "0123456789-123456789-123456789-123456789";
    // 부분 문자열 생성
    std::string substr = large.substr(10);
    // large에서 인덱스 10부터 나머지 부분을 새로운 문자열로 생성

    std::cout << std::endl;

    // std::string_view를 사용한 문자열 조작
    std::cout << "std::string_view" << std::endl;

    // std::string_view로 큰 문자열의 부분 문자열 생성
    std::string_view largeStringView{large.c_str(), large.size()};
    // large 문자열의 데이터를 가리키는 포인터와 문자열의 길이를 사용하여 std::string_view를 초기화
    largeStringView.remove_prefix(10);
    // 처음 10개 문자 제거 

    // 부분 문자열이 일치하는지 확인
    assert(substr == largeStringView);

    std::cout << std::endl;

    // getString 함수 호출
    std::cout << "getString" << std::endl;

    // std::string을 인자로 받는 함수 호출
    getString(large);
    // 문자열 리터럴을 인자로 받는 함수 호출
    getString("0123456789-123456789-123456789-123456789");
    // 문자열 배열을 인자로 받는 함수 호출
    const char message []= "0123456789-123456789-123456789-123456789";
    getString(message);
	  // 40 비트만 필요해도 16비트씩 들고오는 게 가장 효율적이므로 48비트 들고옴
	  // 이를 버스 시스템이라고 한다.

    std::cout << std::endl;

    // getStringView 함수 호출
    std::cout << "getStringView" << std::endl;

    // std::string_view를 인자로 받는 함수 호출
    getStringView(large);
    // 문자열 리터럴을 인자로 받는 함수 호출
    getStringView("0123456789-123456789-123456789-123456789");
    // 문자열 배열을 인자로 받는 함수 호출
    getStringView(message);

    std::cout << std::endl;

}
// 결괏값으로 보아 알 수 있는 점: string_view는 메모리가 할당되지 않는다
// std::string  48 bytes 32 bytes getString 48 bytes 48 bytes
// std::string_view getStringView

