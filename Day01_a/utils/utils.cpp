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
