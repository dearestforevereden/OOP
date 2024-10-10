#include <iostream>
#include <vector>
#include <algorithm>

// Define the square function outside of the main function
void square(int& i) {
    i = i * i;
}

int main() {
    // Create a vector
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use std::for_each to apply the square function to each element
    std::for_each(myVec.begin(), myVec.end(), square);

    // Print the elements of the vector after applying the square function
    for (auto v : myVec) std::cout << v << " ";

    return 0;
}

