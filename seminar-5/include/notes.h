#ifndef NOTES_H
#define NOTES_H
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using Note = std::tuple<int, std::string, std::vector<std::string>>;
void addNote(std::vector<Note> &notes,
             std::unordered_map<std::string, std::vector<int>> &tagIndex,
             std::stack<int> &deletedIds, int &nextId, const std::string &text,
             const std::vector<std::string> &tags);
void deleteNote(
    std::vector<std::tuple<int, std::string, std::vector<std::string>>> &notes,
    std::unordered_map<std::string, std::vector<int>> &tagIndex,
    std::stack<int> &deletedIds, int id);
#endif