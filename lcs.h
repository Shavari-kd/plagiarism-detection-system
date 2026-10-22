#ifndef LCS_H
#define LCS_H
#include <string>
#include <vector>

int computeLCS(const std::string &X, const std::string &Y, std::vector<std::vector<int>> &dp);
std::string getLCS(const std::string &X, const std::string &Y, std::vector<std::vector<int>> &dp);

#endif