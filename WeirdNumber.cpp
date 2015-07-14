#include <iostream>

using namespace std;

bool findSubset(int factor, int* divisors, int lastPosition);

int main()
{
	int nTestCase = 0;
	int no = 0;
	int maxDivisors = 0;
	int* divisors = NULL;

	cin >> nTestCase;

	while (nTestCase--)
	{
		cin >> no;
		
		// Initialize array of divisors
		maxDivisors = (no / 2) + 1;
		divisors = new int[maxDivisors];
		for (int i = 0; i < maxDivisors; i++)
		{
			divisors[i] = 0;
		}

		int position = 0;
		int sumOfDivisors = 0;
		bool isExceeded = false;
		bool hasSubset = false;

		// Get divisors
		for (int i = 1; i < maxDivisors; i++)
		{
			if (no % i == 0)
			{
				divisors[position] = i;
				position++;
			}
		}

		// Add all divisors
		for (int i = 0; i <= position; i++)
		{
			if (divisors > 0)
			{
				sumOfDivisors += divisors[i];
			}
		}

		if (sumOfDivisors > no)
		{
			isExceeded = true;

			// Define 'Factor' as substracted sum of divisors by the number
			int factor = sumOfDivisors - no;

			// Try making subset sums to the number
			hasSubset = findSubset(factor, divisors, position);
		}
		else
		{
			isExceeded = false;
		}

		// Print out result
		if (isExceeded && !hasSubset)
		{
			cout << "weird" << endl;
		}
		else
		{
			cout << "not weird" << endl;
		}

	}

	return 0;
}

bool findSubset(int factor, int* divisors, int lastPosition)
{
	bool isFactorZero = false;

	// Verify element of divisors can make factor
	// Substract factor from biggest divisor to smallest one
	// If factor becoms zero, the number has the subset!
	for (int i = lastPosition; i >= 0; i--)
	{
		if (factor - divisors[i] > 0)
		{
			factor -= divisors[i];
		}
		else if (factor - divisors[i] == 0)
		{
			isFactorZero = true;
		}
	}

	return isFactorZero;
}