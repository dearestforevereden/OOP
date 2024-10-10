#include <algorithm>  // 표준 알고리즘 사용을 위해
#include <cctype>     // std::toupper 사용을 위해
#include <deque>
#include <iostream>   // 표준 입출력 스트림 사용을 위해
#include <list>       // std::list 사용을 위해
#include <set>        // std::set 사용을 위해

// 문자가 모음인지 확인하는 함수
bool isVowel(char c){
    // 모음을 포함한 문자열 정의
    std::string myVowels{"aeiouäöü"};
    // 모음 집합 생성 (빠른 조회를 위해)
    std::set<char> vowels(myVowels.begin(), myVowels.end());
    // 문자가 모음 집합에 있는지 확인
    auto it = vowels.find(c);
    if (it != vowels.end()) return true;
    return false;
}

int main() {
    std::cout << std::endl;

    // 문자 리스트 초기화
    std::list<char> myChars{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    // 문자 배열 초기화
    int chars[] = {'A', 'B', 'C'};

    // std::find를 사용하여 myChars에서 'g'의 첫 번째 위치를 찾음
    std::cout << "*std::find(myChars.begin(), myChars.end(), 'g'): " << *std::find(myChars.begin(), myChars.end(), 'g') << std::endl;
    
    // std::find_if를 사용하여 모음을 찾음
    std::cout << "std::find_if(myChars.begin(), myChars.end(), isVowel): " << *std::find_if(myChars.begin(), myChars.end(), isVowel) << std::endl;
    
    // std::find_if_not를 사용하여 모음이 아닌 문자를 찾음
    std::cout << "std::find_if_not(myChars.begin(), myChars.end(), isVowel): " << *std::find_if_not(myChars.begin(), myChars.end(), isVowel) << std::endl;
    
    // std::find_first_of를 사용하여 myChars에서 chars 배열의 첫 번째 공통 문자를 찾음
    auto iter = std::find_first_of(myChars.begin(), myChars.end(), chars, chars + 3);
    if (iter != myChars.end()) std::cout << "공통 문자: " << *iter << std::endl;
    else std::cout << "myChars에 A, B, C 중 아무것도 없음." << std::endl;
    
    // 대소문자 구분 없이 std::find_first_of 사용
    auto iter2 = std::find_first_of(myChars.begin(), myChars.end(), chars, chars + 3, [](char a, char b){ return std::toupper(a) == std::toupper(b); });
    if (iter2 != myChars.end()) std::cout << "공통 문자: " << *iter2 << std::endl;
    else std::cout << "myChars에 A, B, C 중 아무것도 없음." << std::endl;
    
    // std::adjacent_find를 사용하여 인접한 동일 문자를 찾음
    auto iter3 = std::adjacent_find(myChars.begin(), myChars.end());
    if (iter3 != myChars.end()) std::cout << "인접한 동일 문자: " << *iter3 << std::endl;
    else std::cout << "인접한 동일 문자가 없음." << std::endl;
    
    // std::adjacent_find를 사용하여 인접한 모음 또는 자음을 찾음
    auto iter4 = std::adjacent_find(myChars.begin(), myChars.end(), [](char a, char b){ return isVowel(a) == isVowel(b); });
    if (iter4 != myChars.end()) std::cout << "인접한 모음 또는 자음: " << *iter4 << std::endl;
    else std::cout << "인접한 동일 문자가 없음." << std::endl;

    std::cout << std::endl;
}

