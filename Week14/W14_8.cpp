#include <iostream>
#include <thread>

int main(){

  std::cout << std::endl;

  // 하드웨어 스레드의 개수를 출력
  std::cout << "std::thread::hardware_concurrency()= "<< std::thread::hardware_concurrency() << std::endl;

  std::cout << std::endl;

  // 각각의 람다 함수를 실행하는 두 개의 스레드 생성
  std::thread t1([]{std::cout << "hello from t1 with id= " << std::this_thread::get_id() << std::endl;});
  std::thread t2([]{std::cout << "hello from t2 with id= " << std::this_thread::get_id() << std::endl;});

  std::cout << std::endl;

  // t1과 t2의 스레드 ID를 출력
  std::cout << "FROM MAIN: id of t1 " << t1.get_id() << std::endl;
  std::cout << "FROM MAIN: id of t2 " << t2.get_id() << std::endl;

  std::cout << std::endl;

  // t1과 t2의 스레드 ID를 교환
  t1.swap(t2);

  // 스레드 ID 교환 후 t1과 t2의 스레드 ID를 다시 출력
  std::cout << "FROM MAIN: id of t1 " << t1.get_id() << std::endl;
  std::cout << "FROM MAIN: id of t2 " << t2.get_id() << std::endl;

  std::cout << std::endl;

  // 메인 스레드의 ID를 출력
  std::cout << "FROM MAIN: id of main= " << std::this_thread::get_id() << std::endl;

  // t1과 t2의 작업이 끝날 때까지 대기
  t1.join();
  t2.join();

  std::cout << std::endl;

}

// join()을 사용해서 t1, t2 스레드의 작업이 모두 끝날 때까지 기다렸다가 main 스레드가 실행되도록 하게 하기 때문에 맨 마지막에 출력된다. 
// 따라서 이 코드에서 std::cout << std::endl; 이후의 출력문들은 t1과 t2 스레드의 작업이 모두 끝난 후에 실행되어 t1과 t2 스레드의 출력이 가장 마지막에 나타나게 된다.
// 스레드가 실행되는 순서는 운영체제의 스케줄러에 의해 결정됩니다. 따라서 스레드의 ID 출력 순서와 스레드의 실행 순서가 정확히 일치하지 않을 수 있습니다.
