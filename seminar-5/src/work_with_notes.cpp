#include <notes.h>

void addNote(std::vector<Note> &notes,
             std::unordered_map<std::string, std::vector<int>> &tagIndex,
             std::stack<int> &deletedIds, const std::string &text,
             const std::vector<std::string> &tags) {
  int id = generate_id(deletedIds);
  notes.emplace_back(id, text, tags);
#pragma omp parallel for
  for (size_t i = 0; i < tags.size(); ++i) {
    const auto &tag = tags[i];
#pragma omp critical
    { tagIndex[tag].push_back(id); }
  }
}