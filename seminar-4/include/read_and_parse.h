#ifndef READ_AND_PARSE_H
#define READ_AND_PARSE_H

#include <vector>
#include <map>
#include <string>


std::map<std::string, std::vector<double>>
read_and_parse(const std::string &filename, char delimetr);

#endif