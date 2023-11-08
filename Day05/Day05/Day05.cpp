// Day02.cpp : Defines the entry point for the application.
//

#include <string>
#include <filesystem>
#include <numeric>
#include <stdlib.h>
#include <ctype.h>
#include <map>

#include "Day05.h"
#include "utils.h"


using namespace std;


void part1() {

	string filepath = "C://Users//WegewitzSte//Documents//000_Archiv//cpp//advent_of_Code22_cpp//Day05//Day05//input.txt";
	vector<string> fileLines;
	vector<string> scriptInput;
	vector<int> idxOfCrates;


	int sucess = readInputString(filepath, fileLines);
	int finalscore = 0;
	int finalLineOfCrates = 0;

	std::map<int, vector<char>> crates;
	std::map<int, int> crateMapping;


	for (int j = 0; j < fileLines.size(); j++) {

		string line = fileLines[j];
		bool startlineEncounterd = false;

		for (int i = 0; i < line.size(); i++)
		{
			char c = line[i];

			if (isdigit(c))
			{	

				vector<char> vect;
				crates.insert(std::pair<int, vector<char>>( i, vect));
				crateMapping.insert(std::pair<int,int>(i, c));
				idxOfCrates.push_back(i);

				cout << c << "  Line " << i << endl;
				startlineEncounterd = true;
			}
		}

		if (startlineEncounterd == true) { 
			finalLineOfCrates = j;
			break; }
	}



	for (int j = 0; j < finalLineOfCrates ; j++) {

		string line = fileLines[j];

		for (int i = 0; i < line.size(); i++) {

			if (vectorContains(idxOfCrates, i)) {
				const char c = line[i];

				cout << c << " ad index " << i << endl;
				 
				if (c != ' ') {
					crates[i].push_back(c);
				}
				
				
			}
		}
	}


	cout << "--------" << endl;


	for (char d : crates[1]) {
		cout << d << endl;
	}


	cout << "Score: " << finalscore << endl;

}


int main()
{
	part1();
	return 0;
}
