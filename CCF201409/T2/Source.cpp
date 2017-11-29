#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

int main()
{
	int n, i, j, k;
	int x1, y1, x2, y2;
	int rec[101][101];
	ifstream cin("test.txt");

	while (cin >> n)
	{
		int count = 0;
		//int min_x = 0, max_x = 100, min_y = 0, max_y = 100;
		memset(rec, 0, sizeof(rec));

		for (i = 0;i < n;i++)
		{
			cin >> x1 >> y1 >> x2 >> y2;

			for (j = x1;j < x2;j++)
			{
				for (k = y1;k < y2;k++)
				{
					rec[j][k] = 1;
				}
			}
		}

		for (i = 0;i <= 100;i++)
		{
			for (j = 0;j <= 100;j++)
			{
				if (rec[i][j] == 1)
					count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}