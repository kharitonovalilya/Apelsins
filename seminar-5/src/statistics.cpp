#include "statistics.h"

std::map<std::string, int>
getTagStats(const std::unordered_map<std::string, std::vector<int>> &tagIndex) {
  std::map<std::string, int> stats;
  for (const auto &[tag, notesID] : tagIndex) {
    stats[tag] = notesID.size();
  }
  return stats;
}