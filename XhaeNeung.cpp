#include <stdio.h>
#include <string.h>

int getOperand(char* token);
int computeAnswer(int firstOperand, int secondOperand, char op);
bool isRightAnswer(int answer, char* studentAnswer);

int main()
{
	int nToken = 0;
	int firstOperand = 0;
	int secondOperand = 0;
	int answer = 0;
	char token[10 + 1];
	char op;
	char studentAnswer[10 + 1];

	scanf("%d", &nToken);

	for (int i = 0; i < nToken; i++)
	{
		// Get first operator
		scanf("%s", token);
		firstOperand = getOperand(token);

		// Get operator
		scanf("%s", token);
		op = token[0];

		// Get second operand
		scanf("%s", token);
		secondOperand = getOperand(token);
		
		// Get student's answer
		scanf("%*s%s", token);
		sscanf(token, "%s", studentAnswer);

		// Compute actual answer
		answer = computeAnswer(firstOperand, secondOperand, op);
		
		// Compare answer between actual and student's
		if ((answer < 0) || (answer > 10))
		{
			printf("No\n");
		}
		else if (isRightAnswer(answer, studentAnswer))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

	return 0;
}

int getOperand(char* token)
{
	int operand = 0;

	if (memcmp("zero", token, 4) == 0)
		operand = 0;
	else if (memcmp("one", token, 3) == 0)
		operand = 1;
	else if (memcmp("two", token, 3) == 0)
		operand = 2;
	else if (memcmp("three", token, 5) == 0)
		operand = 3;
	else if (memcmp("four", token, 4) == 0)
		operand = 4;
	else if (memcmp("five", token, 4) == 0)
		operand = 5;
	else if (memcmp("six", token, 3) == 0)
		operand = 6;
	else if (memcmp("seven", token, 5) == 0)
		operand = 7;
	else if (memcmp("eight", token, 5) == 0)
		operand = 8;
	else if (memcmp("nine", token, 4) == 0)
		operand = 9;
	else if (memcmp("ten", token, 3) == 0)
		operand = 10;

	return operand;
}

int computeAnswer(int firstOperand, int secondOperand, char op)
{
	int answer = 0;

	switch (op)
	{
	case '+':
		answer = firstOperand + secondOperand;
		break;
	case '-':
		answer = firstOperand - secondOperand;
		break;
	case '*':
		answer = firstOperand * secondOperand;
		break;
	}

	return answer;
}

bool isRightAnswer(int answer, char* studentAnswer)
{
	bool isRight = false;
	char* found = NULL;

	// Verify student's answer
	switch (answer)
	{
	case 0:
		if ((strchr(studentAnswer, 'z') != NULL) &&
			(strchr(studentAnswer, 'e') != NULL) &&
			(strchr(studentAnswer, 'r') != NULL) &&
			(strchr(studentAnswer, 'o') != NULL))
			isRight = true;
		break;
	case 1:
		if ((strchr(studentAnswer, 'o') != NULL) &&
			(strchr(studentAnswer, 'n') != NULL) &&
			(strchr(studentAnswer, 'e') != NULL))
			isRight = true;
		break;
	case 2:
		if ((strchr(studentAnswer, 't') != NULL) &&
			(strchr(studentAnswer, 'w') != NULL) &&
			(strchr(studentAnswer, 'o') != NULL))
			isRight = true;
		break;
	case 3:
		if ((strchr(studentAnswer, 't') != NULL) &&
			(strchr(studentAnswer, 'h') != NULL) &&
			(strchr(studentAnswer, 'r') != NULL))
		{
			// Find 2 spellings
			found = strchr(studentAnswer, 'e');
			if (found != NULL)
			{
				found = strchr(found + 1, 'e');
			}

			if (found != NULL)
			{
				isRight = true;
			}
		}
		break;
	case 4:
		if ((strchr(studentAnswer, 'f') != NULL) &&
			(strchr(studentAnswer, 'o') != NULL) &&
			(strchr(studentAnswer, 'u') != NULL) &&
			(strchr(studentAnswer, 'r') != NULL))
			isRight = true;
		break;
	case 5:
		if ((strchr(studentAnswer, 'f') != NULL) &&
			(strchr(studentAnswer, 'i') != NULL) &&
			(strchr(studentAnswer, 'v') != NULL) &&
			(strchr(studentAnswer, 'e') != NULL))
			isRight = true;
		break;
	case 6:
		if ((strchr(studentAnswer, 's') != NULL) &&
			(strchr(studentAnswer, 'i') != NULL) &&
			(strchr(studentAnswer, 'x') != NULL))
			isRight = true;
		break;
	case 7:
		if ((strchr(studentAnswer, 's') != NULL) &&
			(strchr(studentAnswer, 'v') != NULL) &&
			(strchr(studentAnswer, 'n') != NULL))
		{
			// Find 2 spellings
			found = strchr(studentAnswer, 'e');
			if (found != NULL)
			{
				found = strchr(found + 1, 'e');
			}

			if (found != NULL)
			{
				isRight = true;
			}
		}
		break;
	case 8:
		if ((strchr(studentAnswer, 'e') != NULL) &&
			(strchr(studentAnswer, 'i') != NULL) &&
			(strchr(studentAnswer, 'g') != NULL) &&
			(strchr(studentAnswer, 'h') != NULL) &&
			(strchr(studentAnswer, 't') != NULL))
			isRight = true;
		break;
	case 9:
		if ((strchr(studentAnswer, 'i') != NULL) &&
			(strchr(studentAnswer, 'e') != NULL))
		{
			// Find 2 spellings
			found = strchr(studentAnswer, 'n');
			if (found != NULL)
			{
				found = strchr(found + 1, 'n');
			}

			if (found != NULL)
			{
				isRight = true;
			}
		}
		break;
	case 10:
		if ((strchr(studentAnswer, 't') != NULL) &&
			(strchr(studentAnswer, 'e') != NULL) &&
			(strchr(studentAnswer, 'n') != NULL))
			isRight = true;
		break;
	}

	return isRight;
}