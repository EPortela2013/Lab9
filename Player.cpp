#include "PLayer.h"

using namespace std;

Player::Player()
{
	//Initialize name to empty string and everything else to 0
	name = "";
	numWins = 0;
	numDraws = 0;
	numLosses = 0;
}


Player::Player(string givenName)
{
	//Initialize name to passed string and everything else to 0
	name = givenName;
	numWins = 0;
	numDraws = 0;
	numLosses = 0;
}

string Player::getRPSThrow() const
{
	//Generate random number between 0 and 3
	int choice = rand(time()) % 3;

	//Based on the random number, return the throw as string
	switch (choice)
	{
	case 0: return string("Rock");
	case 1: return string("Paper");
	case 2: return string("Scissors");
	}
}


double Player::getWinRecord() const
{
	//Calculate total number of fights by adding wins, losses, and draws
	int totalFights = numWins + numLosses + numDraws;

	//Return win record as double by dividing the number of wins by the total number of fights
	return 1.0 * numWins / totalFights * 100.00;
}

string Player::toString() const
{
	//Declare string stream that will temporarily hold player information
	ostringstream playerStringStream;

	//Concetanate all player information
	playerStringStream << "Player " << name << " has the following record: " << endl
		               << "Wins: " << numWins << endl
		               << "Losses: " << numLosses << endl
					   << "Draws: " << numDraws << endl
		               << "Win Record: " << fixed << precision(2) << getWinRecord() << endl;

	//Return concatenated information
	return playerStringStream.str();
}

void Player::setNumWins(int newNumWins)
{
	//Check if number is positive or 0, if negative return
	if (newNumWins < 0) return;

	//Update number of wins to passed number
	numWins = newNumWins;
}


void Player::setNumLosses(int newNumLosses)
{
	//Check if number is positive or 0, if negative return
	if (newNumLosses < 0) return;

	//Update number of losses to passed number
	numLosses = newNumLosses;

}


void Player::setNumDraws(int newNumDraws)
{
	//Check if number is positive or 0, if negative return
	if (newNumDraws < 0) return;

	//Update number of draws to passed number
	numDraws = newNumDraws;
}


void Player::increaseNumWins()
{
	//Increase number of wins by one
	numWins++;
}


void Player::increaseNumDraws()
{
	//Increase number of draws by one
	numDraws++;

}

void Player::increaseNumLosses()
{
	//Increase number of losses by one
	numLosses++;

}
