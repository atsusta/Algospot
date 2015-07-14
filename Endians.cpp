#include <iostream>

using namespace std;

unsigned int* getBinaryExpression(
	unsigned int* arrayBuffer, unsigned int target);
void translateEndian(unsigned int* destination, unsigned int* source);

int main()
{
	int ntestCase = 0;

	// Number saving buffers
	unsigned int* originalNos;
	unsigned int* convertedNos;

	// Buffers for binary expression
	unsigned int* originalNoBuffer = new unsigned int[32];
	unsigned int* conversionBuffer = new unsigned int[32];
	
	for (int i = 0; i < 32; i++)
	{
		originalNoBuffer[i] = 0;
		conversionBuffer[i] = 0;
	}

	// Get number of test cases
	cin >> ntestCase;

	// Intialize buffers sizing by number of testCase
	originalNos = new unsigned int[ntestCase];
	convertedNos = new unsigned int[ntestCase];

	for (int i = 0; i < ntestCase; i++)
	{
		convertedNos[i] = 0;
	}

	// Save original numbers by user input
	for (int i = 0; i < ntestCase; i++)
	{
		cin >> originalNos[i];
	}

	// Compute original numbers to binary expression and convert them
	for (int i = 0; i < ntestCase; i++)
	{
		// Initialize buffers
		for (int j = 0; j < 32; j++)
		{
			originalNoBuffer[j] = 0;
			conversionBuffer[j] = 0;
		}

		// Get binary expression
		originalNoBuffer = getBinaryExpression(originalNoBuffer, 
			originalNos[i]);
		
		// Translate endian
		translateEndian(conversionBuffer, originalNoBuffer);
		
		// Compute translated expression to decimal number
		for (int l = 0; l < 32; l++)
		{
			unsigned int base = 1;
			
			// Get base
			for (int m = 0; m < l; m++)
			{
				base *= 2;
			}

			// Compute converted number
			convertedNos[i] += conversionBuffer[31 - l] * base;
		}
	}

	// Print out converted numbers
	for (int i = 0; i < ntestCase; i++) {
		cout << convertedNos[i] << endl;
	}

	return 0;
}

// Get binary expression
unsigned int* getBinaryExpression(unsigned int* arrayBuffer, unsigned int source)
{
	unsigned int quotient = source;

	for (int j = 31; j > -1; j--)
	{
		// Specify bit value (from LSB)
		arrayBuffer[j] = quotient % 2;

		// Prepare for specifying next bit (to MSB)
		quotient = (quotient - arrayBuffer[j]) / 2;

		if (quotient < 1)	break;
	}

	return arrayBuffer;
}

// Translate binary expression per 8-bit 
// from original buffer to converted number buffer
// original  : 24 25 26 27 28 29 30 31 / 16 17 18 19 20 21 22 23 / ...
// converted : 0  1  2  3  4  5  6  7  / 8  9  10 11 12 13 14 15 / ...
void translateEndian(unsigned int* destination, unsigned int* source)
{
	int bitIndexOffset = 0;

	for (int k = 0; k < 32; k++)
	{
		switch (k)
		{
		case 0:
			bitIndexOffset = 24;
			break;
		case 8:
			bitIndexOffset = 8;
			break;
		case 16:
			bitIndexOffset = -8;
			break;
		case 24:
			bitIndexOffset = -24;
			break;
		}

		destination[k] = source[k + bitIndexOffset];
	}
}
