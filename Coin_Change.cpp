// Coin Change
// https://algospot.com/judge/problem/read/COINS
#include <iostream>

using namespace std;

int getNcases(int change, int nUnits, int * unitCoins, int ** cases);

int main()
{
	int nTestCases = 0;
	int * unitCoins = NULL;
	int ** cases = NULL;

	cin >> nTestCases;

	while (nTestCases--)
	{
		// Change <= 5000
		int change = 0;

		// Number of unit coin <= 100
		int nUnits = 0;
		int nCases = 0;

		// Get target change and units
		cin >> change >> nUnits;

		// Get unit coins
		// Unit coin <= 5000
		unitCoins = new int[nUnits];
		for (int i = 0; i < nUnits; i++)
		{
			cin >> unitCoins[i];
		}

		// Initialize case 2d array
		cases = new int * [nUnits + 1];
		for (int i = 0; i < nUnits + 1; i++)
		{
			cases[i] = new int[change + 1];
		}

		// Verify all cases
		nCases = getNcases(change, nUnits, unitCoins, cases);
	
		cout << nCases << endl;

		// Free dynamic memories
		delete unitCoins;

		for (int i = 0; i < nUnits + 1; i++)
		{
			delete cases[i];
		}
		delete cases;

	}

	return 0;
}

int getNcases(int change, int nUnits, int * unitCoins, int ** cases)
{
	// Case that making 0 won by combining any coin is identical
	for (int i = 0; i < nUnits + 1; i++)
	{
		cases[i][0] = 1;
	}
	
	// Case that making any won by combining 0 coins is not possible
	for (int i = 0; i < change + 1; i++)
	{
		cases[0][i] = 0;
	}

	// For all unit coins
	for (int i = 1; i < nUnits + 1; i++)
	{
		// For all target change
		for (int j = 1; j < change + 1; j++)
		{
			if (j < unitCoins[i - 1])
			{
				cases[i][j] = cases[i - 1][j];
			}
			else
			{
				cases[i][j] = ( cases[i][j - unitCoins[i - 1]] + 
					cases[i - 1][j] ) % 1000000007;
			}
		}
	}

	// Test
	//for (int i = 0; i < nUnits + 1; i++)
	//{
	//	for (int j = 0; j < change + 1; j++)
	//	{
	//		cout << cases[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//return 0;

	return cases[nUnits][change];
}
