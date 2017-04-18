// Final Project
// Due date 12/9/14
// Professor Pinto: Advanced C
// Cameron Swift
// Do not distribute
// There is a readme.txt file that you can use for understanding how the code is commented

#include <stdio.h>
#include <stdlib.h>

// Header file ("create.h") that handles functions for generation of the game board
// Includes:
//			createClearBoard
//			redrawBoard
//			printX
//			printO
//			declareAllValues
//			redrawSingleSquare(Top, Middle and Bottom)
//			declareAllValues
// Also handles all of the storage of the game board states
//#include "create.h"

// Header file ("winAlg.h")
// Includes:
//			checkWinCondition(struct boardSquare *location)
//			fullBoardCheckWinCondition(struct boardSquare *fullBoard)
//#include "winAlg.h"

#define NULL 0

char next;
int move, locationNow, X;

struct boardSquare
{
	// Values for all locations in the board. 1=X owned and 2=O owned.
	int topLeft, topMiddle, topRight, middleLeft, middle, middleRight,
		bottomLeft, bottom, bottomRight;
	int winner; // if winner = 1, X is the winner, if = 2 O is the winner
};

void main()
{
struct boardSquare  ptopLeft, ptopMiddle, ptopRight, pmiddleLeft, pmiddle, pmiddleRight,
		pbottomLeft, pbottom, pbottomRight, pentireBoard;	
	// topLeft 		- topMiddle	 	- topRight
	// middleLeft 	- middle 		- middleRight
	// bottomLeft 	- bottom 		- bottomRight

// Calling all allocations of the variables for the board
//ptopLeft 			= calloc(1,sizeof(struct boardSquare));
//ptopMiddle		= calloc(1,sizeof(struct boardSquare));
//ptopRight 		= calloc(1,sizeof(struct boardSquare));
//pmiddleLeft		= calloc(1,sizeof(struct boardSquare));
//pmiddle 			= calloc(1,sizeof(struct boardSquare));
//pmiddleRight 		= calloc(1,sizeof(struct boardSquare));
//pbottomLeft 		= calloc(1,sizeof(struct boardSquare));
//pbottom 			= calloc(1,sizeof(struct boardSquare));
//pbottomRight 		= calloc(1,sizeof(struct boardSquare));
//pentireBoard		= calloc(1,sizeof(struct boardSquare));

	// Code for setting up values in the board variables
	declareAllValues(&ptopLeft);
	declareAllValues(&ptopMiddle);
	declareAllValues(&ptopRight);
	declareAllValues(&pmiddleLeft);
	declareAllValues(&pmiddle);
	declareAllValues(&pmiddleRight);
	declareAllValues(&pbottomLeft);
	declareAllValues(&pbottom);
	declareAllValues(&pbottomRight);
	declareAllValues(&pentireBoard);
	//----------------------------------------------------------------
	
	// Code for the introduction to the game
	printf("Welcome to Tic-Tac-Toe Advanced, where we will be playing a super advanced Tic-Tac-Toe game with 9 boards all wrapped into one giant one.");
	printf("\nBefore the game officially starts, we have to go over some symbols and controls. First, this is a two player game.\n");
	printf("Second, the following symbol is for the X on the board.\n\n");
	printX();
	printf("\nPress any character to go to the next step:");
	scanf("%d", &next);
	next = NULL;
	scanf("%*c"); //flush scanf

	printf("Next up is the O that will be placed on the board.\n\n");
	printY();
	printf("\nPress any character to go to the next step:");
	scanf("%d", &next);
	next = NULL;
	scanf("%*c"); //flush scanf

	printf("\nFinally, in order to choose which board you want to play on you're going to have to use the num pad (numbers 1 through 9)\n");
	printf("Keep in mind, since there are 9 boards inside of the large board, you're going to choose which smaller board to play in, and then which spot in the smaller board as well.\n");
	printf("If you don't like your choice of smaller board, you can always press 0 and exit back to the large board.\n");
	printf("ALRIGHT, NOW WE'RE READY TO PLAY!\n");
	//----------------------------------------------------------------
	
	// Board generation first call
	createClearBoard(); // Generates board for start of game.
	//----------------------------------------------------------------
	
	// Player 1 determines which of the smaller boards to start on
	printf("Now Player 1, which of the smaller boards do you want to move onto?");
	scanf("%d", &move);
	if (move == 1)
		// move is in the bottomLeft
		locationNow = 1;
	else if (move == 2)
		// move is in the bottom
		locationNow = 2;
	else if (move == 3)
		// move is in the bottomRight
		locationNow = 3;
	else if (move == 4)
		// move is in the middleLeft
		locationNow = 4;
	else if (move == 5)
		// move is in the middle
		locationNow = 5;
	else if (move == 6)
		// move is in the middleRight
		locationNow = 6;
	else if (move == 7)
		// move is in the topLeft
		locationNow = 7;
	else if (move == 8)
		// move is in the topMiddle
		locationNow = 8;
	else
		// move is in the topRight
		locationNow = 9;
	
	scanf("%*c"); //flush scanf
	//------------------------------------------------------------------
	
	// Start of the rest of the code for the game
	while(pentireBoard.winner == 0)
	{
		// Player 1 choosing where to go on the smaller board
		printf("Where do you want to move?");
		scanf("%d", &move);
		scanf("%*c"); //flush scanf
		//---------------------------------------------------
		
		// Finds larger square player chose and then plays onto the location in that square
		// Also sets up the next square the player gets to place his piece/play on
		// Note: Uses goto, and it's ugly as sin.
		spaghetti:
		X = 1;
		if (locationNow == 1)
		{
			if (pbottomLeft.winner == 1 || pbottomLeft.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti;
			}
			else
			{
			//printf("I got this far");
			changeVariable(&pbottomLeft, X, move);
			}
		}
		else if 	(locationNow == 2)
		{	
			if (pbottom.winner == 1 || pbottom.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti;
			}
			else
			{
			changeVariable(&pbottom, X, move);
			}
		}
		else if 	(locationNow == 3)
		{
			if (pbottomRight.winner == 1 || pbottomRight.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti;
			}
			else
			{
			changeVariable(&pbottomRight, X, move);
			}
		}
		else if 	(locationNow == 4)
		{
			if (pmiddleLeft.winner == 1 || pmiddleLeft.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti;
			}
			else
			{
			changeVariable(&pmiddleLeft, X, move);
			}
		}
		else if 	(locationNow == 5)
		{
			if (pmiddle.winner == 1 || pmiddle.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti;
			}
			else
			{
			changeVariable(&pmiddle, X, move);
			}
		}
		else if 	(locationNow == 6)
		{
			if (pbottomLeft.winner == 1 || pbottomLeft.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti;
			}
			else
			{
			changeVariable(&pmiddleRight, X, move);
			}
		}
		else if 	(locationNow == 7)
		{
			if (ptopLeft.winner == 1 || pbottomLeft.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti;
			}
			else
			{
			changeVariable(&ptopLeft, X, move);
			}
		}
		else if 	(locationNow == 8)
		{
			if (ptopMiddle.winner == 1 || ptopMiddle.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti;
			}
			else
			{
			changeVariable(&ptopMiddle, X, move);
			}
		}
		else
		{
			if (ptopRight.winner == 1 || ptopRight.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti;
			}
			else
			{
			changeVariable(&ptopRight, X, move);
			}
		}
		locationNow = move;
		//---------------------------------------------------------
		
		//system("clear");
		redrawBoard(&ptopLeft, &ptopMiddle, &ptopRight, &pmiddleLeft, &pmiddle, &pmiddleRight, &pbottomLeft, &pbottom, &pbottomRight);
		checkWinCondition(&pbottomLeft);
		checkWinCondition(&pbottom);
		checkWinCondition(&pbottomRight);
		checkWinCondition(&pmiddleLeft);
		checkWinCondition(&pmiddle);
		checkWinCondition(&pmiddleRight);
		checkWinCondition(&ptopLeft);
		checkWinCondition(&ptopMiddle);
		checkWinCondition(&ptopRight);
		fullBoardCheckWinCondition(&pentireBoard, &ptopLeft, &ptopMiddle, &ptopRight, &pmiddleLeft, &pmiddle, &pmiddleRight, &pbottomLeft, &pbottom, &pbottomRight);
		
		if (pentireBoard.winner != 0)
			break;
		
		// Player 2 choosing where to go on the smaller board
		printf("Player 2 your move! Where do you want to move?");
		scanf("%d", &move);
		scanf("%*c"); //flush scanf
		//---------------------------------------------------
		
		// Finds larger square player chose and then plays onto the location in that square
		// Also sets up the next square the player gets to place his piece/play on
		X = 2;
		spaghetti2:
		if (locationNow == 1)
		{
			if (pbottomLeft.winner == 1 || pbottomLeft.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti2;
			}
			else
			{
			changeVariable(&pbottomLeft, X, move);
			}
		}
		else if 	(locationNow == 2)
		{	
			if (pbottom.winner == 1 || pbottom.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti2;
			}
			else
			{
			changeVariable(&pbottom, X, move);
			}
		}
		else if 	(locationNow == 3)
		{
			if (pbottomRight.winner == 1 || pbottomRight.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti2;
			}
			else
			{
			changeVariable(&pbottomRight, X, move);
			}
		}
		else if 	(locationNow == 4)
		{
			if (pmiddleLeft.winner == 1 || pmiddleLeft.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti2;
			}
			else
			{
			changeVariable(&pmiddleLeft, X, move);
			}
		}
		else if 	(locationNow == 5)
		{
			if (pmiddle.winner == 1 || pmiddle.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti2;
			}
			else
			{
			changeVariable(&pmiddle, X, move);
			}
		}
		else if 	(locationNow == 6)
		{
			if (pbottomLeft.winner == 1 || pbottomLeft.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti2;
			}
			else
			{
			changeVariable(&pmiddleRight, X, move);
			}
		}
		else if 	(locationNow == 7)
		{
			if (ptopLeft.winner == 1 || pbottomLeft.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti2;
			}
			else
			{
			changeVariable(&ptopLeft, X, move);
			}
		}
		else if (locationNow == 8)
		{
			if (ptopMiddle.winner == 1 || ptopMiddle.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti2;
			}
			else
			{
			changeVariable(&ptopMiddle, X, move);
			}
		}
		else
		{
			if (ptopRight.winner == 1 || ptopRight.winner == 2)
			{
				printf("The other player has given you a free move! Choose the square you want to play on next.");
				scanf("%d", &locationNow);
				scanf("%*c"); //flush scanf
				goto spaghetti2;
			}
			else
			{
			changeVariable(&ptopRight, X, move);
			}
		}
		locationNow = move;
		//-----------------------------------------------------
		
		//system("clear");
		redrawBoard(&ptopLeft, &ptopMiddle, &ptopRight, &pmiddleLeft, &pmiddle, &pmiddleRight, &pbottomLeft, &pbottom, &pbottomRight);
		checkWinCondition(&pbottomLeft);
		checkWinCondition(&pbottom);
		checkWinCondition(&pbottomRight);
		checkWinCondition(&pmiddleLeft);
		checkWinCondition(&pmiddle);
		checkWinCondition(&pmiddleRight);
		checkWinCondition(&ptopLeft);
		checkWinCondition(&ptopMiddle);
		checkWinCondition(&ptopRight);
		fullBoardCheckWinCondition(&pentireBoard, &ptopLeft, &ptopMiddle, &ptopRight, &pmiddleLeft, &pmiddle, &pmiddleRight, &pbottomLeft, &pbottom, &pbottomRight);		

		if (pentireBoard.winner != 0)
			break;
	}
}	
		
		
		
		
		


