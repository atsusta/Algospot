// N-Queen
// https://algospot.com/judge/problem/read/NQUEEN
#include <stdio.h>

int main()
{
	int nTestCases = 0;
	int nQueen = 0;
	int** chessBoard = NULL;
	int firstQueenRow = 0;
	int firstQueenColumn = 0;

	scanf("%d", &nTestCases);

	while (nTestCases--)
	{
		scanf("%d", &nQueen);

		// Initialize N x N size chess board
		chessBoard = new int *[nQueen];
		for (int i = 0; i < nQueen; i++)
		{
			chessBoard[i] = new int[nQueen];
		}

		// Verify orthgonal positions
		placeQueen(0, nQueen, chessBoard);

	}

	return 0;
}

void placeQueen(int row, int boardSize, int ** chessBoard)
{
	// Try to place queen on each column
	for (int column = 0; column < boardSize; column++)
	{
		if (!canBeAttacked(row, column, boardSize, chessBoard))
		{
			// Current queen is placed in safe place, 
			// try another queen to next row
			chessBoard[row][column] = 1;
			placeQueen(row + 1, boardSize, chessBoard);
		}
	}

}

bool canBeAttacked(int row, int column, int boardSize, int** chessBoard)
{
    // Scan each column and find position of current queen
	for (int i = 0; i < column; i++)
	{
		if (i == column)
		{
			// Attaked in same column
			return true;
		}
			
		if ((i - chessBoard[row][i] == row - column) ||
			(i + chessBoard[row][i] == row + column))
		{
			// Attacked in diagonal
			return true;
		}
	}

	return false;
}

