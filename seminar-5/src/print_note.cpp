#include "print_note.h"

void printNote(const Note &note) {
  std::cout << std::get<0>(note) << " " << std::get<1>(note) << " ";
  auto &tegs = std::get<2>(note);
  for (const std::string &teg : tegs) {
    std::cout << teg << " ";
  }
  std::cout << "\n";
}

void printAllNotes(const std::vector<Note> &notes) {
  for (const auto &note : notes) {
    printNote(note);
  }
}