// Changes the value of the location after a player chooses a square to move on
changeVariable(struct boardSquare *location, int X, int move)
{
	if (move == 1)
	{
		(*location).bottomLeft = X;
		//printf("Now it gets this far\n");
	}
	else if (move == 2)
		(*location).bottom = X;
	else if (move == 3)
		(*location).bottomRight = X;
	else if (move == 4)
		(*location).middleLeft = X;
	else if (move == 5)
		(*location).middle = X;
	else if (move == 6)
		(*location).middleRight = X;
	else if (move == 7)
		(*location).topLeft = X;
	else if (move == 8)
		(*location).topMiddle = X;
	else
		(*location).topRight = X;
}
//---------------------------------------------------------------------

/*
changeVariable(move, &locationNow, *location)
int move, &locationNow;
struct boardSquare *location;
{
	if (locationNow = 1)
		locationNow = 9;
	else if (locationNow = 2)
		locationNow = 8;
	else if (locationNow = 3)
		locationNow = 7;
	else if (locationNow = 4)
		locationNow = 6;
	else if (locationNow = 5)
		locationNow = 5;
	else if (locationNow = 6)
		locationNow = 4;
	else if (locationNow = 7)
		locationNow = 3;
	else if (locationNow = 8)
		locationNow = 2;
	else
		changeVariable(move, *topRight);
}*/


