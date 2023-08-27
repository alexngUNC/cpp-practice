#include <iostream> 

int main() {
  // Declare and initialize pointer as nullptr
  int* pNum {};
  double* pFrac {};

  // declare numbers
  int num = 4;
  double frac = 0.25;

  // assign addresses
  pNum = &num;
  pFrac = &frac;

  // print pointers
  std::cout << "pNum: " << pNum << std::endl;
  std::cout << "pFrac " << pFrac << std::endl;

  // all pointers are the same size
  std::cout << "sizeof(pNum): " << sizeof(pNum) << std::endl;
  std::cout << "sizeof(pFrac): " << sizeof(pFrac) << std::endl;

  // get addresses
  std::cout << "&num " << &num << std::endl;
  std::cout << "&frac " << &frac << std::endl;

  std::cout << std::endl;

  // be careful declaring multiple pointers on the same line 
  int* pNum2, num2;
  double* pFrac2, frac2;

  int *pInt1, *pInt2;
  double *pDub1, *pDub2;
  std::cout << "sizeof(pNum2): " << sizeof(pNum2) << " " << "sizeof(num2): " << sizeof(num2) << std::endl;
  std::cout << "sizeof(pFrac2): " << sizeof(pFrac2) << " " << "sizeof(frac2): " << sizeof(frac2) << std::endl;
  std::cout << std::endl;
  std::cout << "sizeof(pInt1): " << sizeof(pInt1) << " " << "sizeof(pInt2): " << sizeof(pInt2) << std::endl;
  std::cout << "sizeof(pDub1): " << sizeof(pDub1) << " " << "sizeof(pDub2): " << sizeof(pDub2) << std::endl;

  std::cout << std::endl;

  // char* string literals are const, can't modify character elements
  const char* pChar = "Yes";
  std::cout << pChar << std::endl;
  std::cout << *pChar << std::endl;
  std::cout << std::endl;
  return 0;
}