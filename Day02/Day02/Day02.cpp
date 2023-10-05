// Day02.cpp : Defines the entry point for the application.
//

#include <string>
#include <filesystem>
#include <unordered_map>
#include <numeric>

#include "Day02.h"
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


const enum rps_modes {
	rock,
	paper,
	scissors
};



const std::unordered_map<std::string, rps_modes> modeTranslation = {
	{"A", rock},
	{"B", paper},
	{"C", scissors},
	{"X", rock},
	{"Y", paper},
	{"Z", scissors}
};


const std::unordered_map<rps_modes, int> score = {
	{rock, 1},
	{paper, 2},
	{scissors, 3}
};



const enum gameStates {
	win,
	lose,
	draw
};


const std::unordered_map<gameStates, int> gamePoints = {
	{win, 6},
	{lose, 0},
	{draw, 3}
};

const std::unordered_map<std::string, int> points = {
	{"AX", 4},
	{"AY", 8},
	{"AZ", 3},
	{"BX", 1},
	{"BY", 5},
	{"BZ", 9},
	{"CX", 7},
	{"CY", 2},
	{"CZ", 6}
};




int getWinnerState(rps_modes player1, rps_modes player2) 
{
	if (player1==rock &&  player2 == rock){ return 0; }
	if (player1==rock &&  player2== scissors){ return 1; }
	if (player1==rock &&  player2== paper){ return 2; }
	if (player1==scissors &&  player2== rock){ return 2; }
	if (player1==scissors &&  player2== scissors){ return 0; }
	if (player1==scissors &&  player2== paper){ return 1; }
	if (player1==paper &&  player2== rock){ return 1; }
	if (player1==paper &&  player2== scissors){ return 2; }
	if (player1 == paper && player2 == paper) { return 0; }
};

struct rps_input {
	string player1Input;
	string player2Input;
};


struct GameTable {
	vector<int> playerOneScore;
	vector<int> playerTwoScore;
};


int main()
{

	string filepath = "C://Users//WegewitzSte//Documents//000_Archiv//cpp//advent_of_Code22_cpp//Day02//Day02//input.txt";
	vector<string> fileLines;
	vector<string> scriptInput;
	vector<rps_input> inputs;

	GameTable gameTable;

	int sucess = readInputString(filepath, fileLines);
	int testscore = 0;
	int scoreSecondRound = 0;

	const std::unordered_map<std::string, int> secondRoundOutput = {
		{"AX", 0 + 3},
		{"AY", 3 + 1},
		{"AZ", 6 + 2},
		{"BX", 0 + 1},
		{"BY", 3 + 2},
		{"BZ", 6 + 3},
		{"CX", 0 + 2},
		{"CY", 3 + 3},
		{"CZ", 6 + 1}
	};

	for (int i = 0; i < fileLines.size(); i ++) {

		string line = fileLines[i];
		scriptInput.push_back(line);
		
		rps_input rpsInput;
		
		vector<string> gameInputs = splitStr(line," ");

		rps_input gameScores = { gameInputs[0], gameInputs[1] };


		rps_modes playerOneMode = modeTranslation.at(gameScores.player1Input);
		rps_modes playerTwoMode = modeTranslation.at(gameScores.player2Input);

		int scoreplayer1 = score.at(playerOneMode); 
		int scoreplayer2 = score.at(playerTwoMode);


		if (getWinnerState(playerOneMode, playerTwoMode)==1) {

			int winnerPoints = scoreplayer1 + gamePoints.at(win);
			int loserPoints = scoreplayer2 + gamePoints.at(lose);

			gameTable.playerOneScore.push_back(winnerPoints);
			gameTable.playerTwoScore.push_back(loserPoints);

		}
		else if (getWinnerState(playerOneMode, playerTwoMode) == 2) {

			int winnerPoints = scoreplayer2 + gamePoints.at(win);
			int loserPoints = scoreplayer1 + gamePoints.at(lose);

			gameTable.playerOneScore.push_back(loserPoints);
			gameTable.playerTwoScore.push_back(winnerPoints);

		}
		else {

			int playerPoints1 = scoreplayer1 + gamePoints.at(draw);
			int playerPoints2 = scoreplayer2 + gamePoints.at(draw);

			gameTable.playerOneScore.push_back(playerPoints1);
			gameTable.playerTwoScore.push_back(playerPoints1);

		}


		string test = vectorToString(gameInputs);
		int pointscore = points.at(test);

		testscore += pointscore;
		scoreSecondRound += secondRoundOutput.at(test);

	}

	std::cout << "finale scores" << endl;

	int sum1 = std::accumulate(gameTable.playerOneScore.begin(), gameTable.playerOneScore.end(), 0);
	int sum2 = std::accumulate(gameTable.playerTwoScore.begin(), gameTable.playerTwoScore.end(), 0);

	std::cout << "Player1: " << sum1 << endl;
	std::cout << "Player2: " << sum2 << endl;

	std:cout << "Player1 Fast: " << testscore << endl;
	cout << "SecondRound: " << scoreSecondRound << endl;

	return 0;
}
