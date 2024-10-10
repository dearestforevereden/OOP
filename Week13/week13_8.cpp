#include <regex>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    // 입력 텍스트
    std::string text{"That's a (to me) amazingly frequent question. It may be the most frequently asked question. Surprisingly, C++0x feels like a new language: The pieces just fit together better than they used to and I find a higher-level style of programming more natural than before and as efficient as ever."};

    // 정규 표현식: \w+는 하나 이상의 문자 또는 숫자를 나타냄
    std::regex wordReg(R"(\w+)");

    // 텍스트에서 모든 단어를 가져옴
    std::sregex_iterator wordItBegin(text.begin(), text.end(), wordReg);
    const std::sregex_iterator wordItEnd;

    // 단어를 저장할 해시 맵
    std::unordered_map<std::string, std::size_t> allWords;

    // 각 단어의 출현 횟수를 계산
    for (; wordItBegin != wordItEnd; ++wordItBegin) {
        ++allWords[wordItBegin->str()];
    }

    // 각 단어와 해당 단어의 출현 횟수를 출력
    for (auto wordIt : allWords) {
        std::cout << "(" << wordIt.first << ":" << wordIt.second << ")";
    }

    std::cout << "\n\n";
}

