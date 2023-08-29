#include <iostream>

int main() {

  int intVal {45};
  double doubleVal {33.65};

  // Assign through initialization
  int& refIntVal {intVal};
  
  // assign through assignment
  double& refDubVal = doubleVal;

  // you have to declare and initialize in one statement
  // int& some_ref; error

  std::cout << "intVal: " << intVal << std::endl;
  std::cout << "refIntVal: " << refIntVal << std::endl;
  std::cout << "doubleVal: " << doubleVal << std::endl;
  std::cout << "refDubVal: " << refDubVal << std::endl;
  std::cout << "&intVal: " << &intVal << std::endl;
  std::cout << "&refIntVal: " << &refIntVal << std::endl;
  std::cout << "sizeof(int): " << sizeof(int) << std::endl;
  std::cout << "sizeof(int&): " << sizeof(int&) << std::endl;
  std::cout << "sizeof(intVal): " << sizeof(intVal) << std::endl;
  std::cout << "sizeof(refIntVal): " << sizeof(refIntVal) << std::endl;
  std::cout << "sizeof(double): " << sizeof(double) << std::endl;
  std::cout << "sizeof(double&): " << sizeof(double&) << std::endl;

  std::cout << std::endl;
  std::cout << "========================" << std::endl;
  std::cout << std::endl;

  // modify values
  int* pInt = &intVal;
  intVal = 111;
  doubleVal = 67.2;

  std::cout << "intVal: " << intVal << std::endl;
  std::cout << "refIntVal: " << refIntVal << std::endl;
  std::cout << "pInt: " << pInt << std::endl;
  std::cout << "*pInt: " << *pInt << std::endl;
  std::cout << "doubleVal: " << doubleVal << std::endl;
  std::cout << "refDubVal: " << refDubVal << std::endl;

  std::cout << std::endl;
  std::cout << "========================" << std::endl;
  std::cout << std::endl;

  refIntVal = 1012;
  refDubVal = 100.45;
  pInt = &refIntVal;

  std::cout << "intVal: " << intVal << std::endl;
  std::cout << "refIntVal: " << refIntVal << std::endl;
  std::cout << "pInt: " << pInt << std::endl;
  std::cout << "*pInt: " << *pInt << std::endl;
  std::cout << "doubleVal: " << doubleVal << std::endl;
  std::cout << "refDubVal: " << refDubVal << std::endl;

  return 0;
}