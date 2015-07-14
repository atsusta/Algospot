#include <iostream>

using namespace std;

int main()
{
	int nBuildings = 0;
	int missionUsage = 0;
	int usage = 0;
	int sumOfUsages = 0;

	cin >> nBuildings;

	for (int i = 0; i < nBuildings; i++)
	{
		// Get mission usage
		cin >> missionUsage;

		for (int j = 0; j < 9; j++)
		{
			// Get usage by timestamp
			cin >> usage;

			// Add usage
			sumOfUsages += usage;
		}

		if (sumOfUsages <= missionUsage)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

		// Reset sum of usages
		sumOfUsages = 0;
		usage = 0;
	}

	return 0;
}
