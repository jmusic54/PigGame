/*--------------------------------------------------
file: pig.h
by: J.Schladt
org: COP 2001, Spring 2020
for: Global configuration data for the pig game
--------------------------------------------------*/
#pragma once

#include <string>
using namespace std;

class Pig {
private:
	string playerName;		// name for a player

	int score;				// score for that respective player

public:
	//---------------------------------------
	// Constructors
	//---------------------------------------
	Pig();
	Pig(string pName);

	//---------------------------------------
	// Accessors
	//---------------------------------------
	string getName();
	void setName(string& playerName);
	int getScore();

	//---------------------------------------
	// Methods
	//---------------------------------------
	int roundScore(int rScore);
	string nameScore(int aScore);
};	// end class Pig