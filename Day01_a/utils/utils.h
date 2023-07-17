#ifndef UTILS
#define UTILS

#include<vector>
#include<string>

//using namespace std;

float adder(float a, float b);

int readInputString(std::string inputpath, std::vector<std::string>& result);

std::string replaceStr(std::string targetString, const std::string& from, const std::string& to);

#endif  // UTILS