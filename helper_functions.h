#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

using namespace std;

/*
*showAllPlayers
*
* Lists all the players in the game with their respective names, wins, losses, draws, and winning record
*
*Parameter: Vector containing pointers to all players in the game
*/
void showAllPlayers(const vector<Player *> &allPlayers);

/*
*addPlayer
*
* Prompts user for player name and adds it to the passed Player vector if Player doesn't already exist
*
*Parameter: Vector containing pointers to all players in the game
*/
void addPlayer(vector<Player *> &allPlayers);

/*
*addPlayerToWaiting
*
* Prompts user for player name and adds it to the waiting
*
*Parameter: Vector containing pointers to all players in the game
*Parameter: Vector containing pointers to players waiting for a fight
*/
void addPlayerToWaiting(const vector<Player *> &allPlayers, vector<Player *> &waitingPlayers);

/*
*showWaitingPlayers
*
* Lists the names of all the players waiting to compete
*
*Parameter: Vector containing pointers to all players in the game
*/
void showWaitingPlayers(const vector<Player *> &waitingPlayers);

/*
*fight
*
* Emulates a fight between the two players that have been waiting the longest, updates their record accordingly
* and removes them from the queue
*
*Parameter: Vector containing pointers to all players in the game
*/
void fight(vector<Player *> &waitingPlayers);


/*
*deleteAllPlayers
*
* Deletes all players in the vector list
*
*Parameter: Vector containing pointers to all players in the game
*/
void deleteAllPlayers(vector<Player *> &allPlayers);


/*
*findPlayer
*
* Looks for player inside the given pointer array by using the player's name
*
*Parameter: Vector containing pointers to all players in the game
*Parameter: String containing name to find
*
* Return:  The index of the found player. -1 if player is not found in vector
*/
int findPlayer(const vector<Player *> &playerVector, const string &nameToFind);

/*
*executeFight
*
* Handles the logic for the fight, updates players records according to outcome, and displays results of the fight
*
*Parameter: Player pointer to first player in fight
*Parameter: Player pointer to second player in fight
*
*/
void executeFight(Player *player1, Player *player2);


/*
*prepareForNextRound
*
* Prepares waiting players vector for next round by removing the first two players of the vector
*
*Parameter: Vector containing pointers to the players waiting for a match
*
*/
void prepareForNextRound(vector<Player *> &waitingPlayers);


#endif