// Day01_a.cpp : Defines the entry point for the application.
//

#include <string>
#include <filesystem>


#include "Day01_a.h"
#include "utils.h"

using namespace std;

// table for elfs. Each index equates to one elf
struct elfs {
	vector <vector<int>> caloriesPerFood;
	vector<int> calories;
	int size = 0;
};


void addToElfs(elfs &tableElfs, int sumOfCalroies, vector<int> caloriesPerFoodSingleElf) {
	tableElfs.calories.push_back(sumOfCalroies);
	tableElfs.caloriesPerFood.push_back(caloriesPerFoodSingleElf);
	tableElfs.size += 1;
}



int main()
{

	string filepath = "C://Users//WegewitzSte//Documents//000_Archiv//cpp//advent_of_Code22_cpp//Day01_a//Day01_a//input.txt";
	vector<string> fileLines;
	vector<string> scriptInput;

	int sucess = readInputString(filepath, fileLines);

	int sumOfCalroies = 0;
	vector<int> caloriesPerFoodSingleElf;
	elfs tableElfs;

	for (int i = 0; i < fileLines.size(); i ++) {
		string line = fileLines[i];
		scriptInput.push_back(line);

		if (line == "" || i == fileLines.size() ) {

			// Add data to table
			addToElfs(tableElfs, sumOfCalroies, caloriesPerFoodSingleElf);

			// Set to default
			sumOfCalroies = 0;
			caloriesPerFoodSingleElf.clear();
			continue; }
		
		// Store data of elf
		int currentcalorie = std::stoi(line);
		sumOfCalroies += currentcalorie;
		caloriesPerFoodSingleElf.push_back(currentcalorie);

	}
	// Add last elf to the table. Its saver to do it here again
	addToElfs(tableElfs, sumOfCalroies, caloriesPerFoodSingleElf);


	cout << "Input:" << endl;
	for (string line : scriptInput) {
		cout << line << endl;
	}
	for (int i = 0; i < tableElfs.size; i++) {
		cout << "Calories of Elf: " << std::to_string(tableElfs.calories[i]) << endl;
	}

	cout << "Max Elf:" << endl;
	vector<int>::iterator result;
	result = std::max_element(tableElfs.calories.begin(), tableElfs.calories.end());

	std::cout << "max element found at index "
		<< std::distance(tableElfs.calories.begin(), result)
		<< " has value " << *result << '\n';

	return 0;
}
