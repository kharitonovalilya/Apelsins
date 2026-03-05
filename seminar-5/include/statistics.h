#ifndef TAG_STATS_H
#define TAG_STATS_H
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
std::map<std::string, int>
getTagStats(const std::unordered_map<std::string, std::vector<int>> &tagIndex);
#endif