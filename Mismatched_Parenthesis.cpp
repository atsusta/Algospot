// Mismatched Parenthesis
// https://algospot.com/judge/problem/read/FIXPAREN
#include <stdio.h>
#include <stack>

using namespace std;

char getPair(char bracket);
int getPriority(char bracket, char brackets[]);

int main()
{
	int nTestCases = 0;
	stack<char> bracketStack;
	char * brackets;
	char * offsets;
	char * priority;

	scanf("%d", &nTestCases);

	while (nTestCases--)
	{
		// Initialize new arrays
		brackets = new char[100 + 1];
		offsets = new char[100 + 1];
		priority = new char[5 + 1];

		scanf("%s %s", brackets, priority);

		int position = 0;
		int offsetIndex = 0;

		// Search and verify
		while (brackets[position] != '\0')
		{
			switch (brackets[position])
			{
			case '(':
			case '{':
			case '<':
			case '[':
				// Push current bracket to stack
				bracketStack.push(brackets[position]);

				// Set offset of current bracket to result array
				offsets[offsetIndex] = position;
				offsetIndex++;
				break;
			case ')':
			case '}':
			case '>':
			case ']':
				offsetIndex--;
				char currentLeftPair = getPair(brackets[position]);
				
				if (getPriority(currentLeftPair, priority) <
					getPriority(bracketStack.top(), priority))
				{
					// Current right bracket is higher than left one
					// Change left bracket to pair of current bracket
					//printf("right is higher\n");
					brackets[offsets[offsetIndex]] = currentLeftPair;
				}
				else
				{
					// Former left bracket is higher or eqaul than current one
					// Change current bracket to pair of left bracket
					//printf("left is higher or equal\n");
					brackets[position] = getPair(brackets[offsets[offsetIndex]]);
				}
				
				// Remove offset from array and pop left bracket from stacks
				offsets[offsetIndex] = 0;
				bracketStack.pop();
				break;
			}

			position++;
		}

		// Print out result brackets
		for (int i = 0; i < position; i++)
		{
			printf("%c", brackets[i]);
		}
		printf("\n");

	}

	return 0;
}

char getPair(char bracket)
{
	switch (bracket)
	{
	case ')':
		return '(';
	case '}':
		return '{';
	case ']':
		return '[';
	case '>':
		return '<';
	case '(':
		return ')';
	case '{':
		return '}';
	case '[':
		return ']';
	case '<':
		return '>';
	}
}

int getPriority(char bracket, char priority[])
{
	int position = -1;

	// Find bracket from priority array and return priority
	while (priority[++position] != '\0')
	{
		if (priority[position] == bracket)
		{
			return position;
		}

	}

	return position;
}
