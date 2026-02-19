#include <iostream>
#include "read_and_parse.h"
#include "statistics.h"
#include "write_statistics_csv.h"

using TableNumbers = std::map<std::string, std::vector<double>>;

int main() {
  TableNumbers table_numbers = read_and_parse("data/input.csv", ',');
  write_statistics_csv("../data/output.csv", table_numbers);
  return 0;
}