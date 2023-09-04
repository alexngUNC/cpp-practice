#include <iostream>
#include <concepts>
#include <type_traits>

// syntax 1
template <typename T>
concept MyIntegral = std::is_integral_v<T>;

/*
template <typename T>
requires MyIntegral<T>
T add (T a, T b) {
  return a + b;
}
*/


template <MyIntegral T>
T add(T a, T b) {
  return a + b;
}

/*
template <typename T>
T add(T a, T b) requires MyIntegral<T> {
  return a + b;
}
*/

/*
MyIntegral auto add(MyIntegral auto T a, T b) {
  return a + b;
}
*/

template <typename T>
concept Multipliable = requires(T a, T b) {
  a * b; // must support multiplication operator
};

template <Multipliable T> 
T multiply(T a, T b) {
  return a * b;
}

template <typename T>
concept Incrementable = requires(T a) {
  a+=1;
  ++a;
  a++;
};

template <Incrementable T>
T up(T a) {
  return ++a;
}

template <typename T>
concept TinyType = requires(T t) {
  sizeof(T) <= 4; // simple requirement only checks syntax
  requires sizeof(T) <= 4; // nested requirement evaluates expression to see if it is true
};

TinyType auto tinyAdd(TinyType auto a, TinyType auto b) {
  return a + b;
}

// compound requirement
template <typename T>
concept Addable = requires(T a, T b) {
  // noexcept is optional and checks that it doesn't throw exceptions
  // checks if a + b is valid syntax and the result is convertible it int
  {a + b} noexcept -> std::convertible_to<int>; 
};

int main() {
  int x {6};
  int y {7};
  double x2 {6.0};
  double y2 {7.0};
  std::cout << add(x, y) << std::endl;
  std::cout << tinyAdd(x, y) << std::endl;
  // fails: std::cout << tinyAdd(x2, y2) << std::endl;
  std::cout << multiply(x, y) << std::endl;
  std::cout << up(x) << std::endl;

  // enforce a concept when delcaring a variable
  std::integral auto z = add(x, y);
  return 0;
}