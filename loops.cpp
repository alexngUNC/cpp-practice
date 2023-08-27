#include <iostream>

int main() {
  char message[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
  char messageBad[5] = {'h', 'e', 'l', 'l', 'o'};
  std::cout << message << std::endl;
  for (auto c : message)
    std::cout << c << " ";
  std::cout << std::endl;
  std::cout << sizeof(message) << std::endl;
  std::cout << std::size(message) << std::endl;
  std::cout << std::size(messageBad) << std::endl;

  // string literal
  char literal[] {"literal"};
  for (auto c : literal)
    std::cout << c << " ";
  std::cout << std::endl;

  // print numbers
  int nums[] {1, 2, 3, 4, 5};
  for (int n : nums)
    std::cout << n << " ";
  std::cout << std::endl;
  return 0;
}