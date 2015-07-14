#include <stdio.h>
#include <string.h>

double convertUnit(double originalValue, char* unit);

int main()
{
	int nDataSet = 0;
	double originalValue = 0.0;
	double convertedValue = 0.0;
	char unit[2 + 1];

	// Get number of data sets
	scanf_s("%d", &nDataSet);

	for (int i = 0; i < nDataSet; i++)
	{
		// Get original value and unit
		scanf_s("%lf %s", &originalValue, unit, 3);

		// Convert as forwarded unit
		convertedValue = convertUnit(originalValue, unit);

		// Print out converted value and unit
		printf("%d %.4lf %s\n", (i + 1), convertedValue, unit);
	}

	return 0;
}

double convertUnit(double originalValue, char* unit)
{
	double convertedValue = 0.0;

	if (strncmp(unit, "kg\0", sizeof(unit)) == 0)
	{
		// Kilogram to pound
		convertedValue = originalValue * 2.2046;
		strcpy_s(unit, 3, "lb");
	}
	else if (strncmp(unit, "lb\0", sizeof(unit)) == 0)
	{
		// Pound to kilogram
		convertedValue = originalValue * 0.4536;
		strcpy_s(unit, 3, "kg");
	}
	else if (strncmp(unit, "l\0", sizeof(unit)) == 0)
	{
		// Liter to gallon
		convertedValue = originalValue * 0.2642;
		strcpy_s(unit, 2, "g\0");
	}
	else if (strncmp(unit, "g\0", sizeof(unit)) == 0)
	{
		// Gallon to liter
		convertedValue = originalValue * 3.7854;
		strcpy_s(unit, 2, "l\0");
	}
	
	return convertedValue;
}