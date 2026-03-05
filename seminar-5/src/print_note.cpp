#include "print_note.h"

void printNote(Note& note) {
  std::cout << std::get<0>(note) << " " << std::get<1>(note) << " ";
  auto& tegs = std::get<2>(note);
  for (auto teg : tegs) {
    std::cout << teg << " ";
  }
  std::cout << "\n";
}

void printAllNotes(std::vector<Note>& notes) {
  for (auto& note : notes) {
    printNote(note);
  }
}