/*
		if locationNow = 0)
			printf("The other player has given you a free space! Which of the smaller boards would you like to move on?");
		if (locationNow = 1)
			changeVariable(move, &locationNow, *bottomLeft);
		else if (locationNow = 2)
			changeVariable(move,&locationNow, *bottom);
		else if (locationNow = 3)
			changeVariable(move,&locationNow, *bottomRight);
		else if (locationNow = 4)
			changeVariable(move,&locationNow, *middleLeft);
		else if (locationNow = 5)
			changeVariable(move,&locationNow, *middle);
		else if (locationNow = 6)
			changeVariable(move,&locationNow, *middleRight);
		else if (locationNow = 7)
			changeVariable(move,&locationNow, *topLeft);
		else if (locationNow = 8)
			changeVariable(move,&locationNow, *topMiddle);
		else
			changeVariable(move, *topRight);

		if ((*entireboard).winner = 1)
		{
			break;
		}
	
}*/


// Function that does individual win conditions based on struct 'location'
checkWinCondition(location)
struct boardSquare *location;
{
	// X winning across top of the board
	if (((*location).topLeft == 1) && ((*location).topMiddle == 1) && ((*location).topRight == 1)) 
		(*location).winner = 1;
	//--------------------------------------------------------------------------------------
	
	// Y winning across top of the board
	else if ((*location).topLeft == 2 && (*location).topMiddle == 2 && (*location).topRight == 2)
		(*location).winner = 2;
	//--------------------------------------------------------------------------------------
	
