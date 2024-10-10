#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Square each element of the vector
    std::for_each(myVec.begin(), myVec.end(), [](int& i) { i = i * i; });

    // Print the modified vector
    for (int num : myVec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

