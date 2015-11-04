#include "Player.h"
#include "Player.cpp"
#include <vector>
#include "helper_functions.h"

using namespace std;

const int MINIMUM_NUM_PLAYERS = 2;				//Constant for minimum number of players required for a fight

int main()
{
	const int SAFE_CHOICE = 0;				//Constant used for resetting choice to a safe setting
	const int FIRST_VALID_CHOICE = 1;		//Constant for first valid menu choice
	const int LAST_VALID_CHOICE = 6;		//Constant for last valid menu choice
	const int QUIT_CHOICE = 6;				//Constant for choice to quit program
	const int NUM_CHARS_TO_IGNORE = 1;		//Constant for number of characters to ignore before next getline call
	int choice = SAFE_CHOICE;				//Will hold the choice user makes from the main menu



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
			cout << endl << "Please input a choice and hit enter: ";
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
		//Make sure pointer is not NULL. If usable, display player information
		if (allPlayers[i] != NULL) cout << endl << allPlayers[i]->toString() << endl;
	}

}

void addPlayer(vector<Player *> &allPlayers)
{
	string newName;		//Will hold the new player's name
		
	//Prompt user for the new player's name
	cout << endl << "Please input the new player's name and press enter: ";

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
	string playerName;		//Will hold the player's name
	int vectorSize = allPlayers.size();	//Will hold the vector size of the all players vector
	int indexFoundPlayer;				//Will hold the index of the player if found in the all players vector, -1 otherwise
	Player *foundPlayerPointer = NULL;			//Will hold the pointer to the found player instance

	//If there are no players to add to the waiting list, print message and return
	if (vectorSize == 0)
	{
		cout << endl << "There are no players in the player's list. Please add some." << endl << endl;
		return;
	}

	//Prompt user for the player's name
	cout << endl << "Please input the player's name and press enter: ";

	//Capture player's name
	getline(cin, playerName);

	//Get index for player
	indexFoundPlayer = findPlayer(allPlayers, playerName);


	//Check if name exists in all players vector
	if (indexFoundPlayer != -1)
	{
		//Player found

		//Store pointer of the found player
		foundPlayerPointer = allPlayers[indexFoundPlayer];

		//Add pointer at the end of the waiting players vector
		waitingPlayers.push_back(foundPlayerPointer);

		//Display success message
		cout << endl << "Player " << playerName << " successfully added to list to wait for a match" << endl << endl;
	}
	else
	{
		//Player not found

		//Display error message
		cout << endl << "Player " << playerName << " could not be found!" << endl << endl;
	}


}

void showWaitingPlayers(const vector<Player *> &waitingPlayers)
{
	int vectorSize = waitingPlayers.size();

	//Check if there are any players waiting
	if (vectorSize == 0)
	{
		//There are no players waiting, display message and return
		cout << endl << "There are no players waiting for a fight." << endl << endl;
		return;
	}

	//Display header
	if (vectorSize == 1) cout << endl << "There is 1 player waiting for a fight:" << endl;
	else cout << endl << "There are " << vectorSize << " players waiting for a fight:" << endl;

	//Loop through waiting players
	for (int i = 0; i < vectorSize; i++)
	{
		//Make sure pointer is not NULL. If usable, display player information
		if(waitingPlayers[i] != NULL) cout << endl << waitingPlayers[i]->toString() << endl;
	}
}

void fight(vector<Player *> &waitingPlayers)
{
	
	int vectorSize = waitingPlayers.size();			//Store size of waiting players vector
	Player *player1 = NULL;							//Will hold pointer to first player
	Player *player2 = NULL;							//Will hold pointer to second player

	//Check if there are enough players for a fight
	if (vectorSize < MINIMUM_NUM_PLAYERS)
	{
		//There are not enough players for a fight, display message and return
		cout << endl << "There are not enough players for a fight" << endl << endl;;
		return;
	}

	//Get the players that have been waiting the longest, index 0 and 1
	player1 = waitingPlayers[0];
	player2 = waitingPlayers[1];

	//Compare the two pointers
	if (player1 == player2)
	{
		//It is the same player

		//Make sure the pointer is not NULL before using
		if (player1 != NULL)
		{
			//Add draw to player
			player1->increaseNumDraws();

			//Display message
			cout << endl << "Player " << player1->getName() << " cannot fight against self! Draw added to record!" << endl << endl;
		}
	}
	else
	{
		//Two different players
		//Execute fight
		executeFight(player1, player2);
		
	}



	//Prepare vector for next round
	prepareForNextRound(waitingPlayers);


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
		//Check if pointer is usable, i.e. not NULL
		if (playerVector[i] != NULL)
		{
			//If the current player's name matches the name to find, return current index
			if (playerVector[i]->getName() == nameToFind) return i;
		}
	}

	//Looped through all players and did not find name, return -1

	return -1;
}

