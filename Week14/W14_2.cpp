#include <fstream>
#include <bitset>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
 
void printPerms(fs::perms perm){
  std::cout << ((perm & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
            << ((perm & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
            << ((perm & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
            << ((perm & fs::perms::group_read) != fs::perms::none ? "r" : "-")
            << ((perm & fs::perms::group_write) != fs::perms::none ? "w" : "-")
            << ((perm & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
            << ((perm & fs::perms::others_read) != fs::perms::none ? "r" : "-")
            << ((perm & fs::perms::others_write) != fs::perms::none ? "w" : "-")
            << ((perm & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
            << std::endl;
}


int main(){
  
    std::ofstream("rainer.txt");
    // rainer.txt 파일을 생성

    std::cout << "Initial file permissions for a file: ";
    printPerms(fs::status("rainer.txt").permissions());
    std::cout << std::endl;
    // 만든 rainer.txt 파일의 첫 퍼미션을 출력하라
 
    fs::permissions("rainer.txt",
                   fs::perms::owner_all | fs::perms::group_all, 
                   fs::perm_options::add);
    std::cout << "Adding all bits to owner and group:  ";
    printPerms(fs::status("rainer.txt").permissions());
    std::cout << std::endl;
    // 기존 퍼미션에 오너, 그룹 퍼미션을 주고난 후의 상태를 출력
    
    fs::permissions("rainer.txt",
                   fs::perms::owner_write | fs::perms::group_write | fs::perms::others_write,
                   fs::perm_options::remove);
    std::cout << "Removing the write bits for all:     ";
    printPerms(fs::status("rainer.txt").permissions());
    std::cout << std::endl;
    // 오너, 그룹, 다른 사용자의 쓰기 퍼미션을 제거한 후의 상태를 출력
 
    fs::remove("rainer.txt");
    // rainer.txt 파일을 삭제
    
}

