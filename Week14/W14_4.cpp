#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(){
    
    fs::space_info root = fs::space("/");  // 루트 디렉토리의 공간 정보를 가져옴
    fs::space_info usr = fs::space("/usr"); // /usr 디렉토리의 공간 정보를 가져옴
 
    std::cout << "        Capacity       Free      Available\n"
              << "/    " << root.capacity << "   "  // 루트 디렉토리의 총 용량
              << root.free << "   " << root.available << "\n"  // 루트 디렉토리의 여유 공간과 사용 가능한 공간
              << "usr  "  << usr.capacity << "   "  // /usr 디렉토리의 총 용량
              << usr.free <<  "   " << usr.available;  // /usr 디렉토리의 여유 공간과 사용 가능한 공간
              
    // 결괏값 예시 :
    //        Capacity       Free      Available
    // /    500107862016   200215076864   200215076864
    // usr  500107862016   200215076864   200215076864
    // Capacity는 파일 시스템의 전체 용량이고, Free는 빈 공간, Available은 일반 프로세스가 사용할 수 있는 여유 공간(free가 가리키는 공간보다 작거나 같다)
}