	// X winning across middle of the board
	else if ((*location).middleLeft == 1 && (*location).middle == 1 && (*location).middleRight == 1)
		(*location).winner = 1;
	//--------------------------------------------------------------------------------------
	
	// Y winning across middle of the board
	else if ((*location).middleLeft == 2 && (*location).middle == 2 && (*location).middleRight == 2)
		(*location).winner = 2;
	//--------------------------------------------------------------------------------------
		
	// X winning across the bottom of the board
	else if ((*location).bottomLeft == 1 && (*location).bottom == 1 && (*location).bottomRight == 1)
		(*location).winner = 1;
	//--------------------------------------------------------------------------------------
	
	// Y winning across the bottom of the board
	else if ((*location).bottomLeft == 2 && (*location).bottom == 2 && (*location).bottomRight == 2)
		(*location).winner = 2;
	//--------------------------------------------------------------------------------------
	
	// X winning diagonal right
	else if ((*location).topRight == 1 && (*location).middle == 1 && (*location).bottomRight == 1)
		(*location).winner = 1;
	//--------------------------------------------------------------------------------------
	
	// Y winning diagonal right
	else if ((*location).topRight == 2 && (*location).middle == 2 && (*location).bottomRight == 2)
		(*location).winner = 2;
	//--------------------------------------------------------------------------------------
	
	// X winning diagonal left
	else if ((*location).topRight == 1 && (*location).middle == 1 && (*location).bottomLeft == 1)
		(*location).winner = 1;
	//---------------------------------------------------------------------------------------
	
	// Y winning diagonal left
	else if ((*location).topRight == 2 && (*location).middle == 2 && (*location).bottomLeft == 2)
		(*location).winner = 2;
	//---------------------------------------------------------------------------------------
	
	// X winning left down
	else if ((*location).topLeft == 1 && (*location).middleLeft == 1 && (*location).bottomLeft == 1)
		(*location).winner = 1;
	//---------------------------------------------------------------------------------------
	
	// Y winning left down
	else if ((*location).topLeft == 2 && (*location).middleLeft == 2 && (*location).bottomLeft == 2)
		(*location).winner = 2;
	//---------------------------------------------------------------------------------------	
	
	// X winning middle down
	else if ((*location).topMiddle == 1 && (*location).middle == 1 && (*location).bottom == 1)
		(*location).winner = 1;
	//---------------------------------------------------------------------------------------
	
