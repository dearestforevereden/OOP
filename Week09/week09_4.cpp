#include <unordered_map>
#include <iostream>
#include <vector>

int main(){
  // Initialize an unordered_map with string keys and integer values
  std::unordered_map<std::string, int> unordMap{
    {"Rainer",1966}, {"Beatrix", 1966}, {"Juliette",1997},{"Marisus", 1999} 
  };
  // Define a constant iterator pointing to the end of the unordered_map
  std::unordered_map<std::string, int>::const_iterator endMapIt = unordMap.end();
  // Define an iterator for the unordered_map
  std::unordered_map<std::string, int>::iterator mapIt;

  // Iterate through the unordered_map and print key-value pairs
  for ( mapIt = unordMap.begin(); mapIt != endMapIt; ++mapIt )
    std::cout << "{" << mapIt->first << "," << mapIt->second << "}";
    std::cout << std::endl;

  // Initialize a vector with integer elements
  std::vector<int> myVec{1,2,3,4,5,6,7,8,9};
  // Define a constant iterator pointing to the end of the vector
  std::vector<int>::const_iterator vecEndIt = myVec.end();
  // Define an iterator for the vector
  std::vector<int>::iterator vecIt;
  
  // Iterate through the vector and print its elements
  for ( vecIt = myVec.begin(); vecIt != vecEndIt; ++vecIt )
    std::cout << *vecIt << " ";

   std::cout << std::endl;

  // Iterate through the vector using range-based for loop and print its elements
  for ( const auto v: myVec )
    std::cout << v << " ";
  std::cout << std::endl;

  // Define a constant reverse iterator pointing to the end of the vector
  std::vector<int>::const_reverse_iterator vecEndRevIt = myVec.rend();
  // Define a reverse iterator for the vector
  std::vector<int>::reverse_iterator vecRevIt;
  
  // Iterate through the vector in reverse order and print its elements
  for ( vecRevIt = myVec.rbegin(); vecRevIt != vecEndRevIt; ++vecRevIt )
    std::cout << *vecRevIt << " ";

  return 0;
}

