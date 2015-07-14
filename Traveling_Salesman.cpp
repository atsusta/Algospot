// Traveling Salesman Problem 1 
// https://algospot.com/judge/problem/read/TSP1
#include <stdio.h>
#include <algorithm>

double findShortestPath(int nCities, double ** weight);
double verifyPath(int nCities, double minLength, int * city, double ** weight);
double getMaxLength();

int main()
{
	int nTestCases;
	int nCities;
	double ** weight = NULL;

	scanf("%d", &nTestCases);

	while (nTestCases--)
	{
		scanf("%d", &nCities);

		// Initialize weight array
		weight = new double *[nCities];
		for (int i = 0; i < nCities; i++)
		{
			weight[i] = new double[nCities];
		}

		// Set distance values
		for (int i = 0; i < nCities; i++)
		{
			for (int j = 0; j < nCities; j++)
			{
				scanf("%lf", &weight[i][j]);
			}
		}

		// Get distance of shortest path
		printf("%.10lf\n", findShortestPath(nCities, weight));
	}

	return 0;
}

double findShortestPath(int nCities, double ** weight)
{
	// Initialize city number array
	int * city = new int[nCities];
	for (int i = 0; i < nCities; i++)
	{
		city[i] = i;
	}

	// Initialize minimum length value
	double minLength = getMaxLength();

	// Get Sequence of traveling cities and verify length of paths
	// This algorithm is NP-Complete
	minLength = verifyPath(nCities, minLength, city, weight);
	while (std::next_permutation(city, city + nCities))
	{
		minLength = verifyPath(nCities, minLength, city, weight);
	}

	// Test code
	//printf("Shortest Path : \n");
	//for (int i = 0; i < nCities; i++)
	//{
	//	printf("%d ", city[i]);
	//}
	//printf("\n");
	
	return minLength;
}

double verifyPath(int nCities, double minLength, int * city, double ** weight)
{
	double pathLength = 0.0;
	for (int i = 0; i < nCities - 1; i++)
	{
		pathLength += weight[city[i]][city[i + 1]];
	}

	if (minLength > pathLength)
	{
		minLength = pathLength;
	}

	return minLength;
}

double getMaxLength()
{
	return 1415 * 7;
}

//double travel(int nCities, double ** distances)
//{
//	double sum = 0.0;
//	double shortest = 0.0;
//
//	int i = 0;
//
//	// Find shortest value in current row and add to Sum
//	while (i < nCities)
//	{
//		int j = 0;
//		shortest = 0;
//
//		//printf("%.10lf or %.10lf", distances[i][j], distances[i][j]);
//		shortest = distances[i][j++];
//		//printf(" -> %.10lf\n", shortest);
//
//		while (j < i)
//		{
//			printf("%.10lf or %.10lf", shortest, distances[i][j]);
//			shortest = fmin(shortest, distances[i][j++]);
//			printf(" -> %.10lf\n", shortest);
//		}
//
//		sum += shortest;
//		//printf("sum : %.10lf\n", sum);
//
//		i++;
//	}
//
//	return sum;
//}
