#include "Player.h"
#include "Player.cpp"
#include <vector>
#include "helper_functions.h"

using namespace std;

int main()
{
	const int SAFE_CHOICE = 0;				//Constant used for resetting choice to a safe setting
	const int FIRST_VALID_CHOICE = 1;		//Constant for first valid menu choice
	const int LAST_VALID_CHOICE = 6;		//Constant for last valid menu choice
	const int QUIT_CHOICE = 6;				//Constant for choice to quit program
	int choice = SAFE_CHOICE;							//Will hold the choice user makes from the main menu


	vector<Player *> allPlayers;			//Contains pointers to all player objects
	vector<Player *> waitingPlayers;		//Contains pointers to players waiting for a match

	do
	{
		do
		{
			//Print menu
			cout << "1 - Show Players" << endl
				<< "2 - Add Player" << endl
				<< "3 - Add To Line-up" << endl
				<< "4 - Show Line-up" << endl
				<< "5 - Fight" << endl
				<< "6 - Quit" << endl;

			//Prompt user to make choice and store selection
			cout << endl << "What would you like to do? ";
			cin >> choice;

			//Check if invalid input was made
			if (cin.fail())
			{
				//If invvalid input, clear error and buffer
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				//Also reset choice to safe choice
				choice = SAFE_CHOICE;

			}

		} while (choice < FIRST_VALID_CHOICE || choice > LAST_VALID_CHOICE);  //Loop indefinitely until user makes a valid choice

		//Choose function according to user choice
		switch (choice)
		{
			//Show all players
		case 1:
			showAllPlayers(allPlayers);
			break;

			//Add player
		case 2:
			addPlayer(allPlayers);
			break;

			//Add player to line-up
		case 3:
			addPlayerToWaiting(allPlayers, waitingPlayers);
			break;

			//Show line-up
		case 4:
			showWaitingPlayers(waitingPlayers);
			break;

			//Fight
		case 5:
			fight(waitingPlayers);
			break;		
		}

	} while (choice != QUIT_CHOICE); //Loop indefinitely until user selects to quit

	//Terminating program, call function to deallocate memory allocated by all players vector
	deleteAllPlayers(allPlayers);

	return 0;
}



void showAllPlayers(const vector<Player *> &allPlayers)
{

}

void addPlayer(vector<Player *> &allPlayers)
{

}

void addPlayerToWaiting(const vector<Player *> &allPlayers, vector<Player *> &waitingPlayers)
{

}

void showWaitingPlayers(const vector<Player *> &waitingPlayers)
{

}

void fight(vector<Player *> waitingPlayers)
{

}


void deleteAllPlayers(vector<Player *> &allPlayers)
{
	//Get the vector size
	int vectorSize = allPlayers.size();

	//Loop through all the members of the players vector
	for (int i = 0; i < vectorSize; i++)
	{
		//Deallocate the space being pointed by current member
		delete allPlayers[i];

		//Set to null as a precaution
		allPlayers[i] = NULL;
	}
}