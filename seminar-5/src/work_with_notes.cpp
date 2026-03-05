#include <algorithm>
#include <notes.h>
#include <omp.h>

int generate_id(std::stack<int> &deletedIds, int nextId) {
  if (deletedIds.empty()) {
    return nextId++;
  }
  int first_deleted_id = deletedIds.top();
  deletedIds.pop();
  return first_deleted_id;
}

void addNote(std::vector<Note> &notes,
             std::unordered_map<std::string, std::vector<int>> &tagIndex,
             std::stack<int> &deletedIds, int nextId, const std::string &text,
             const std::vector<std::string> &tags) {
  int id = generate_id(deletedIds, nextId);
  notes.emplace_back(id, text, tags);
#pragma omp parallel for
  for (size_t i = 0; i < tags.size(); ++i) {
    const auto &tag = tags[i];
#pragma omp critical
    { tagIndex[tag].push_back(id); }
  }
}

void deleteNote(
    std::vector<std::tuple<int, std::string, std::vector<std::string>>> &notes,
    std::unordered_map<std::string, std::vector<int>> &tagIndex,
    std::stack<int> &deletedIds, int id) {
  auto noteToDelete =
      std::find_if(notes.begin(), notes.end(),
                   [id](const auto &Note) { return std::get<0>(Note) == id; });
  if (noteToDelete != notes.end()) {
    const auto &tagsToDelete = std::get<2>(*noteToDelete);
#pragma omp parallel for
    for (size_t idx = 0; idx < tagsToDelete.size(); ++idx) {
      const auto &tag = tagsToDelete[idx];
      auto currentTag = tagIndex.find(tag);
      if (currentTag != tagIndex.end()) {
        auto &noteID = currentTag->second;
#pragma omp critical
        {
          std::vector<int> tempVector;
          for (int currentId : noteID) {
            if (currentId != id) {
              tempVector.push_back(currentId);
            }
          }
          noteID = std::move(tempVector);
        }
      }
    }
    notes.erase(noteToDelete);
    deletedIds.push(id);
  }
}