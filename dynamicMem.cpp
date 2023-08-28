#include <iostream>

int main() {
  // it is possible to init a pointer with a valid address
  // upon declaration instead of a nullptr
  int* p_num1{ new int }; // memory allocation contains a junk value
  int* p_num2{ new int (22) }; // use direct initialization
  int* p_num3{ new int {23} }; // use uniform initialization

  std::cout << std::endl;
  std::cout << "Init with valid memory address at declaration: " << std::endl;
  std::cout << "p_num1: " << p_num1 << std::endl;
  std::cout << "*p_num1: " << *p_num1 << std::endl; // junk value

  std::cout << "p_num2: " << p_num2 << std::endl;
  std::cout << "*p_num2: " << *p_num2 << std::endl; 

  std::cout << "p_num3: " << p_num3 << std::endl;
  std::cout << "*p_num3: " << *p_num3 << std::endl; 

  // release memory
  delete p_num1;
  p_num1 = nullptr;

  delete p_num2;
  p_num2 = nullptr;

  delete p_num3;
  p_num3 = nullptr;



  int* p_num4{}; //initialize to nullptr
  p_num4 = new int(7);

  if (p_num4) {
    std::cout << "p_num4 points to a VALID address: " << p_num4 << std::endl;
    std::cout << "*p_num4: " << *p_num4 << std::endl;
  } else {
    std::cout << "p_num4 points to an INVALID address, don't dereference!" << std::endl;
  }

  delete p_num4; 
  p_num4 = nullptr;

  if (!p_num4) {
    std::cout << "p_num4 is null" << std::endl;
  }

  // it's ok to call delete on a nullptr
  delete p_num4;


  // memory leak example
  int* p_num5 {new int{67}}; // points to some address with int 67
  // should delete and reset p_num5 here
  delete p_num5;
  p_num5 = nullptr;

  // another int at a different address
  int number {55};

  // reassign pointer to the new int
  p_num5 = &number; // If p_num5 was not deleted and reset (it still pointed to the first int), 
                    // then the first heap address is still in use by our program but we lost it (memory leak) and can't release it  
  // another memory leak
  // p_num5 = new int{44};

  // pointers die with scope but the memory can remain
  /*
  {
    int* p_num6 {new int {56}};
    // must delete p_num6 since it won't be accessible outside of the scope
  }
  // memory with int 56 is still around
  
  */

  // Dynamically allocating arrays
  size_t size {10}; // size doesn't need to be const
  // salaries will contain garbage values
  double* pSalaries { new double[size] };
  // all values are initialized to 0
  int* pStudents { new(std::nothrow) int[size]{} };
  // allocating memory space for an array with the first 5 
  // numbers initialized to 1...5 and the rest will be 0s
  double* pScores { new(std::nothrow) double[size] {1, 2, 3, 4, 5} };

  // nullptr check and use array'
  if (pScores) {
    for (size_t i{}; i<size; ++i) {
      std::cout << "Value: " << pScores[i] << " | " << *(pScores+i) << std::endl;
    }
  }

  // free memory
  delete[] pScores;
  delete[] pStudents;
  delete[] pSalaries;
  pScores = nullptr;
  pStudents = nullptr;
  pSalaries = nullptr;
  return 0;
}