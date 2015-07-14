// Weekly Calendar
// https://algospot.com/judge/problem/read/WEEKLYCALENDAR
#include <stdio.h>
#include <string.h>

bool isCurrectWeekday(char * userWeekday, const char * weekday[],
	int weekdayOffset);
void createUserWeekdays(int month, int day, int weekdayOffset, int aWeek[]);

int main()
{
	int nTestCases = 0;
	int month;
	int day;
	int weekdayOffset;
	const char * weekday[] = { "Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday" };
	char * userWeekday = new char[10];
	int * aWeek = new int[7];

	scanf("%d", &nTestCases);

	while (nTestCases--)
	{
		// Prompt user for date
		scanf("%d %d %s", &month, &day, userWeekday);

		// Verify user's week
		for (int i = 0; i < 7; i++)
		{
			if (!memcmp(userWeekday, weekday[i], sizeof(i)))
			{
				weekdayOffset = i;
			}
		}

		// Create user's weekdays
		createUserWeekdays(month, day, weekdayOffset, aWeek);

		printf("%d %d %d %d %d %d %d\n", aWeek[0], aWeek[1], aWeek[2], aWeek[3],
			aWeek[4], aWeek[5], aWeek[6]);

	}

	return 0;
}

void createUserWeekdays(int month, int day, int weekdayOffset, int aWeek[])
{
	// Get first day
	int firstMonthday = day - weekdayOffset;

	for (int i = 0; i < 7; i++)
	{
		aWeek[i] = firstMonthday;

		switch (month)
		{
		case 1:
		case 8:
			// Month is January or August
			if (firstMonthday < 1)  aWeek[i] = firstMonthday + 31;
			if (firstMonthday > 31)	aWeek[i] = firstMonthday - 31;
			break;
		case 2:
			// Month is Febrary
			if (firstMonthday < 1)  aWeek[i] = firstMonthday + 31;
			if (firstMonthday > 28)	aWeek[i] = firstMonthday - 28;
			break;
		case 3:
			// Month is March
			if (firstMonthday < 1)  aWeek[i] = firstMonthday + 28;
			if (firstMonthday > 31)	aWeek[i] = firstMonthday - 31;
			break;
		case 5:
		case 7:
		case 10:
		case 12:
			// Month is May, July, October or December
			if (firstMonthday < 1)  aWeek[i] = firstMonthday + 30;
			if (firstMonthday > 31) aWeek[i] = firstMonthday - 31;
			break;
		default:
			// Month is April, June, September or November
			if (firstMonthday < 1)  aWeek[i] = firstMonthday + 31;
			if (firstMonthday > 30) aWeek[i] = firstMonthday - 30;
			break;
		}

		firstMonthday++;
	}

}