	// Y winning middle down
	else if ((*location).topMiddle == 2 && (*location).middle == 2 && (*location).bottom == 2)
		(*location).winner = 2;
	//---------------------------------------------------------------------------------------	
	
	// X winning right down
	else if ((*location).topRight == 1 && (*location).middleRight == 1 && (*location).bottomRight == 1)
		(*location).winner = 1;
	//---------------------------------------------------------------------------------------
	
	// Y winning right down
	else if ((*location).topRight == 2 && (*location).middleRight == 2 && (*location).bottomRight == 2)
		(*location).winner = 2;
	//---------------------------------------------------------------------------------------
}
//----------------------------------------------------

// Function that takes in the struct 'entireBoard' and determines the winner
fullBoardCheckWinCondition(fullBoard, ptopLeft, ptopMiddle, ptopRight, pmiddleLeft, pmiddle, pmiddleRight, pbottomLeft, pbottom, pbottomRight)
struct boardSquare (*fullBoard), (*ptopLeft), (*ptopMiddle), (*ptopRight), (*pmiddleLeft), (*pmiddle), (*pmiddleRight), (*pbottomLeft), (*pbottom), (*pbottomRight);
{
	(*fullBoard).topLeft 			= (*ptopLeft).winner;
	(*fullBoard).topMiddle  		= (*ptopMiddle).winner;
	(*fullBoard).topRight			= (*ptopRight).winner;
	(*fullBoard).middleLeft			= (*pmiddleLeft).winner;
	(*fullBoard).middle 			= (*pmiddle).winner;
	(*fullBoard).middleRight 		= (*pmiddleRight).winner;
	(*fullBoard).bottomLeft 		= (*pbottomLeft).winner;
	(*fullBoard).bottom 			= (*pbottom).winner;
	(*fullBoard).bottomRight 		= (*pbottomRight).winner;
	
	checkWinCondition(&fullBoard);

	if ((*fullBoard).winner == 1)
	{
		//system("clear");
		printf("Winner is X!");
	}
	else if ((*fullBoard).winner == 2)
	{
		//system("clear");
		printf("Winner is O!");
	}
}
//----------------------------------------------------------

declareAllValues(location)
struct boardSquare *location;
{
//struct boardSquare *location;

(*location).topLeft 		= 0;
(*location).topMiddle		= 0;
(*location).topRight 		= 0;
(*location).middleLeft 		= 0;
(*location).middle			= 0;
(*location).middleRight		= 0;
(*location).bottomLeft		= 0;
(*location).bottom			= 0;
(*location).bottomRight		= 0;
(*location).winner			= 0;
}


/*
declareAllValues(struct boardSquare *location) {
	(*location).topLeft 	= 0;
	(*location).topMiddle 	= 0;
	(*location).topRight 	= 0;
	(*location).middleLeft 	= 0;
	(*location).middle		= 0;
	(*location).middleRight	= 0;
	(*location).bottomLeft	= 0;
	(*location).bottom		= 0;
	(*location).bottomRight	= 0;
	(*location).winner		= 0;
}*/

// Creates the first clear board, can probably remove for redrawboard, but I like having two different functions for some reason
createClearBoard()
{

	printf(" | | || | | || | | \n-------------------\n | | || | | || | | \n-------------------\n | | || | | || | | \n-------------------\n-------------------\n | | || | | || | | \n-------------------\n | | || | | || | | \n-------------------\n | | || | | || | | \n-------------------\n-------------------\n | | || | | || | | \n-------------------\n | | || | | || | | \n-------------------\n | | || | | || | | \n");

}

// Prints a simple space with an X on the board
printX()
{
	printf("X|");
}
//-----------------------------------------------------------------------------------------------

// Prints a simple space with an O on the board
printY()
{
	printf("O|");
}
//------------------------------------------------------------------------------------------------

// Prints a simple empty space on the board
printSpace()
{
	printf(" |");
}
//------------------------------------------------------------------------------------------------

