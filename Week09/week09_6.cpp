#include <iostream>
#include <iterator> // Include the iterator header for iterator-related operations
#include <deque>    // Include the deque header for deque container
#include <vector>   // Include the vector header for vector container
#include <algorithm> // Include the algorithm header for find function

int main(){
  
  std::deque<int> deq{5,6,7,10,11,12}; // Create a deque named 'deq' and initialize it with some integers
  std::vector<int> vec{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; // Create a vector named 'vec' and initialize it with some integers
  
  // Find the value 13 in the vector 'vec', copy all elements from that point till the end, and insert them into the back of 'deq' deque
  std::copy(std::find(vec.begin(), vec.end(), 13), vec.end(), std::back_inserter(deq));
  
  // Print the elements of 'deq' deque
  for (auto d: deq) std::cout << d << " ";
  std::cout << std::endl;

  // Find the value 8 and 10 in the vector 'vec', copy the range between them, and insert them into 'deq' after the first occurrence of 10
  std::copy(std::find(vec.begin(), vec.end(), 8),
            std::find(vec.begin(), vec.end(), 10),
            std::inserter(deq, std::find(deq.begin(), deq.end(),10)));

  // Print the elements of 'deq' deque
  for (auto d: deq) std::cout << d << " ";
  std::cout << std::endl;
 
  // Copy the elements of 'vec' starting from the 12th element till the end, and insert them into the front of 'deq' deque
  std::copy(vec.rbegin() + 11, vec.rend(), std::front_inserter(deq));
  
  // Print the elements of 'deq' deque
  for (auto d: deq) std::cout << d << " ";
  
  std::cout << std::endl;
}

