#include <iostream>

// function template - types have to be the same
template <typename T> T maximum(T a, T b);

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
  
  return 0;
}

// template implementation
template <typename T> T maximum(T a, T b) {
  return (a > b) ? a : b;
}