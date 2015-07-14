#include <iostream>
//#include <stdio.h>
//#include <string.h>

using namespace std;

const int MAX_SIZE = 80;

int main()
{
	int nTestCase = 0;
	int position = 0;
	char word[MAX_SIZE + 1];

	cin >> nTestCase;

	for (int i = 0; i < nTestCase; i++)
	{
		scanf_s("%d %s", &position, word, MAX_SIZE);
		// scanf("%d %s", position, word);

		cout << (i + 1) << " ";
			
		for (int j = 0; j < strlen(word); j++)
		{
			if (j != position - 1)
			{
				cout << word[j];
			}
		}

		cout << endl;
	}
	
	return 0;
}
