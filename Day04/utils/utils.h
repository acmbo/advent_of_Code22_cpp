#ifndef UTILS
#define UTILS

#include<vector>
#include<string>

//using namespace std;

float adder(float a, float b);

int readInputString(std::string inputpath, std::vector<std::string>& result);

std::string replaceStr(std::string targetString, const std::string& from, const std::string& to);

std::vector<std::string> splitStr(std::string line, const std::string& delimiter);

std::tuple<std::string, std::string> splitStrAt(std::string line, const int& index);

bool strContains(std::string const& line, char s);

std::string vectorToString(const std::vector<std::string>& vec);

/// <summary>
/// checks if a object is within a vector of the same Type
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="target"></param>
/// <param name="entry"></param>
/// <returns></returns>
template <typename T>
bool vectorContains(const std::vector<T>& target, T entry)
{
    return std::find(target.begin(), target.end(), entry) != target.end();
}

#endif  // UTILS