
#include <iostream>
#include <stack>

int main()
{
  std::stack<int> myStack;
  std::cout << std::boolalpha << "myStack.empty() : " << myStack.empty() <<std::endl; //turn to ture/false
  std::cout << "myStack.size() : " << myStack.size() << std::endl; // Zero

  myStack.push(1);
  myStack.push(2);
  myStack.push(3);
  myStack.push(77);
  myStack.push(100);
  std::cout << "myStack.size() : " << myStack.size() <<std::endl;
  std::cout << "myStack.top() : " << myStack.top() << std::endl;

  while (!myStack.empty()){
    std::cout << "myStack.top() : " << myStack.top() << std::endl;
    myStack.pop();
    }
    std:: cout << std::boolalpha << "myStack.empty() : " << myStack.empty()<< std::endl;
    std::cout << "myStack.size() : "  << myStack.size() << std::endl;

return 0;
}
