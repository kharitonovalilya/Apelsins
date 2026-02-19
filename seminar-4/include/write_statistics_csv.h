#ifndef WRITE_STATISTICS_CSV_H
#define WRITE_STATISTICS_CSV_H

#include <map>
#include <string>
#include <vector>

void write_statistics_csv(
    const std::string &filename,
    const std::map<std::string, std::vector<double>> &data,
    char delimiter = ',');

#endif