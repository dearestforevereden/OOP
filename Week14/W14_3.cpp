#include <iostream>
#include <chrono>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std::chrono_literals;

// file_time_type을 std::time_t로 변환하는 함수
std::time_t to_time_t(fs::file_time_type ftime) {
    auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
    );
    return std::chrono::system_clock::to_time_t(sctp);
}

int main(){
    // 현재 작업 디렉토리에 rainer.txt 파일의 경로를 설정
    fs::path path = fs::current_path() / "rainer.txt";
    // rainer.txt 파일을 생성
    std::ofstream(path.c_str()); 
    // rainer.txt 파일의 마지막 수정 시간을 가져옴
    auto ftime = fs::last_write_time(path);
 
    // 파일의 마지막 수정 시간을 time_t 형식으로 변환
    std::time_t cftime = to_time_t(ftime);
    // 서버의 로컬 시간을 출력
    std::cout << "Write time on server (local): " << std::asctime(std::localtime(&cftime));
    // 서버의 GMT 시간을 출력
    std::cout << "Write time on server (GMT): " << std::asctime(std::gmtime(&cftime)) << std::endl;
 
    // 파일의 마지막 수정 시간을 2시간 후로 변경
    fs::last_write_time(path, ftime + 2h);
    // 수정된 파일의 마지막 수정 시간을 다시 가져옴
    ftime = fs::last_write_time(path); 
 
    // 수정된 시간을 time_t 형식으로 변환
    cftime = to_time_t(ftime);
    // 클라이언트의 로컬 시간을 출력
    std::cout << "Local time on client (local): " << std::asctime(std::localtime(&cftime)) << std::endl;
    
    // rainer.txt 파일을 삭제
    fs::remove(path);
}

