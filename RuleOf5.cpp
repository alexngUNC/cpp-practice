#include <iostream>

class DynamicIntArray {
  private:
    int* data;
    size_t size;

  public: 
    // constructor
    DynamicIntArray(size_t s) : size(s) {
      data = new int[size];
      for (size_t i=0; i<size; i++) {
        data[i] = i+1;
      }
    }

    // destructor
    ~DynamicIntArray() {
      delete[] data;
    }

    // copy constructor
    DynamicIntArray(const DynamicIntArray& other) : size(other.size) {
      data = new int[size];
      for (size_t i=0; i<size; ++i) {
        data[i] = other.data[i];
      }
    }

    // copy assignment constructor
    DynamicIntArray& operator=(const DynamicIntArray& other) {
      if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (size_t i=0; i<size; ++i) {
          data[i] = other.data[i];
        }
      }
      return *this;
    }

    // move constructor
    DynamicIntArray(DynamicIntArray&& other) noexcept : data(other.data), size(other.size) {
      other.data = nullptr;
      other.size = 0;
    }

    // move assignment operator
    DynamicIntArray& operator=(DynamicIntArray&& other) noexcept {
      if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
      }
      return *this;
    }

    // print the array
    void print() const {
      for (size_t i=0; i<size; ++i) {
        std::cout << data[i] << " ";
      }
      std::cout << std::endl;
    }
};

int main() {
  DynamicIntArray arr1(5);
  for (size_t i=0; i<5; ++i) {
    arr1.print();
  }

  // calls copy constructor
  DynamicIntArray arr2 = arr1; 
  arr2.print();

  DynamicIntArray arr3(3);
  // calls assignment operator
  arr3 = arr1;

  // calls move constructor
  DynamicIntArray arr4(std::move(arr1));
  arr4.print(); // arr1 is now in a valid but unspecified state

  DynamicIntArray arr5(4);
  // Move assignment operator
  arr5 = std::move(arr2);
  arr5.print();
  // arr2 is now in a valid but unspecified state

  return 0;
}