#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Player
{
public:
	/*
	* Default Constructor, initializes all variables to 0
	*/
	Player();


	/*
	* Initializes Player to given name and sets all other variables to 0
	* Parameter: givenName
	*         String of the player's name
	*/
	Player(string givenName);

	/*
	* getRPSThrow
	*
	* Randomizes selection of rock, paper, or scissors
	*
	* Return: Randomized "throw" of rock, paper, or scissors as string
	*/
	string getRPSThrow() const;

	/*
	* getWinRecord
	*
	* Calculates win record by diving the number of wins by the number of matches played
	*
	* Return: Value of win record as a double
	*/
	double getWinRecord() const;

	/*
	* toString
	*
	* Compiles all player information as a string
	*
	* Return: All player information as string
	*/
	string toString() const;

	/*
	* getName
	*
	* Returns player's name
	*
	* Return: Player's name as string
	*/
	string getName() const;

	/*
	* setNumWins
	*
	* Sets new number of wins
	* Param: int newNumWins
	*        New number of wins to store
	*/
	void setNumWins(int newNumWins);

	/*
	* setNumLosses
	*
	* Sets new number of Losses
	* Param: int newNumLosses
	*        New number of losses to store
	*/
	void setNumLosses(int newNumLosses);

	/*
	* setNumDraws
	*
	* Sets new number of Draws
	* Param: int newNumDraws
	*        New number of draws to store
	*/
	void setNumDraws(int newNumDraws);

	/*
	* increaseNumWins
	*
	* Increases number of wins by one
	*
	*/
	void increaseNumWins();

	/*
	* increaseNumDraws
	*
	* Increases number of draws by one
	*
	*/
	void increaseNumDraws();

	/*
	* increaseNumLosses
	*
	* Increases number of draws by one
	*
	*/
	void increaseNumLosses();

private:
	string name;	//Stores player name
	int numWins;	//Stores number of games won
	int numLosses;	//Stores number of games lost
	int numDraws;	//Stores number of games that ended in draw

};


#endif
