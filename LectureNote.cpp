#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sort(int size, vector<string>& tokens);
void merge(vector<string>& firstPart, vector<string>& secondPart,
	vector<string>& target);

int main() {
	int nTestCases = 0;
	vector<string> words;
	vector<string> tokens;
	size_t position = 0;

	// Get number of test cases
	cin >> nTestCases;

	// Get user inputs iterated by number of test cases
	for (int i = 0; i < nTestCases; i++)
	{
		string aString;
		cin >> aString;
		words.push_back(aString);
	}

	for (vector<string>::iterator i = words.begin();
		i != words.end();
		++i)
	{
		// Divide the user inputs into substrings each length is 2
		int sizeOfSubset = i->size() / 2;
		if (sizeOfSubset % 2 != 0)
		{
			sizeOfSubset++;
		}

		// Clear list and position
		tokens.clear();
		position = 0;

		// Make subsets of stream
		for (int count = 0; count < sizeOfSubset; count++)
		{
			tokens.push_back(i->substr(position, 2));
			position += 2;
		}

		// Sort list
		sort(tokens.size(), tokens);

		// Print out sorted list
		for (int j = 0; j < tokens.size(); j++)
		{
			cout << tokens[j];
		}
		cout << endl;
	}
	
	return 0;
}

void sort(int size, vector<string>& target)
{
	if (size > 1)
	{
		// Initialize 2 parts
		vector<string> firstPart;
		vector<string> secondPart;
	
		// Get size of 2 parts
		int firstPartSize = size / 2;
		int secondPartSize = size - firstPartSize;
		
		// Divide target list into 2 parts
		for (int i = 0; i < firstPartSize; i++)
		{
			firstPart.push_back(target.at(i));
		}

		for (int i = firstPartSize; i < size; i++)
		{
			secondPart.push_back(target.at(i));
		}

		// Divide until only 2 elements are in part
		sort(firstPart.size(), firstPart);
		sort(secondPart.size(), secondPart);

		// Merge 2 parts into sorted list
		merge(firstPart, secondPart, target);
	}
}

void merge(vector<string>& firstPart, vector<string>& secondPart, 
	vector<string>& target)
{
	int firstPosition = 0;
	int secondPosition = 0;
	int targetPosition = 0;

	while ((firstPosition < firstPart.size()) &&
		(secondPosition < secondPart.size()))
	{
		// Copy element that is bigger than in the other one.
		if (firstPart.at(firstPosition) < secondPart.at(secondPosition))
		{
			target.at(targetPosition) = firstPart.at(firstPosition);
			firstPosition++;
		}
		else
		{
			target.at(targetPosition) = secondPart.at(secondPosition);
			secondPosition++;
		}
		targetPosition++;
	}

	// Copy all remainders into list to sort
	if (firstPosition >= firstPart.size())
	{
		for (int i = secondPosition; i < secondPart.size(); i++)
		{
			target.at(targetPosition) = secondPart.at(i);
			targetPosition++;
		}
	}
	else
	{
		for (int i = firstPosition; i < firstPart.size(); i++)
		{
			target.at(targetPosition) = firstPart.at(i);
			targetPosition++;
		}
	}
}