// Function that draws the board based on what the values are for (*location).winner.
redrawBoard(ptopLeft, ptopMiddle, ptopRight, pmiddleLeft, pmiddle, pmiddleRight, pbottomLeft, pbottom, pbottomRight)
struct boardSquare (*ptopLeft), (*ptopMiddle), (*ptopRight), (*pmiddleLeft), (*pmiddle), (*pmiddleRight), (*pbottomLeft), (*pbottom), (*pbottomRight);
{
	// Function(s) for drawing the first 3 squares
	redrawSingleSquareTop(&(*ptopLeft));
	printf("|");
	redrawSingleSquareTop(&(*ptopMiddle));
	printf("|");
	redrawSingleSquareTop(&(*ptopRight));
	printf("\n-------------------\n");
	redrawSingleSquareMiddle(&(*ptopLeft));
	printf("|");
	redrawSingleSquareMiddle(&(*ptopMiddle));
	printf("|");
	redrawSingleSquareMiddle(&(*ptopRight));
	printf("\n-------------------\n");
	redrawSingleSquareBottom(&(*ptopLeft));
	printf("|");
	redrawSingleSquareBottom(&(*ptopMiddle));
	printf("|");
	redrawSingleSquareBottom(&(*ptopRight));
	printf("\n-------------------\n-------------------\n");
	
	// Function(s) for drawing the next 3 squares
	redrawSingleSquareTop(&(*pmiddleLeft));
	printf("|");
	redrawSingleSquareTop(&(*pmiddle));
	printf("|");
	redrawSingleSquareTop(&(*pmiddleRight));
	printf("\n-------------------\n");
	redrawSingleSquareMiddle(&(*pmiddleLeft));
	printf("|");
	redrawSingleSquareMiddle(&(*pmiddle));
	printf("|");
	redrawSingleSquareMiddle(&(*pmiddleRight));
	printf("\n-------------------\n");
	redrawSingleSquareBottom(&(*pmiddleLeft));
	printf("|");
	redrawSingleSquareBottom(&(*pmiddle));
	printf("|");
	redrawSingleSquareBottom(&(*pmiddleRight));
	printf("\n-------------------\n-------------------\n");
	
	// Function(s) for drawing the final 3 squares
	redrawSingleSquareTop(&(*pbottomLeft));
	printf("|");
	redrawSingleSquareTop(&(*pbottom));
	printf("|");
	redrawSingleSquareTop(&(*pbottomRight));
	printf("\n-------------------\n");
	redrawSingleSquareMiddle(&(*pbottomLeft));
	printf("|");
	redrawSingleSquareMiddle(&(*pbottom));
	printf("|");
	redrawSingleSquareMiddle(&(*pbottomRight));
	printf("\n-------------------\n");
	redrawSingleSquareBottom(&(*pbottomLeft));
	printf("|");
	redrawSingleSquareBottom(&(*pbottom));
	printf("|");
	redrawSingleSquareBottom(&(*pbottomRight));
	printf("\n-------------------\n-------------------\n");
}

// Takes in the location and determines for the first 3 locations what should be drawn to board
redrawSingleSquareTop(location)
struct boardSquare (*location);
{
	if ((*location).topLeft == 0) {
		//printf("If it gets here this is interesting");
		printSpace(); }
	else if ((*location).topLeft == 1) {
		//printf("I hate C");
		printX(); }
	else
		printY();
	
	if ((*location).topMiddle == 0)
		printSpace();
	else if ((*location).topMiddle == 1)
		printX();
	else
		printY();
	
	if ((*location).topRight == 0)
		printSpace();
	else if ((*location).topRight == 1)
		printX();
	else
		printY();	
}

redrawSingleSquareMiddle(location)
struct boardSquare (*location);
{
	if ((*location).middleLeft == 0)
		printSpace();
	else if ((*location).middleLeft == 1)
		printX();
	else
		printY();
	
	if ((*location).middle == 0)
		printSpace();
	else if ((*location).middle == 1)
		printX();
	else
		printY();
	
	if ((*location).middleRight == 0)
		printSpace();
	else if ((*location).middleRight == 1)
		printX();
	else
		printY();	
}

redrawSingleSquareBottom(location)
struct boardSquare (*location);
{
	if ((*location).bottomLeft == 0)
		printSpace();
	else if ((*location).bottomLeft == 1)
		printX();
	else
		printY();
	
	if ((*location).bottom == 0)
		printSpace();
	else if ((*location).bottom == 1)
		printX();
	else
		printY();
	
	if ((*location).bottomRight == 0)
		printSpace();
	else if ((*location).bottomRight == 1)
		printX();
	else
		printY();	
}
//----------------------------------------------------------------------------------------
