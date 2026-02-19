#include "write_statistics_csv.h"
#include "statistics.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>

void write_statistics_csv(
    const std::string &filename,
    const std::map<std::string, std::vector<double>> &data,
    char delimiter = ',') {
  std::ofstream final_csv(filename);
  if (!final_csv.is_open()) {
    return;
  }
  std::vector<std::string> metrics = {
      "count",    "sum",           "mean", "min", "max", "range", "median",
      "variance", "std_deviation", "q1",   "q2",  "q3",  "iqr"};
  final_csv << "column";
  for (const auto &element : metrics) {
    final_csv << delimiter << element;
  }
  final_csv << '\n';
  for (const auto &[col_name, values] : data) {
    auto stats = calculate_statistics(values);
    final_csv << col_name;
    for (const auto &element : metrics) {
      final_csv << delimiter;
      auto result = stats.find(element);
      if (result != stats.end()) {
        final_csv << result->second;
      } else {
        final_csv << "";
      }
    }
    final_csv << '\n';
  }
}
