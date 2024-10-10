#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    // 현재 작업 디렉터리 출력
    std::cout << "Current path: " << fs::current_path() << std::endl;

    // 디렉터리 생성
    std::string dir = "sandbox/a/b";
    fs::create_directories(dir);

    // 파일 생성
    std::ofstream("sandbox/file1.txt");

    // 심볼릭 링크 생성
    fs::path symPath = fs::current_path() / "sandbox" / "syma";
    fs::create_symlink("a", symPath);

    // 디렉터리 및 심볼릭 링크 여부 확인
    std::cout << "fs::is_directory(dir): " << fs::is_directory(dir) << std::endl;
    std::cout << "fs::exists(symPath): " << fs::exists(symPath) << std::endl;
    std::cout << "fs::is_symlink(symPath): " << fs::is_symlink(symPath) << std::endl;

    // 재귀적으로 디렉터리 탐색하여 출력
    for (auto& p : fs::recursive_directory_iterator("sandbox"))
        std::cout << p << std::endl;

    // 생성한 디렉터리 및 파일 삭제
    fs::remove_all("sandbox");
}

