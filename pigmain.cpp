/*--------------------------------------------------
file: pigmain.cpp
by: J.Schladt
org: COP 2001, Spring 2020
for: Main application file for pig game
--------------------------------------------------*/
#include <iostream>
#include <time.h>	// time
#include <stdlib.h>	// srand, rand

#include "pig.h"

using namespace std;

const int MAX_PLAYERS = 6;
const int WINNING_SCORE = 100;
const string DASH_LINES = "----------------------------------------";

int main() {

	// initialize random numbers
	srand(time(NULL));

	// variables to be used in the game
	char playerAdd = 'Y';		// determines to add more players or to start game
	char holdChoice = 'Y';		// determines if player will hold or not
	string playerName;			// player name user enters
	int diceNumber;				// dice number that is rolled stored as an int
	int roundTotal = 0;			// score for each round
	int roundNumber = 0;		// number of each round
	int playerNumber = 1;		// order of each player
	bool gameOver = false;		// determines if game is being played or not
	bool holdStart = true;		// determines if player is in loop to hold score or not
	bool diceTime = true;		// determines if player is in dice rolling loop or not


	// initializing array to make player objects
	Pig pl[MAX_PLAYERS];

	// loop to add info to player objects, up to 5 players
	for (int i = 0; playerNumber < 6  && (playerAdd == 'Y' || playerAdd == 'y'); i++) {
		cout << "Enter name for player " << playerNumber << ": ";
		cin >> playerName;
		pl[i].setName(playerName);
		if (playerNumber < 5) {
			cout << "Add more players (Y/N)? ";
			cin >> playerAdd;
			cin.ignore();
		}
		else if (playerNumber == 5) {
			playerAdd = 'N';
		}
		playerNumber++;
		}

	// if statement to determine if the game can start
	if (playerAdd == 'N' || playerAdd == 'n') {
		gameOver = false;
	}

	// main game loop
	while (gameOver == false) {
		roundNumber++;
		cout << endl << DASH_LINES << endl;
		cout << "Starting Round " << roundNumber << endl;
		for (int i = 0; i < 5; i++) {
			cout << "Player " << i + 1 << ": " << pl[i].nameScore(pl[i].getScore()) << endl;
		}
		cout << endl << DASH_LINES << endl;

		// start player turn
		for (int i = 0; i < 5; i++) {
			holdStart = true;
			roundTotal = 0;
			cout << "Starting Turn for Player " << i + 1 << ": " << pl[i].nameScore(pl[i].getScore()) << endl;
			while (holdStart == true) {
				diceTime = true;
				while (diceTime == true) {
					diceNumber = rand() % 6 + 1;
					cout << "Dice=" << diceNumber << endl;

					// player rolled a one
					if (diceNumber == 1) {
						int ripScore = pl[i].getScore() * 0;
						pl[i].roundScore(roundTotal * 0);
						cout << "Ending Turn for Player " << i + 1 << ": " << pl[i].nameScore(ripScore) << endl;
						cout << DASH_LINES << endl << endl;
						holdStart = false;
						diceTime = false;
					}

					//player did not roll a one
					else {
						// increases score for the round per player
						roundTotal = roundTotal + diceNumber;
						cout << "Round Score=" << roundTotal << endl;

						// player wins the game
						int scorePlayer = (pl[i].getScore());
						while (scorePlayer > WINNING_SCORE) {
							cout << "Game Over!" << endl;
							cout << "The Winner is Player " << pl[i].nameScore(pl[i].getScore()) << endl;
							for (int i = 0; i < 5; i++) {
								cout << "Player " << i + 1 << ": " << pl[i].nameScore(pl[i].getScore()) << endl;
							}
							gameOver = true;
							holdStart = false;
							diceTime = false;
							scorePlayer = 0;
						}

						// player chooses to hold or not
						cout << "hold (Y/N)? ";
						cin >> holdChoice;
						if (holdChoice == 'Y' || holdChoice == 'y') {
							pl[i].roundScore(roundTotal);
							cout << "Ending Turn for Player " << i + 1 << ": " << pl[i].nameScore(pl[i].getScore()) << endl;
							cout << DASH_LINES << endl << endl;
							holdStart = false;
							diceTime = false;							
						
						}
						else {
							diceTime = false;

						}
					}
				}
				
			}
		}
		cout << endl << DASH_LINES << endl;
	}

	while (gameOver == true) {
		break;
	}

	return 0;
} //end main