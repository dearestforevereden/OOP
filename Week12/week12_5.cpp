#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// 파일에서 데이터를 읽어와 벡터로 반환하는 함수
std::vector<std::string> readFromFile(const char* fileName){

  // 파일 열기
  std::ifstream file(fileName);

  // 파일 열기에 실패한 경우
  if ( !file ){
    std::cerr << "Could not open the file " << fileName << ".";
    exit(EXIT_FAILURE);
  }

  std::vector<std::string> lines; // 데이터를 저장할 벡터
  std::string line; // 한 줄씩 읽어올 문자열
  while ( getline(file , line) ) lines.push_back(line); // 한 줄씩 읽어서 벡터에 저장

  return lines; // 읽은 데이터가 담긴 벡터 반환
}

int main(){
  
  std::cout << std::endl;
  
  std::string fileName;
  std::cout << "Your filename: "; // << 는 출력 스트림에 글을 쓴다. >> 는 입력 스트림으로부터 스트링을 읽는다.
  std::cin >> fileName; // 사용자로부터 파일 이름 입력 받기

  std::vector<std::string> lines=readFromFile(fileName.c_str()); // 파일에서 데이터 읽어오기
  
  int num{0};
  // 읽어온 데이터 출력
  for ( auto line: lines ) std::cout << ++num << ": " <<  line <<  std::endl;

  std::cout << std::endl;

}

