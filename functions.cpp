#include <iostream>
#include <cstring>
#include <concepts>

// function template - types have to be the same
template <typename T> T maximum(T a, T b);

// pass by reference
template <typename T> const T& max2(const T& a, const T& b);

// template specialization
template <>
const char* maximum<const char*> (const char* a, const char* b);

// concept for type restriction
/* syntax 1
template <typename T> 
requires std::integral<T>
T add (T a, T b) {
  return a + b;
} 
*/

//syntax 2
template <std::integral T>
T add(T a, T b) {
  return a + b;
}

/* syntax for using auto for parameters and return type
auto add(std::integral auto a, std::integral auto b) {
  return a + b;
}
*/

// syntax 4
/*
template <typename T>
T add(T a, T b) requires std::integral<T> {
  return a + b;
}
*/


int main() {

  // lambda function
  [] (int num) {
    std::cout << "Your magic number is: " <<  num << std::endl;
  }(4);

  // lambda function with function handle to call multiple times
  auto func = [](int num) {
    if (num % 2 == 0) {
      std::cout << "Your number is even" << std::endl;
    } else {
      std::cout << "Your number is odd" << std::endl;
    }
  };

  // lambda function with return value
  auto result = [](int a, int b) -> int {
    return a^b;
  }(2, 8);

  func(21283987);
  func(21328148);
  std::cout << result << std::endl;


  // capture by value: data in the lambda function is a copy
  int c = 42;
  auto func2 = [c]() {
    std::cout << "Inner value: " << c << " &c: " << &c<<  std::endl;
  };
  for (size_t i{}; i<5; i++) {
    std::cout << "Outer value: " << c << "&c: " << &c<< std::endl;
    func2();
    ++c;
  }

  // capture by reference
  int d {42};
  auto func3 = [&d] () {
    std::cout << "Inner d: " << d << "&d: " << &d << std::endl;
  };
  for (size_t i{}; i<5; i++) {
    std::cout << "Outer d: " << d << "&d: " << &d << std::endl;
    func3();
    ++d;
  }

  // max for ints
  int a {8};
  int b {23};
  std::cout << "max(a, b): " << maximum(a, b) << std::endl;

  // max for doubles
  double c2 {4.0};
  double d2 {3.99};
  std::cout << "max(c2, d2): " << maximum(c2, d2) << std::endl;
  
  // template type deduction: explicitly say the type, implicit conversion
  std::cout << maximum<float>(c2, d2) << std::endl;

  // pass by reference example
  double a2 {23.5};
  double b2 {51.2};
  std::cout << "Out &a2: " << &a2 << std::endl;
  double max1 = max2(a2, b2);
  std::cout << "max1: " << max1 << std::endl;

  /*
  // return max string using specialization and string type deducing
  char* pChar1 {"car"};
  char* pChar2 {"boat"};
  char* maxString = maximum(pChar1, pChar2);
  std::cout << "maxString: " << maxString << std::endl;
  */


  /*========Concepts=======*/
  int b_0 {11};
  int b_1 {5};
  auto result_b = add(b_0, b_1);
  std::cout << "result_b: " << result_b << std::endl;
  return 0;
}

// template implementation
template <typename T> T maximum(T a, T b) {
  return (a > b) ? a : b;
}

// pass by reference
template <typename T> const T& max2(const T& a, const T& b) {
  std::cout << "In &a: " << &a << std::endl;
  return (a > b) ? a : b;
}

// template specialization for char*
template<>
const char* maximum<const char*> (const char* a, const char* b) {
  return (std::strcmp(a, b) > 0) ? a : b;
}