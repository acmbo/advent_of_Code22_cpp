#include "utils.h"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;

float adder(float a, float b)
{
	return (a + b);
}


int readInputString(string inputpath, vector<string>& result) {

    ifstream inputFile(inputpath);  // Open the file for reading
    if (!filesystem::exists(inputpath))
    {
        cerr << "Cant find the file at : " << inputpath << endl;
        return 1;
    }

    if (!inputFile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line)) {
        result.push_back(line);  // Print each line of the file
    }

    inputFile.close();  // Close the file
    return 0;
}


/// @brief Replaces parts of a string wit new set of string
/// @param targetString Complete string to look substring in
/// @param from Substring which to replace.
/// @param to String to replace with.
/// @return true for sucess
string replaceStr(string targetString, const string& from, const string& to)
{
    size_t position = targetString.find(from);
    if (position == targetString.size()) { return targetString; }

    targetString.replace(position, from.length(), to);

    // replace maybe other parts of the string
    targetString = replaceStr(targetString, from, to);
    return targetString;
}


/// <summary>
/// splits a string by a seperator/delimiter and returns a vector of all parts.
/// </summary>
/// <param name="line"></param>
/// <param name="delimiter"></param>
/// <returns></returns>
vector<string> splitStr(string line, const string& delimiter)
{
    vector<string> partsOfString;
    size_t pos = 0;
    string token;

    while ((pos = line.find(delimiter)) != string::npos) {

        token = line.substr(0, pos);

        partsOfString.push_back(token);

        line.erase(0, pos + delimiter.length());
    }
    // Last entry of string
    partsOfString.push_back(line);

    return partsOfString;
}





std::string vectorToString(const std::vector<std::string>& vec) {
    std::string result;

    for (const std::string& str : vec) {
        result += str;
    }

    return result;
}