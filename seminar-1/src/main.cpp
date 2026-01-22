#include <iostream>

#include "sub.h"

int main() {
  std::cout << "Enter two integer numbers:\n";

  long long first_number = 0;
  long long second_number = 0;

  if (!(std::cin >> first_number >> second_number)) {
    std::cerr << "Invalid input\n";
    return -1;
  }

  std::cout << "Your result: " << sub(first_number, second_number) << "\n";
}