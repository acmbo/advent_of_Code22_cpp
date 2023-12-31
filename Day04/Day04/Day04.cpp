﻿// Day02.cpp : Defines the entry point for the application.
//

#include <string>
#include <filesystem>
#include <unordered_map>
#include <numeric>

#include "Day04.h"
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

	string filepath = "C://Users//WegewitzSte//Documents//000_Archiv//cpp//advent_of_Code22_cpp//Day04//Day04//input.txt";
	vector<string> fileLines;
	vector<string> scriptInput;


	int sucess = readInputString(filepath, fileLines);
	int finalscore = 0;



	for (int i = 0; i < fileLines.size(); i++) {

		string line = fileLines[i];

		auto inputs = splitStr(line, ",");

		vector<string> elf1 = splitStr(inputs.at(0), "-");
		vector<string> elf2 = splitStr(inputs.at(1), "-");



		if (
			((std::stoi(elf1.at(0)) <= std::stoi(elf2.at(0))) &&
				(std::stoi(elf2.at(0)) <= std::stoi(elf1.at(1))) &&
				(std::stoi(elf1.at(0)) <= std::stoi(elf2.at(1))) &&
				(std::stoi(elf2.at(1)) <= std::stoi(elf1.at(1)))) ||

			((std::stoi(elf2.at(0)) <= std::stoi(elf1.at(0))) &&
				(std::stoi(elf1.at(0)) <= std::stoi(elf2.at(1))) &&
				(std::stoi(elf2.at(0)) <= std::stoi(elf1.at(1))) &&
				(std::stoi(elf1.at(1)) <= std::stoi(elf2.at(1)))
				)
			)
		{
			cout << "found!" << endl;
			finalscore += 1;
		}

		cout << "---" << endl;


		scriptInput.push_back(line);
	}

	cout << "Score: " << finalscore << endl;

}


int main()
{
	string filepath = "C://Users//WegewitzSte//Documents//000_Archiv//cpp//advent_of_Code22_cpp//Day04//Day04//input.txt";
	vector<string> fileLines;
	vector<string> scriptInput;


	int sucess = readInputString(filepath, fileLines);
	int finalscore = 0;
	int finalscore2 = 0;
	

	for (int i = 0; i < fileLines.size(); i++) {

		string line = fileLines[i];

		auto inputs = splitStr(line, ",");

		vector<string> elf1 = splitStr(inputs.at(0), "-");
		vector<string> elf2 = splitStr(inputs.at(1), "-");

		vector<int> elf1Vals;
		vector<int> elf2Vals;


		for (int i = std::stoi(elf1.at(0)); i <= std::stoi(elf1.at(1)); i++) 
		{
			elf1Vals.push_back(i);
		}
		for (int i = std::stoi(elf2.at(0)); i <= std::stoi(elf2.at(1)); i++)
		{
			elf2Vals.push_back(i);
		}

		if (
		   ( ((std::stoi(elf1.at(0)) <= std::stoi(elf2.at(0))) &&
			 (std::stoi(elf2.at(0)) <= std::stoi(elf1.at(1)))) ||(
			 (std::stoi(elf1.at(0)) <= std::stoi(elf2.at(1))) &&
			 (std::stoi(elf2.at(1)) <= std::stoi(elf1.at(1))) )))
		{ 
			finalscore2 += 1;
			//cout << line << endl;
			//cout << "found" << endl;

			for (int i : elf2Vals) {

				if (vectorContains(elf1Vals, i)) {
					finalscore += 1;
				}

			}
		}
		else if (
			(((std::stoi(elf2.at(0)) <= std::stoi(elf1.at(0))) &&
			 (std::stoi(elf1.at(0)) <= std::stoi(elf2.at(1))) )||(
			 (std::stoi(elf2.at(0)) <= std::stoi(elf1.at(1))) &&
			 (std::stoi(elf1.at(1)) <= std::stoi(elf2.at(1))))
			))
		{
			finalscore2 += 1;
			//cout << line << endl;
			//cout << "found" << endl;
			for (int i : elf2Vals) {

				if (vectorContains(elf2Vals, i)) {
					finalscore += 1;
				}

			}
		
		}

 


		scriptInput.push_back(line);
	}	

	cout << "Score: " << finalscore << endl;
	cout << "overlapping assignment pairs: " << finalscore2 << endl;
	return 0;
}
