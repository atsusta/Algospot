#include <iostream>
#include <vector>

using namespace std;

int main() {

	int testCases = 0;
	vector<pair<int, int>> vertexes;
	vector<pair<int, int>> remainVertexes;
	
	cin >> testCases;

	// Get all vertexes that are 3 per test case
	for (int i = 0; i < testCases * 3; i++)
	{
		int vertex[2];
		for (int j = 0; j < 2; j++)
		{
			cin >> vertex[j];
		}

		vertexes.push_back(make_pair(vertex[0], vertex[1]));
	}

	int* x = new int[3];
	int* y = new int[3];
	int counter = 0;

	for (vector<pair<int, int>>::iterator i = vertexes.begin();
		i != vertexes.end();
		++i)
	{
		// Get vertexes
		x[counter] = i->first;
		y[counter] = i->second;
		
		counter++;
		if (counter > 2)
		{
			// If count is full, verify remain vertex
			int identicalX = 0;
			int identicalY = 0;

			if (x[0] == x[1])      identicalX = x[2];
			else if (x[0] == x[2]) identicalX = x[1];
			else if (x[1] == x[2]) identicalX = x[0];

			if (y[0] == y[1])      identicalY = y[2];
			else if (y[0] == y[2]) identicalY = y[1];
			else if (y[1] == y[2]) identicalY = y[0];

			// Save it to list
			remainVertexes.push_back(make_pair(identicalX, identicalY));

			// Reset arrays and counter to verify another vertex
			for (int i = 0; i < 3; i++) { x[i] = 0; y[i] = 0; }
			counter = 0;
		}
	}

	// Print out remain vertexes
	for (vector<pair<int, int>>::iterator i = remainVertexes.begin();
		i != remainVertexes.end();
		++i)
	{
		cout << i->first << " " << i->second << endl;
	}

	return 0;
}