#include <iostream>
#include <cstring>
#include <string>

int main() {
  // check if a character is alphanum
  std::cout << "C is alphanum: " << std::isalnum('C') << std::endl;
  std::cout << "^ is alphanum: " << std::isalnum('^') << std::endl;

  // can use this as a test condition
  char inputChar {'*'};
  if (std::isalnum(inputChar)) {
    std::cout << inputChar << " is alphanum" << std::endl;
  } else {
    std::cout << inputChar << " is not alphanum" << std::endl;
  }

  // check if a character is alphabetic
  if (std::isalpha(inputChar)) {
    std::cout << inputChar << " is alphabetic" << std::endl;
  } else {
    std::cout << inputChar << " is not alphabetic" << std::endl;
  }


  // check if a character is blank with std::isblank()
  char message[] {"Hello, there. How are you doing? The sun is shining. There are 8 planets in our solar system. The year is 2023. 1,000,000 is a big number, but 1e10 is even bigger!"};
  std::cout << message << std::endl;

  // find and print blank indices
  int blankCount {};
  for (size_t i {0}; i<std::size(message); i++) {
    // std::cout << "Value: " << message[i] <<std::endl;
    if (std::isblank(message[i])) {
      std::cout << "Found a blank character at index: [" << i << "]" << std::endl;
      ++blankCount;
    }
  }
  std::cout << "Total blank characters: " << blankCount << std::endl;


  // check if a character is lowercase or uppercase with std::islower and std::isupper
  int lowerCount {};
  int upperCount {};
  for (auto c : message) {
    if (std::islower(c)) { 
      std::cout << " " << c;
      ++lowerCount;
    } else if (std::isupper(c)) {
      ++upperCount;
    }
  }

  std::cout << std::endl << "Found " << lowerCount << " lowercase characters and " << upperCount << " uppercase characters" << std::endl;
  std::cout << std::endl;

  // check if a character is a digit with std::isdigit
  int digitCount {};
  for (char c : message) {
    if (std::isdigit(c)) {
      std::cout << "Found digit: " << c << std::endl;
      ++digitCount;
    }
  }
  std::cout << std::endl << "Found " << digitCount << " digits in the message" << std::endl;

  // change everything to uppercase
  char upperMes[std::size(message)];
  for (size_t i{}; i<std::size(message); i++) {
    upperMes[i] = std::toupper(message[i]);
  }
  std::cout << upperMes << std::endl;

  // error: std::cout << std::toupper(message) << std::endl;

  // find length of a string with std::strlen
  const char message1[] {"The sky is blue"};
  std::cout << "message1: " << message1 << std::endl;

  // strlen ignotes the null character
  std::cout << "std::strlen(message1): " << std::strlen(message1) << std::endl;

  // sizeof includes the null character
  std::cout << "sizeof(message1): " << sizeof(message1) << std::endl;

  // array decays into a pointer when we use const char*
  const char* message2 {"The sky is red"};
  std::cout << "message2: " << message2 << std::endl;

  // strlen still works with decayed arrays
  std::cout << "strlen(message2): " << std::strlen(message2) << std::endl;

  // prints the size of the pointer instead of the size of the string
  std::cout << "sizeof(message2): " << sizeof(message2) << std::endl;

  std::cout << std::endl;
  std::cout << "========================" << std::endl;
  std::cout << std::endl;

  // Compare strings
  /*
    std::strcmp - signature: int strcmp(const char* lhs, const char* rhs);
    returns negative if lhs appears before rhs in lexicographical order
    returns zero if lhs and rhs are equal
    returns positive if lhs appears after rhs in lexicographical order
    can use strncmp to compare  the first n characters
  */
  const char* string1 {"Alabama"};
  const char* string2 {"Blabama"};
  const char* string3 {"alabama"};
  const char* string4 {"Alabama"};

  // print comparison
  std::cout << "std::strcmp(" << string1 << "," << string2 << "): " 
    << std::strcmp(string1, string2)  << std::endl;
  std::cout << "std::strcmp(" << string1 << "," << string3 << "): " 
  << std::strcmp(string1, string3)  << std::endl;
  std::cout << "std::strcmp(" << string1 << "," << string4 << "): " 
  << std::strcmp(string1, string4)  << std::endl;

  std::cout << std::endl;
  std::cout << "========================" << std::endl;
  std::cout << std::endl;

  // Find first occurrence of a character
  char target = 'a';
  const char* result = string1;
  int iterations {};

  while ((result = std::strchr(result, target)) != nullptr) {
    std::cout << "Found " << target << " starting at " << result << "'\n'";
    // increment result to find next target
    result++;
    iterations++;
  }
  std::cout << "Iterations: " << iterations << std::endl;

  // find last occurence of a character
  std::cout << std::endl;
  char input[] = "/home/alexng/preempt/hello.cpp";
  char* output = std::strrchr(input, '/');
  if (output)
    // +1 because we want to start printing past the character found by std::strrchr
    std::cout << output+1 << std::endl;

  std::cout << std::endl;
  std::cout << "========================" << std::endl;
  std::cout << std::endl;

  // concatenate strings
  std::cout << std::endl;
  char dest[50] = "Hello ";
  char src[50] = "World!";
  std::strcat(dest, src);
  std::cout << dest << std::endl;
  std::strcat(dest, " Goodbye world!");
  std::cout << "dest: " << dest << std::endl;
  // strncat to concatenate n characters from src to dest and returns a pointer to the result string
  std::cout << std::strncat(dest, src, 2) << std::endl;

  // copy strings
  std::cout << std::endl;
  const char* banana = "banana";
  char* banana2 = new char[std::strlen(banana) + 1]; // null terminator
  std::strcpy(banana2, banana);
  std::cout << sizeof(banana2) << std::endl;
  std::cout << std::strlen(banana2) << std::endl;
  std::cout << banana2 << std::endl;

  // std::string
  std::string empty; // empty string
  std::string planet {"Earth"};
  std::string greeting {"Hello there", 5}; // take first 5 characters
  std::string FiveAs {5, 'A'};
  return 0;
}