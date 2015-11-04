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
	const int NUM_CHARS_TO_IGNORE = 1;		//Constant for number of characters to ignore before next getline call
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
			//Prepare input stream for getline call
			cin.ignore(NUM_CHARS_TO_IGNORE);

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
	int vectorSize = allPlayers.size();

	//If there are no players in the vector, print message and return
	if (vectorSize == 0)
	{
		cout << endl << "There are currently no players in the game. Please add some." << endl << endl;
		return;
	}

	//Display header
	if(vectorSize == 1)	cout << endl << "There is 1 player in the game: " << endl;
	else cout << endl << "There are " << vectorSize << " players in the game: " << endl;

	//Loop through all players in vector and print
	for (int i = 0; i < vectorSize; i++)
	{
		cout << endl << allPlayers[i]->toString() << endl;
	}

}

void addPlayer(vector<Player *> &allPlayers)
{
	string newName;		//Will hold the new player's name
		
	//Prompt user for the new player's name
	cout << endl << "Please enter the new player's name and press enter: ";

	//Capture player's name
	getline(cin, newName);

	//Check if player's name is in vector
	if (findPlayer(allPlayers, newName) == -1)
	{
		//Player not found in vector, create new player with given name
		Player *newPlayer = new Player(newName);

		//Add new player to player's vector
		allPlayers.push_back(newPlayer);

		//Display success message
		cout << endl << "Player " << newName << " has been successfully added to the player's list." << endl << endl;

	}
	else
	{
		cout << endl <<  "Player " << newName << " is already on the player's list." << endl << endl;
	}




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


int findPlayer(const vector<Player *> &playerVector, const string &nameToFind)
{
	//Store the vector size
	int vectorSize = playerVector.size();

	//Loop through the players
	for (int i = 0; i < vectorSize; i++)
	{
		//If the current player's name matches the name to find, return current index
		if (playerVector[i]->getName() == nameToFind) return i;
	}

	//Looped through all players and did not find name, return -1

	return -1;
}