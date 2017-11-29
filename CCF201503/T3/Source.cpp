/**********************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//判断第 m 年是否是闰年，是则返回 1，否则返回 0。
bool isLeapYear(int m)
{
	if (m % 4 != 0 || (m % 100 == 0 && m % 400 != 0)) return 0;  //不是闰年
	else return 1;   // 是闰年
}

int main()
{
	//year[0]表示非闰年的天数， year[1]表示闰年的天数。
	int year[2] = { 365,366 };
	//month[0]表示非闰年里每个月的天数， month[1]表示闰年里每个月的天数。
	int month[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };

	int i, j, k;
	int a, b, c, year1, year2;
	ifstream cin("test.txt");

	while (cin >> a >> b >> c >> year1 >> year2)
	{
		int total = 0;  //当年的a月1日到1850.1.1的天数总和
		int week1day;   //当年的a月1日是周几
		int TotaltoYear1 = 0;   //1850到year1前一年的总天数

		for (i = 1850;i < year1;i++)
		{
			TotaltoYear1 += year[isLeapYear(i)];
		}

		for (i = year1;i <= year2;i++)   //年份循环
		{
			total = TotaltoYear1;
			if (i > year1)
			{
				for(k=year1+1;k<=i;k++)
					total += year[isLeapYear(k - 1)];
			}

			for (j = 1;j < a;j++)   //月份循环
			{
				total += month[isLeapYear(i)][j];
			}
			//计算出当年的a月1日是周几
			week1day = total % 7 + 2;

			int bCount = 0, weekday = week1day;
			int count_day = 1;    //计数到了该天时到当月1日的天数，算头也算尾
			if (weekday == c)  bCount++;  //必须要先把第一天判断了
			while (bCount != b || weekday != c)
			{
				weekday++;
				count_day++;
				//注意，下面这两句一定要放到最下面，而不是开始放的最上面
				if (weekday > 7)  weekday %= 7;
				if (weekday == c)  bCount++;
			}

			//根据上面的计算判定输出
			if (count_day > month[isLeapYear(i)][a])
				cout << "none" << endl;
			else
			{
				cout << i << '/' << setw(2) << setfill('0') << a << '/' << setw(2) << setfill('0') << count_day << endl;
			}
		}
	}

	return 0;
}
*************************************************************************************************************/





//输出完全正确
#include <iostream>
#include <stdio.h>
using namespace std;

const int YEAR = 1850;
int flag = 0;   //定义为了全局变量

//daysOfMonth[0][]表示平年月份的天数
//daysOfMonth[1][]表示闰年月份的天数
int daysOfMonth[2][13] =
{
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

//判断是否为闰年
void judgeIsLeapYear(int year)
{
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))  flag = 1;
	else  flag = 0;
}

int cmpDays(int y, int m)
{
	int days = 0;
	for (int i = YEAR; i < y; i++)
	{
		judgeIsLeapYear(i);
		if (flag == 1)
			days += 366;
		else
			days += 365;
	}
	judgeIsLeapYear(y);
	for (int i = 1; i <= m; i++)
		days += daysOfMonth[flag][i - 1];
	return days;
}

int main()
{
	int a, b, c, y1, y2;
	int d1, d2;
	int count;
	int dth;   //每月一号是星期几

	while (scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2) != EOF)
	{
		for (int i = y1; i <= y2; i++)
		{
			d1 = cmpDays(i, a);    //与1850年1月1日相差的天数
			dth = d1 % 7 + 2;      //当前a月1号是星期几
		//计算a月第b个星期星期c的具体日期
		//如果当前输入的星期c小于dth表示，第一周的星期c要从下一周算起。

			if (c < dth)  count = 1;
			else  count = 2;
			d2 = 8 - dth + (b - count) * 7 + c;

			if (d2 <= daysOfMonth[flag][a])  printf("%d/%02d/%02d\n", i, a, d2);
			else  printf("none\n");
		}
	}

	return 0;
}
