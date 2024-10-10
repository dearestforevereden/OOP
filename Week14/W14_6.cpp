#include <iostream>
#include <thread>

void helloFunction(){
  std::cout << "Hello C++20 from a function." << std::endl; // 함수에서 출력
}

class HelloFunctionObject  {
  public:
    void operator()() const {
      std::cout << "Hello C++20 from a function object." << std::endl; // 함수 객체에서 출력
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
  std::thread t3([]{std::cout << "Hello C++20 from lambda function." << std::endl;});

  // t1, t2, t3가 종료될 때까지 대기
  t1.join();
  t2.join();
  t3.join();

  std::cout << std::endl;

}

// 이 코드는 세 가지 다른 방법으로 스레드를 생성하고 실행합니다.
// 1. helloFunction 함수를 실행하는 스레드 t1을 생성합니다.
// 2. HelloFunctionObject 객체를 실행하는 스레드 t2를 생성합니다.
// 3. 람다 함수를 실행하는 스레드 t3을 생성합니다.
// 각 스레드는 메시지를 출력합니다.

// 예상되는 결괏값은 다음과 같습니다:
// (스레드의 실행 순서는 비결정적이므로, 출력 순서는 매번 다를 수 있습니다)

// Hello C++11 from a function.
// Hello C++11 from a function object.
// Hello C++11 from lambda function.

// join() 함수는 스레드가 완료될 때까지 호출한 스레드를 대기 상태로 만드는 역할을 합니다. 
// 이는 멀티스레딩 프로그램에서 중요한 동기화 기법으로, 주 스레드가 다른 스레드들이 완료되기 전에 프로그램이 종료되는 것을 방지하는 데 사용됩니다.

