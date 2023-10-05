#ifndef UTILS
#define UTILS

#include<vector>
#include<string>

//using namespace std;

float adder(float a, float b);

int readInputString(std::string inputpath, std::vector<std::string>& result);

std::string replaceStr(std::string targetString, const std::string& from, const std::string& to);


std::vector<std::string> splitStr(std::string line, const std::string& delimiter);


std::string vectorToString(const std::vector<std::string>& vec);


#endif  // UTILS