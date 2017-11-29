//只有90分
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

bool isLeapYear(int year)   //是闰年返回1
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 400 != 0))
		return 1;
	else return 0;
}

//int DayOfYear[2] = { 365,366 };

int main()
{
	int i, j;
	int y, d;
	int DayOfMonth[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,
		                      31,29,31,30,31,30,31,31,30,31,30,31 };
	ifstream cin("test.txt");

	while (cin>>y>>d)
	{
		int month=1, day=d;
		while (day > DayOfMonth[isLeapYear(y)][month-1])
		{
			day -= DayOfMonth[isLeapYear(y)][month-1];
			month++;
		}

		cout << month << endl << day << endl;
	}

	return 0;
}


//代码2
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int y, d;
	while (scanf("%d %d", &y, &d) != EOF)
	{
		month[2] = 28;
		if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) month[2] = 29;

		int yue = 1;
		while (d > month[yue])
		{
			d -= month[yue];
			yue++;
		}
		printf("%d\n%d\n", yue, d);
	}
}