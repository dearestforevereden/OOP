#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include <string>
#include <vector>

template <typename Cont, typename T>
void doTheSame(Cont cont, T t) {
  std::cout << "Original container: " << std::endl;
  for (auto c : cont) std::cout << c << " ";
  std::cout << std::endl;
  std::cout << "Original container size: " << std::endl;
  std::cout << "cont.size():" << cont.size() << std::endl;

  std::cout << "Reversed container: " << std::endl;
  std::reverse(cont.begin(), cont.end());
  for (auto c:cont)std::cout << c<<" ";
  std::cout << std::endl;

  std::cout << "Reversed again container: " << std::endl;
  std::reverse(cont.begin(),cont.end());
  for (auto c:cont) std::cout << c<< " ";
  std::cout <<std::endl;

  std::cout << "Reversed container from element " <<t << " : " <<std::endl;
  auto It = std::find(cont.begin(),cont.end(),t);
  std::reverse(It, cont.end());
  for (auto c:cont) std::cout << c << " ";
  std::cout << std::endl;
}

int main(){
  std::vector<int> myVec{1,2,3,4,5,6,7,8,9,10};
  doTheSame(myVec, 5);
  std::deque<std::string> myDeque({"A", "B", "C", "D", "E", "F", "G", "H", "I"});
  doTheSame(myDeque, "E"); 
  std::list<char> myList({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'});
  doTheSame(myList, 'e');
} 

