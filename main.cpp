#include <iostream>
#include <limits>

int main(void) {
  // std::cout << "The range for short is from " << std::numeric_limits<short>::min();
  // std::cout << " to " << std::numeric_limits<short>::max() << std::endl;

  short int var1 = 10; // 2 bytes
  short int var2 = 20;

  char var3 = 40; // 1 byte
  char var4 = 50;

  // automatically converted to int
  auto result1 = var1+ var2;
  auto result2 = var3 + var4;

  char resultC = var3 + var4;

  std::cout << "size of var1: " << sizeof(var1) << std::endl;
  std::cout << "size of var2: " << sizeof(var2) << std::endl;
  std::cout << "size of var3: " << sizeof(var3) << std::endl;
  std::cout << "size of var5: " << sizeof(var4) << std::endl;

  std::cout << "var1 + var2: " << result1 << std::endl;
  std::cout << "var3 + var4: " << result2 << std::endl;

  std::cout << "size of result1: " << sizeof(result1) << std::endl;
  std::cout << "size of result2: " << sizeof(result2) << std::endl;
  return 0;
}