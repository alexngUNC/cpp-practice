#include <iostream>
#include <string_view>
#define string std::string

class Animal {
  public:
    Animal(string n) {
      this->name = n;
    }
  protected:
    string name;
  // private: error
    void makeNoise() {
      std::cout << "RRRAAAAHHHH" << std::endl;
    }
};

class Dog : Animal {
  public:
    Dog(string n) : Animal(n) {}
    using Animal::makeNoise;
    void makeNoise() {
      std::cout << "WOOOF" << std::endl;
    }
};

int main() {
  string name = "sadie";
  Dog sadie = Dog(name);
  sadie.makeNoise();

  return 0;
}