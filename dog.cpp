#include <iostream>
#include <string_view>


class Dog {
  public:
    Dog() = default;
    Dog(std::string_view namePar, std::string_view breedPar, int pAgePar);
    ~Dog();
    std::string getName();
    Dog* setName(const std::string& name);
    Dog* setAge(int age);
    int getAge();

  private:
    std::string name;
    std::string breed;
    int* pAge {nullptr};
};

Dog::Dog(std::string_view name, std::string_view breed, int age) {
  this->name = name;
  this->breed = breed;
  this->pAge = new int;
  *(this->pAge) = age;
  std::cout << name << " has entered at " << this << std::endl;
}

// destructor
Dog::~Dog() {
  delete pAge;
  std::cout << name << " has left from " << this << std::endl;
}

std::string Dog::getName() {
  return name;
}

int Dog::getAge() {
  return *pAge;
}

Dog* Dog::setName(const std::string& name) {
  this->name = name;
  return this;
}

// return reference
/*
Dog& Dog::setName(const std::string& name) {
  this->name = name;
  return *this;
}
*/

Dog* Dog::setAge(int age) {
  if (this->pAge) {
    *(this->pAge) = age;
  }
  return this;
}

int main() {
  Dog* dog = new Dog("Bailey", "shepherd", 7);
  std::cout << dog->getName() << "'s age: " << dog->getAge() << std::endl;

  // change name and age
  dog->setName("Sadie")->setAge(14);
  // reference chaining
  // *dog.setName("Sadie").setAge(14);
  std::cout << dog->getName() << "'s age: " << dog->getAge() << std::endl;
  delete dog;
  return 0;
}
