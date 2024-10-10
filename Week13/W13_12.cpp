#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// 템플릿 함수: 문자열을 주어진 타입 T로 변환
template <class T>
T StringTo(const std::string& source) {
    std::istringstream iss(source);  // source 문자열로 입력 스트림 생성
    T ret;  // 변환된 값을 저장할 변수
    iss >> ret;  // 스트림에서 값을 읽어서 ret에 저장
    return ret;  // 변환된 값 반환
}

// 템플릿 함수: 주어진 타입 T의 값을 문자열로 변환
template <class T>
std::string ToString(const T& n) {
    std::ostringstream tmp;  // 출력을 문자열로 변환하기 위한 출력 스트림 생성
    tmp << n;  // 스트림에 값을 출력
    return tmp.str();  // 스트림의 내용을 문자열로 반환
}

int main() {

    std::cout << std::endl;

    // 정수 5를 문자열로 출력
    std::cout << "5 = " << std::string("5") << std::endl;

    // 문자열 "5"를 정수로 변환하여 출력
    std::cout << "5 = " << StringTo<int>("5") << std::endl;

    // 문자열 "5"를 정수로 변환한 값에 6을 더한 결과를 출력
    std::cout << "5 + 6 = " << StringTo<int>("5") + 6 << std::endl;

    // 문자열 "5"를 정수로 변환한 값에 6을 더한 결과를 문자열로 변환하여 출력
    std::string erg(ToString(StringTo<int>("5") + 6));
    std::cout << "5 + 6 = " << erg << std::endl;

    // 문자열 "5e10"을 실수로 변환하여 고정 소수점 형식으로 출력
    std::cout << "5e10: " << std::fixed << StringTo<double>("5e10") << std::endl;

    std::cout << std::endl;

}

