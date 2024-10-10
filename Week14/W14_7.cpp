
#include <iostream>
#include <thread>

void helloFunction(){
  std::cout << "Hello C++11 from a function." << std::endl; // 함수에서 출력
}

class HelloFunctionObject  {
  public:
    void operator()() const {
      std::cout << "Hello C++11 from a function object." << std::endl; // 함수 객체에서 출력
    }
};

int main(){

  std::cout << std::endl;

  // helloFunction을 실행하는 스레드 생성
  std::thread t1(helloFunction);

  // HelloFunctionObject를 실행하는 스레드 생성
  HelloFunctionObject helloFunctionObject;
  std::thread t2(helloFunctionObject);

  // 람다 함수를 실행하는 스레드 생성
  std::thread t3([]{std::cout << "Hello C++11 from lambda function." << std::endl;});

  // t1, t2, t3가 메인 스레드 종료 전에 마치도록 보장한다.
  t1.join(); // t1 스레드가 끝날 때까지 메인 스레드 대기 (t1의 작업이 완료되면 다음 코드로 진행)
  t2.detach(); // t2 스레드를 분리 (t2는 백그라운드에서 실행되고, main 스레드와 독립적으로 실행됨, main 스레드는 t2가 끝날 때까지 안기다림)
  t3.join(); // t3 스레드가 끝날 때까지 대기 
  

  std::cout << std::endl;

}
// (스레드의 실행 순서는 비결정적이므로, 출력 순서는 매번 다를 수 있습니다)


// t2 스레드가 분리되어 백그라운드에서 실행되기 때문에 t2의 출력은 main 스레드가 종료된 후에도 출력될 수 있습니다.