void executeFight(Player *player1, Player *player2)
{
	//Test to make neither pointer is NULL, if so don't continue, return
	if (player1 == NULL) return;
	if (player2 == NULL) return;

	//Get names for players and store them
	string player1Name = player1->getName();
	string player2Name = player2->getName();


	//Display message
	cout << endl << "Fight initiated between " << player1->getName() << " and " << player2->getName() << endl;

	//Get throws for each player and store them
	string throwPlayer1 = player1->getRPSThrow();
	string throwPlayer2 = player2->getRPSThrow();

	//Display each players throws
	cout << endl << player1->getName() << " throws " << throwPlayer1 << endl;


	cout << player2->getName() << " throws " << throwPlayer2 << endl;

	//Compare throws
	if (throwPlayer1 == throwPlayer2)
	{
		//It is a draw

		//Display message
		cout << endl << "It is a draw!" << endl << endl;

		//Add draw to both players
		player1->increaseNumDraws();
		player2->increaseNumDraws();

	}
	else
	{
		if (throwPlayer1 == "Rock")
		{
			//If player 1 threw "Rock", check player 2 throw
			if (throwPlayer2 == "Paper")
			{
				//Paper beats rock, player 2 wins
				//Display message
				cout << endl << player2Name << " wins!" << endl << endl;

				//Add win to player 2
				player2->increaseNumWins();

				//Add loss to player 1
				player1->increaseNumLosses();
			}
			else
			{
				//Player 2 did not draw rock nor paper, player 2 drew scissors

				//Rock beats scissors, player 1 wins
				//Display message
				cout << endl << player1Name << " wins!" << endl << endl;

				//Add win to player 1
				player1->increaseNumWins();

				//Add loss to player 2
				player2->increaseNumLosses();
			}
		}
		else
		{
			if (throwPlayer1 == "Paper")
			{
				//If player 1 threw "Paper", check player 2 throw
				if (throwPlayer2 == "Scissors")
				{
					//Scissors beats Paper, player 2 wins
					//Display message
					cout << endl << player2Name << " wins!" << endl << endl;

					//Add win to player 2
					player2->increaseNumWins();

					//Add loss to player 1
					player1->increaseNumLosses();
				}
				else
				{
					//Player 2 did not draw paper nor scissors, player 2 drew rock

					//Rock beats scissors, player 1 wins
					//Display message
					cout << endl << player1Name << " wins!" << endl << endl;

					//Add win to player 1
					player1->increaseNumWins();

					//Add loss to player 2
					player2->increaseNumLosses();

				}
			}
			else
			{
				//Player 1 drew Scissors
				//Check player 2 throw
				if (throwPlayer2 == "Rock")
				{
					//Rock beats Scissors, player 2 wins
					//Display message
					cout << endl << player2Name << " wins!" << endl << endl;

					//Add win to player 2
					player2->increaseNumWins();

					//Add loss to player 1
					player1->increaseNumLosses();
				}
				else
				{
					//Player 2 did not draw rock nor scissors, player 2 drew paper

					//Scissors beats paper, player 1 wins
					//Display message
					cout << endl << player1Name << " wins!" << endl << endl;

					//Add win to player 1
					player1->increaseNumWins();

					//Add loss to player 2
					player2->increaseNumLosses();

				}
			}

		}
	}
}


void prepareForNextRound(vector<Player *> &waitingPlayers)
{
	int vectorSize = waitingPlayers.size();			//Store the vector's  size
	vector<Player *> temp;							//Create a temporary vector that will hold the 
	
	if (vectorSize < MINIMUM_NUM_PLAYERS) return;

	//Holds the last index of the waiting player vector
	int lastIndex = vectorSize - 1;

	//Loop through the waiting player vector in backwards order, leaving the last two
	for (int i = lastIndex; i > 1; i--)
	{
		//Add current player to temporary vector
		temp.push_back(waitingPlayers[i]);

		//Remove current element from the vextor
		waitingPlayers.pop_back();
	}

	//Remove last remaining players in vector
	waitingPlayers.pop_back();
	waitingPlayers.pop_back();

	//Get last index for temp vector
	lastIndex = temp.size() - 1;

	//Loop through temporary player vector in backwards order
	for (int i = lastIndex; i >= 0; i--)
	{
		//Place current element in waiting player vector
		waitingPlayers.push_back(temp[i]);
	}

}