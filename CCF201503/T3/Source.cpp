/**********************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//�жϵ� m ���Ƿ������꣬���򷵻� 1�����򷵻� 0��
bool isLeapYear(int m)
{
	if (m % 4 != 0 || (m % 100 == 0 && m % 400 != 0)) return 0;  //��������
	else return 1;   // ������
}

int main()
{
	//year[0]��ʾ������������� year[1]��ʾ�����������
	int year[2] = { 365,366 };
	//month[0]��ʾ��������ÿ���µ������� month[1]��ʾ������ÿ���µ�������
	int month[2][12] = { 31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };

	int i, j, k;
	int a, b, c, year1, year2;
	ifstream cin("test.txt");

	while (cin >> a >> b >> c >> year1 >> year2)
	{
		int total = 0;  //�����a��1�յ�1850.1.1�������ܺ�
		int week1day;   //�����a��1�����ܼ�
		int TotaltoYear1 = 0;   //1850��year1ǰһ���������

		for (i = 1850;i < year1;i++)
		{
			TotaltoYear1 += year[isLeapYear(i)];
		}

		for (i = year1;i <= year2;i++)   //���ѭ��
		{
			total = TotaltoYear1;
			if (i > year1)
			{
				for(k=year1+1;k<=i;k++)
					total += year[isLeapYear(k - 1)];
			}

			for (j = 1;j < a;j++)   //�·�ѭ��
			{
				total += month[isLeapYear(i)][j];
			}
			//����������a��1�����ܼ�
			week1day = total % 7 + 2;

			int bCount = 0, weekday = week1day;
			int count_day = 1;    //�������˸���ʱ������1�յ���������ͷҲ��β
			if (weekday == c)  bCount++;  //����Ҫ�Ȱѵ�һ���ж���
			while (bCount != b || weekday != c)
			{
				weekday++;
				count_day++;
				//ע�⣬����������һ��Ҫ�ŵ������棬�����ǿ�ʼ�ŵ�������
				if (weekday > 7)  weekday %= 7;
				if (weekday == c)  bCount++;
			}

			//��������ļ����ж����
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





//�����ȫ��ȷ
#include <iostream>
#include <stdio.h>
using namespace std;

const int YEAR = 1850;
int flag = 0;   //����Ϊ��ȫ�ֱ���

//daysOfMonth[0][]��ʾƽ���·ݵ�����
//daysOfMonth[1][]��ʾ�����·ݵ�����
int daysOfMonth[2][13] =
{
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

//�ж��Ƿ�Ϊ����
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
	int dth;   //ÿ��һ�������ڼ�

	while (scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2) != EOF)
	{
		for (int i = y1; i <= y2; i++)
		{
			d1 = cmpDays(i, a);    //��1850��1��1����������
			dth = d1 % 7 + 2;      //��ǰa��1�������ڼ�
		//����a�µ�b����������c�ľ�������
		//�����ǰ���������cС��dth��ʾ����һ�ܵ�����cҪ����һ������

			if (c < dth)  count = 1;
			else  count = 2;
			d2 = 8 - dth + (b - count) * 7 + c;

			if (d2 <= daysOfMonth[flag][a])  printf("%d/%02d/%02d\n", i, a, d2);
			else  printf("none\n");
		}
	}

	return 0;
}
