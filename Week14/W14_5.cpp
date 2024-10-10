#include <atomic>
#include <iostream>
#include <thread>

std::atomic_int x; // std::atomic_int는 정수형 변수를 원자적으로 처리하도록 함
std::atomic_int y; // 즉, 동시에 여러 스레드가 접근하더라도 문제가 발생하지 않도록 보장함
int r1; // 일반 정수형 변수로, 원자적이지 않음
int r2;

void writeX(){
  x.store(1); // x를 1로 설정 (store는 원자적으로 값을 설정함)
  r1 = y.load(); // y의 값을 원자적으로 읽어와 r1에 저장 (load는 원자적으로 값을 읽어옴)
}

void writeY(){
  y.store(1); // y를 1로 설정 (store는 원자적으로 값을 설정함)
  r2 = x.load(); // x의 값을 원자적으로 읽어와 r2에 저장 (load는 원자적으로 값을 읽어옴)
}

int main(){

  std::cout << std::endl;

  x = 0; // x를 0으로 초기화
  y = 0; // y를 0으로 초기화
  std::thread a(writeX); // writeX 함수를 실행하는 스레드를 생성
  std::thread b(writeY); // writeY 함수를 실행하는 스레드를 생성
  a.join(); // 스레드 a가 끝날 때까지 대기
  b.join(); // 스레드 b가 끝날 때까지 대기
  std::cout << "(r1, r2)= " << "(" << r1 << ", " << r2 << ")" << std::endl; // r1과 r2의 값을 출력

  std::cout << std::endl;
  // r1과 r2의 출력 값은 스레드의 실행 순서에 따라 달라짐
  // r1과 r2는 각각 0 또는 1이 될 수 있음
  // 예를 들어, r1 = 0, r2 = 1 또는 r1 = 1, r2 = 0 또는 r1 = 1, r2 = 1 등이 될 수 있음

  // 멀티스레딩 (Multithreading)은 하나의 프로세스 내에서 여러 스레드가 동시에 실행되는 것을 의미함
  // 이는 병렬 처리를 통해 성능을 향상시키거나, IO와 같은 블로킹 작업을 비동기적으로 처리할 수 있게 함

  // 원자적 연산 (Atomic operation)은 여러 스레드가 동시에 접근할 때도 일관성을 유지하도록 보장되는 연산을 의미함
  // std::atomic을 사용하면 해당 변수에 대한 모든 연산이 원자적으로 수행되도록 보장함
  // 따라서 데이터 경쟁 (data race) 문제를 피할 수 있음

}

