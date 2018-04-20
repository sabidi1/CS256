/*
 * populaton.c
 *
 *  Created on: Apr 18, 2018
 *      Author: Zeeshan
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * displayBoard() function: takes the contents of the board and prints them on the screen.
 */
int displayBoard(char board[3][3]); // Intially
int displayBoard(char board[3][3]) // Placeholder for displayBoard
{
	//intilize counter
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		printf(" \n "); // Each row should end in a newline
		for (j = 0; j < 3; j++) // Go through each column
		{
			printf(" %c ", board[i][j]);
		}
	}

	return 0;
}

/*
 * input() function: gets input for either row number or column number and returns it
 */

int input(int number); 
int input(int number) // Placeholder for input()
{
	int row_or_column = 0; // Initialize
	char* string_to_print[7];
	if (number == 0)
	{
		*string_to_print = "row";
	}
	else if (number == 1)
	{
		*string_to_print = "column";
	}
	else {
		printf("\n Error. "); //invalid input
	}

	int valid = 0;
	while (valid == 0)
	{
		printf("\n Choose a %s ", *string_to_print); // Display prompt
		scanf("%d", &row_or_column); // Get input 
		if (1 <= row_or_column && row_or_column <= 3)
		{
			printf("\n You have chosen %s #%d. \n", *string_to_print, row_or_column);
			valid = 1;

		} else {
			printf("\n %s = %d \n", *string_to_print, row_or_column);
			printf("\n Invalid %s chosen, please try again.]", *string_to_print, *string_to_print);

		}
	}
	return row_or_column;
}

/*
 * winner() function:
 * Checks the board to see if there is winnner
 */
int winner(char board[3][3]);
int winner(char board[3][3])
{
	int winnerNumber = 0;
	int blankSpace = 0;
	int i = 0;
	int j = 0;
	//player 1 wins
	if (((board[0][0] == 'X') && (board[0][1] == 'X') && (board[0][2] == 'X')) || // first row
		((board[0][0] == 'X') && (board[1][0] == 'X') && (board[2][0] == 'X')) || // first column
		((board[0][0] == 'X') && (board[1][1] == 'X') && (board[2][2] == 'X')) || // diagonal 1
		((board[1][0] == 'X') && (board[1][1] == 'X') && (board[1][2] == 'X')) || // second row
		((board[2][0] == 'X') && (board[2][1] == 'X') && (board[2][2] == 'X')) || // third row
		((board[0][1] == 'X') && (board[1][1] == 'X') && (board[2][1] == 'X')) || // second column
		((board[0][2] == 'X') && (board[1][2] == 'X') && (board[2][2] == 'X')) || // third column
		((board[0][2] == 'X') && (board[1][1] == 'X') && (board[2][0] == 'X')) // diagonal 2
		)
	{
		winnerNumber = 1;
	//player 2 wins
	} else if (((board[0][0] == 'O') && (board[0][1] == 'O') && (board[0][2] == 'O')) || // first row
			   ((board[0][0] == 'O') && (board[1][0] == 'O') && (board[2][0] == 'O')) || // first column
			   ((board[0][0] == 'O') && (board[1][1] == 'O') && (board[2][2] == 'O')) || // diagonal 1
			   ((board[1][0] == 'O') && (board[1][1] == 'O') && (board[1][2] == 'O')) || // second row
			   ((board[2][0] == 'O') && (board[2][1] == 'O') && (board[2][2] == 'O')) || // third row
			   ((board[0][1] == 'O') && (board[1][1] == 'O') && (board[2][1] == 'O')) || // second column
			   ((board[0][2] == 'O') && (board[1][2] == 'O') && (board[2][2] == 'O')) || // third column
			   ((board[0][2] == 'O') && (board[1][1] == 'O') && (board[2][0] == 'O')) // diagonal 2
			   )
	{
		winnerNumber = 2;
	} else {
		for (i = 0; i < 3; i++) // iterate each row
		{
			for (j = 0; j < 3; j++) // iterate each column
			{
				if (board[i][j] == '_') {
					blankSpace = 1; // 1 = empty space
				}
			}
		}
		if (blankSpace == 0) { //no empty spaces
			winnerNumber = 3;	//player 3 wins = tie
		}
	}

	return winnerNumber;
}



int main (int argc, const char * argv[]) {

	int number = 0; 
	int player = 1; // Represent players as numbers
	int flag = 0; 
	
	char board[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}}; 
	
	int won = 0; // Initialize win condition 

	printf("\n Blank Tic-Tac-Toe board \n");
	displayBoard(board); // Show initial position of board (empty)
	while (won == 0) // Continue the game until a player wins
	{
		while (flag == 0) {
			printf("\n It is player #%i's turn. \n", player);
			int row = input(number); // Start game by getting row
			row--; // Decrement because the arrays actually go from 0 to 2, not 1 to 3
			number++; // get column instead of row
			int column = input(number); // Get column
			column--;

			if (player == 1 && board[row][column] == '_') {
				board[row][column] = 'X';
				flag = 1;
			} else if (player == 2 && board[row][column] == '_') {
				board[row][column] = 'O';
				flag = 2;
			} else if (board[row][column] == 'O') {
				printf("\n Space is taken by O. Please try again. \n");
			} else if (board[row][column] == 'X') {
				printf("\n Space is taken by X. Please try again. \n");
			} else {
				printf("Error");
				exit(1); 
			}
			
			number = 0; // Reset
		}
		
		printf("\n The board now looks like this: \n");
		displayBoard(board); // Update board
		won = winner(board); // Check for winner
	
		if (won == 1) { //return 1 if player 1 wins
			printf("\n Player 1 wins!");
		} else if (won == 2) { // return 2 if player 2 wins
			printf("\n Player 2 wins! ");
		} else if (won == 3) { // return 3 if it's a tie.
			printf("\n It's a tie :/" );
		} else {
		    //Reset variables
			flag = 0; 
			won = 0;  
		}
		if (player == 1) { // Switch players
			player = 2; 
		} else if (player == 2) {
			player = 1;
		} else {
			printf("Error"); 
		}
	}
    return 0;
}

// newline \n
