#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
  // init rand with seed
  std::srand(314159);

  std::vector<int> vec;
  
  // add random integers
  for (auto i = 1; i <= 5; ++i)
    vec.push_back(rand() % 100);

  // print vector size
  std::cout << "vector size: " << vec.size() << std::endl;

  std::cout << "vector elements: ";

  for (auto &elem : vec)
    std::cout << elem << " ";
  std::cout << std::endl;

  return 0;

  
}