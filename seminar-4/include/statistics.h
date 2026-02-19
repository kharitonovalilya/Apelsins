#ifndef STATISTICS_H
#define STATISTICS_H

#include <map>
#include <string>
#include <vector>

std::map<std::string, double> calculate_statistics(const std::vector<double>& data);

#endif