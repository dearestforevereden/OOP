#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
namespace fs = std::filesystem; // 이걸 다 쓰는 대신 fs로 짧게 줄여씀 
 
int main(){

    std::cout << "Current path: " << fs::current_path() << std::endl;
    // 현재 디렉토리 알아내기

    std::string dir= "sandbox/a/b";
    fs::create_directories(dir);
    // 샌드박스 -> a-> b 디렉토리를 만들기

    std::ofstream("sandbox/file1.txt"); 
    // ouputstream생성. sandbox에 file1.txt 만들기 
    fs::path symPath= fs::current_path() /=  "sandbox"; 
    // current_path()에 /=로 sandbox를 갖다붙힘
    symPath /= "syma";
    fs::create_symlink("a", "symPath");
    // a 디렉토리에 a를 가리키는 심볼릭링크 symPath을 만든다.
    
    std::cout << std::boolalpha;
    std::cout << "fs::is_directory(dir): " << fs::is_directory(dir) << std::endl;
    std::cout << "fs::exists(symPath): "  << fs::exists(symPath) << std::endl;
    std::cout << "fs::symlink(symPath): " << fs::is_symlink(symPath) << std::endl;
    // 만든 게 진짜 디렉토리인지, symPath가 존재하는지, 심볼릭 링크인지 출력

    for(auto& p: fs::recursive_directory_iterator("sandbox"))
        std::cout << p << std::endl;
    fs::remove_all("sandbox");
    
    // sandbox 안에 있는 것들을 반복하면서 뭐가 있는지를 보는 코드.
}
