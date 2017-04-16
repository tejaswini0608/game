/*
 * crossfireOperations.h
 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */

#ifndef CROSSFIREOPERATIONS_H_
#define CROSSFIREOPERATIONS_H_



#endif /* CROSSFIREOPERATIONS_H_ */

#define BOARD_SIZE 7
#define REQ_DISTANCE 3

/*
 * Definition of boolean types
 * This avoids using <stdbool.h>
 */
typedef int bool;
enum { false, true };

/*
 * The slot template
 */
struct slot{
	//row number
	int row;
	//column number
	int column;

	// adjacent left slot
	struct slot *left;
	// adjacent right slot
	struct slot *right;
	// adjacent up slot
	struct slot *up;
	// adjacent down slot
	struct slot *down;
	
}slot[6];

struct data
{
	char type[10];      //declaration of struct data to represent the players
	char name[10];
	int Smartness;     //characteristics of the players
	int Strength;
	int MagicSkills; 
	int Luck;
	int Dexterity;
	int Lifepoints;    

	        
};
struct data player[6];                   // declaration of struct data player 

struct slots      //declaration of the struct slot to represent the slots
{
	
	struct data *player;
	int type;
	char type_inwords[10];
	int playernum;
	int slot_location;
	char slot_name[20];
	int player_in_slot;
	
};
struct slots arrSlots[7][7];

void move(int row,int column,int i);
void newabilities(int row,int column,int i);
int remaining_players_fun(int remaining_players,int i);
void nearattack(int row,int column,int i,int attacked);
//int playercanattack(int row,int column,int i,int attacker);
void magic_attack(int row,int column,int i,int a);
	void after_near_attack(int i,int attacked);
	void after_dist_attack(int i,int attacked);


/*
 * FUNCTIONS PROTOTYPES
 */

/*
 * Functions getBoardSize and getDesiredElement
 * manage the interaction with the users
 */

//Asks the user to provide as input the size of the board

//Returns the size of the board
int getBoardSize();

//Asks the user to insert the row and the column of the element
//she wants to find given a board of size equal to maxsize

 
void createBoard(int boardSize, struct slot **upLeft, struct slot **upRight, struct slot **downLeft, struct slot **downRight);

/*
 * This function traverses the board to find a slot at a predefined
 * position (row, column)
 * Parameters:
 * 	row: the row in which the desired slot is located
 * 	column: the column in which the desired slot is located
 * 	initialSlot: the slot from which the slot search should start
 */
struct slot *  reachDesiredElement(int row, int column, struct slot * initialSlot);


/*
 * The recursive function that traverses the board to find the slots at a predefined
 * distance from the current slot and place them in foundSlots.
 * Parameters:
 * 	reqDist: the required distance from the starting slot
 * 	currDist: the distance of the current slot from the starting slot
 * 	currSlot: a pointer to the current slot that is traversed
 * 	foundSlots: the array of slots that are at a required distance from the starting slot
 * 	count: pointer to an integer representing the number of slots that are found to be at a required distance from the starting slot
 * 	explored: matrix indicating for each slot at row x and column y has been traversed (true) or not (false)
 */
void findSlots(int reqDist, int currDist,  struct slot * currSlot, struct slot * foundSlots, int * count,  bool explored[7][7]);
