#include <stdio.h>
#include <string.h>

int main()
{
	int nTestCases;
	char * brackets = NULL;
	int * depths = NULL;

	scanf("%d", &nTestCases);

	while (nTestCases--)
	{
		brackets = new char[10001];
		depths = new int[5001];
		for (int i = 0; i < 5001; i++)
		{
			depths[i] = 0;
		}

		scanf("%s", brackets);

		int bracketPosition = 0;
		int depthPosition = 0;

		// Verify brackets complete or not
		while (brackets[bracketPosition] != '\0')
		{
			// Search until string is finished
			switch (brackets[bracketPosition])
			{
			case '(':
				depths[depthPosition] = 1;
				depthPosition++;
				break;
			case '{':
				depths[depthPosition] = 2;
				depthPosition++;
				break;
			case '[':
				depths[depthPosition] = 3;
				depthPosition++;
				break;
			case ')':
				depthPosition--;
				depths[depthPosition] -= 1;
				break;
			case '}':
				depthPosition--;
				depths[depthPosition] -= 2;
				break;
			case ']':
				depthPosition--;
				depths[depthPosition] -= 3;
				break;
			}
			
			if (depths[depthPosition] != 0)
			{
				// Break loop when current bracket is verified as abnormaly closed
				break;
			}

			bracketPosition++;
		}

		if (depthPosition != 0)
		{
			// A bracket is abnormaly closed
			printf("NO\n");
		}
		else
		{
			// All brackets closed completely
			printf("YES\n");
		}

	}

	return 0;
}
