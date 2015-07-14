// Hamming Code 
// https://algospot.com/judge/problem/read/HAMMINGCODE
#include <iostream>

using namespace std;

int main()
{
	int nTestCases = 0;
	char receivedMessage[7 + 1];
	int* message = NULL;
	int* syndromeBits = NULL;

	cin >> nTestCases;

	while (nTestCases--)
	{
		scanf("%s", receivedMessage);

		// Get message as integer array format
		message = new int[7];
		for (int i = 0; i < 7; i++)
		{
			message[i] = receivedMessage[i] - '0';
		}

		// Get syndrome
		syndromeBits = new int[3];
		syndromeBits[0] = message[0] ^ message[2] ^ message[4] ^ message[6];
		syndromeBits[1] = message[1] ^ message[2] ^ message[5] ^ message[6];
		syndromeBits[2] = message[3] ^ message[4] ^ message[5] ^ message[6];

		int syndrome = (syndromeBits[2] << 2) | (syndromeBits[1] << 1) | 
			(syndromeBits[0]);

		// Apply syndrome to message
		if (syndrome > 0)
		{
			message[syndrome - 1] = message[syndrome - 1] ^ 1;
		}

		// Print out decoded message
		cout << message[2] << message[4] << message[5] << message[6] << endl;

	}


	return 0;
}