#include <iostream>
//#include <stdio.h>
//#include <string.h>

using namespace std;

char* encrypt(char* plainText);

const int MAX_SIZE = 100;

int main()
{
	int nTestCase = 0;
	char* plainText = NULL;
	char** cypherTexts = NULL;

	// Reserve plain text area
	plainText = new char[MAX_SIZE + 1];

	// Get number of test cases
	cin >> nTestCase;

	// Initialize row of 2d array
	cypherTexts = new char* [nTestCase];

	for (int i = 0; i < nTestCase; i++)
	{
		// Get user text
		scanf_s("%s", plainText, MAX_SIZE);
		//scanf("%s", plainText);

		// Encypt user text and set the string to each column(pointer)
		cypherTexts[i] = encrypt(plainText);
	}

	for (int i = 0; i < nTestCase; i++)
	{
		// Print out cypher texts
		// (Operate '<<' to char array goes to foreseen consequence)
		cout << cypherTexts[i] << endl;
	}

}

char* encrypt(char* plainText)
{
	// Get text size
	int size = strlen(plainText);

	// Reserve cypher text area
	char* cypherText = new char[size + 1];
	
	// Initialize cypher text string index
	int position = 0;

	// Encrypt text
	for (int i = 0; i < strlen(plainText) + 1; i += 2)
	{
		// Copy characters are in even position
		cypherText[position] = plainText[i];
			
		if (plainText[i] != '\0')
		{
			// Didn't meet null character
			position++;
		}
	}

	for (int i = 1; i < strlen(plainText) + 1; i += 2)
	{
		// Copy characters are in odd position
		cypherText[position] = plainText[i];
			
		if (plainText[i] != '\0')
		{
			// Didn't meet null character
			position++;
		}
	}

	// Null-terminate cypher text
	cypherText[position] = '\0';

	return cypherText;
}