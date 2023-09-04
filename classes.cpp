#include <iostream>
#include "cylinderImpl.h"

int main() {
  Cylinder cyl1;
  std::cout << "cyl1 vol: " << cyl1.volume() << std::endl;

  Cylinder c2 = Cylinder(4.0, 8.0);
  std::cout << "Cylinder 2 Volume: " << c2.volume() << std::endl;

  // allocate on heap
  Cylinder* c3 = new Cylinder(11, 20);
  std::cout << "Cylinder 3 Volume: " << c3->volume() << std::endl;
  std::cout << "Cylinder 3 Height: " << (*c3).getHeight() << std::endl;
  delete c3;
  return 0;
}