﻿// Day02.cpp : Defines the entry point for the application.
//

#include <string>
#include <filesystem>
#include <unordered_map>
#include <numeric>

#include "Day03.h"
#include "utils.h"

using namespace std;


const std::unordered_map<char, int> scores =
{
	{'a', 1},
	{'b', 2 },
	{'c', 3 },
	{'d', 4 },
	{'e', 5 },
	{'f', 6 },
	{'g', 7 },
	{'h', 8 },
	{'i', 9 },
	{'j', 10 },
	{'k', 11 },
	{'l', 12 },
	{'m', 13 },
	{'n', 14},
	{'o', 15},
	{'p', 16},
	{'q', 17},
	{'r', 18},
	{'s', 19},
	{'t', 20},
	{'u', 21},
	{'v', 22},
	{'w', 23},
	{'x', 24},
	{'y', 25},
	{'z', 26},
	{'A' , 27},
	{'B' , 28 },
	{'C' , 29 },
	{'D' , 30 },
	{'E' , 31 },
	{'F' , 32 },
	{'G' , 33 },
	{'H' , 34 },
	{'I' , 35 },
	{'J' , 36 },
	{'K' , 37 },
	{'L' , 38 },
	{'M' , 39 },
	{'N' , 40 },
	{'O' , 41 },
	{'P' , 42 },
	{'Q' , 43 },
	{'R' , 44 },
	{'S' , 45 },
	{'T' , 46 },
	{'U' , 47 },
	{'V' , 48 },
	{'W' , 49 },
	{'X' , 50 },
	{'Y' , 51 },
	{'Z' , 52 },
};


void part1() {

	string filepath = "C://Users//WegewitzSte//Documents//000_Archiv//cpp//advent_of_Code22_cpp//Day03//Day03//input.txt";
	vector<string> fileLines;
	vector<string> scriptInput;


	int sucess = readInputString(filepath, fileLines);
	int finalscore = 0;

	for (int i = 0; i < fileLines.size(); i++) {

		string line = fileLines[i];
		scriptInput.push_back(line);
		int halfIndex = line.size() / 2;

		tuple<string, string> inpunts = splitStrAt(line, halfIndex);


		string rucksack1 = get<0>(inpunts);
		string rucksack2 = get<1>(inpunts);

		std:vector<char> foundChars;

		for (char currentChar : rucksack1) {

			bool contains = strContains(rucksack2, currentChar);
			if (contains == true && vectorContains<char>(foundChars, currentChar) == false)
			{
				foundChars.push_back(currentChar);
			}

			//std::cout << "Checks " << currentChar << " - " << contains << " " << endl;
		}

		int sum = 0;

		for (const char c : foundChars) {
			cout << "Found: " << c << endl;
			cout << "Converts: " << scores.at(c) << endl;
			sum += scores.at(c);
		}


		std::cout << "1: " << get<0>(inpunts) << std::endl;
		std::cout << "2: " << get<1>(inpunts) << std::endl;
		cout << "Score: " << sum << endl;

		finalscore += sum;
		//vector<string> gameInputs = splitStr(line," ");

	}

	cout << "Final score: " << finalscore;
}


int main()
{
	string filepath = "C://Users//WegewitzSte//Documents//000_Archiv//cpp//advent_of_Code22_cpp//Day03//Day03//inputPart2.txt";
	vector<string> fileLines;
	vector<string> scriptInput;


	int sucess = readInputString(filepath, fileLines);
	int finalscore = 0;
	int previousIdx = 0;
	

	for (int i = 0; i < fileLines.size(); i+= 6) {

		

		string elf  = fileLines[i] ;
		string elf2 = fileLines[i+1];
		string elf3 = fileLines[i+2];

		vector<char> foundChars;

		for (char currentChar : elf) {

			bool contains = strContains(elf2, currentChar);
			bool contains2 = strContains(elf3, currentChar);
			if (contains == true && contains2 == true && vectorContains<char>(foundChars, currentChar) == false)
			{
				foundChars.push_back(currentChar);
			}
		}

		
		string elf4  = fileLines[i+3] ;
		string elf5 = fileLines[i+4];
		string elf6 = fileLines[i+5];

		vector<char> foundChars2;

		for (char currentChar : elf4) {

			bool contains3 = strContains(elf5, currentChar);
			bool contains4= strContains(elf6, currentChar);
			if (contains3 == true && contains4 == true && vectorContains<char>(foundChars2, currentChar) == false)
			{
				foundChars2.push_back(currentChar);
			}
		}

		int score = 0;

		for (char c : foundChars) {

			score += scores.at(c);
			cout << "Found: " << c << endl;
			cout << "Found score: " << scores.at(c) << endl;
		}



		for (char c : foundChars2) {
			score += scores.at(c);
			cout << "Found2: " << c << endl;
			cout << "Found2 score: " << scores.at(c) << endl;
		}

		finalscore += score;


		cout << elf << endl;
		cout << elf2 << endl;
		cout << elf3 << endl;
		cout << elf4 << endl;
		cout << elf5 << endl;
		cout << elf6 << endl;
		cout << "---" << endl;
	}	

	cout << "Score: " << finalscore << endl;
	return 0;
}
