
#ifndef PRINT_NOTE_H
#define PRINT_NOTE_H
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using Note = std::tuple<int, std::string, std::vector<std::string>>;
void printNote(Note &note);
void printAllNotes(std::vector<Note> &notes);
#endif