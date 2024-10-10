#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;
    std::cout << std::boolalpha << "myQueue.empty() : " << myQueue.empty() << std::endl; // true
    std::cout << "myQueue.size() : " << myQueue.size() << std::endl; // 0

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    std::cout << "myQueue.size() : " << myQueue.size() << std::endl; // 3
    std::cout << "myQueue.back() : " << myQueue.back() << std::endl; // 3
    std::cout << "myQueue.front() : " << myQueue.front() << std::endl; // 1

    while (!myQueue.empty()) {
        std::cout << "myQueue.back() : " << myQueue.back() << std::endl;
        std::cout << "myQueue.front() : " << myQueue.front() << std::endl;
        myQueue.pop();
    }

  std::cout << std::boolalpha << "myQueue.empty() : " << myQueue.empty() << std::endl;
    std::cout << "myQueue.size() : " << myQueue.size() << std::endl;
    return 0;
}


