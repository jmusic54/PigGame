/*--------------------------------------------------
file: pig.cpp
by: J.Schladt
org: COP 2001, Spring 2020
for: Implementation file for a player class object
--------------------------------------------------*/
#include "pig.h"

//---------------------------------------
// Constructors
//---------------------------------------

/****************************************************
Default constructor for the player that sets the
name to an empty string and the score to zero
parameters:

returns:
****************************************************/
Pig::Pig() {
	playerName = "";	// the name the user enters for the player
	score = 0;			// the score for the player, automatically set to 0
}

/****************************************************
Constructor with string parameter and
score set to zero
parameters:

returns:
****************************************************/
Pig::Pig(string pName) {
	pName = "";			// the name the user enters for the player
	score = 0;			// the score for the player, automatically set to 0
}


//---------------------------------------
// Accessors
//---------------------------------------

/****************************************************
Returns the name the user entered for the player
parameters:
returns:
	String - player name
****************************************************/
string Pig::getName() {
	return playerName;
}


/****************************************************
Sets and stores the player name the user enters
parameters:
	playerName		- name user enters for player
returns:
****************************************************/
void Pig::setName(string& playerName) {
	this->playerName = playerName;
}

/****************************************************
Returns the name the user entered for the player
parameters:
returns:
	int - player score
****************************************************/
int Pig::getScore() {
	return score;
}

//---------------------------------------
// Methods
//---------------------------------------

/****************************************************
Takes the score for the round and adds it to the
players score attribute
parameters:
	rScore	-	score from the dice
returns:
	int		-	score for the round
****************************************************/

int Pig::roundScore(int rScore) {
	score = rScore + score;
	return score;
}

/****************************************************
Takes the players name and current score and 
returns them both as a formatted string
parameters:
	aScore	- score called
returns:
	String - player name and current score
****************************************************/

string Pig::nameScore(int aScore) {
	// returns name and score as a string
	return getName() + " Score= " + to_string(aScore);

}
