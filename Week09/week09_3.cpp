#include <iostream>
#include <queue>
#include <string> // Include string header for std::string

int main() {
    // Original priority queue
    std::priority_queue<int> myPriorityQueue;
    std::cout << std::boolalpha << "empty() : " << myPriorityQueue.empty() << std::endl;
    std::cout << "size() : " << myPriorityQueue.size() << std::endl;

    myPriorityQueue.push(3);
    myPriorityQueue.push(1);
    myPriorityQueue.push(2);

    std::cout << "size() : " << myPriorityQueue.size() << std::endl;
    std::cout << "top() : " << myPriorityQueue.top() << std::endl;
    while(!myPriorityQueue.empty()){
        std::cout << "top() : " << myPriorityQueue.top() << std::endl;
        myPriorityQueue.pop();
    }

  std::cout << std::boolalpha << "empty() : " << myPriorityQueue.empty() << std::endl;
  std::cout << "size() : " << myPriorityQueue.size() << std::endl;


    // New priority queue
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string> > myPriorityQueue2;

    myPriorityQueue2.push("Apple");
    myPriorityQueue2.push("Ding");
    myPriorityQueue2.push("Banana");
    myPriorityQueue2.push("Can");
    myPriorityQueue2.push("Emma");
    myPriorityQueue2.push(".");

    while(!myPriorityQueue2.empty()){
   std::cout << "top() : " << myPriorityQueue2.top() << std::endl;
    myPriorityQueue2.pop();
  }
    return 0;
}

