#include "print_note.h"

void printNote(Note& note) {
  std::cout << std::get<0>(note) << " " << std::get<1>(note) << "\n";
}