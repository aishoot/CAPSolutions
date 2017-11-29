/*********************************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const int maxn = 600;
int d[maxn][maxn], n;
const int dir[2][2] = { -1,1,1,-1 };

bool isIn(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	ifstream cin("test.txt");
	while (cin>>n)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> d[i][j];

		int m = n + n - 1;
		bool flag = true, o = false;

		for (int i = 0; i < m; ++i, flag = !flag)
		{
			for (int j = flag ? 0 : i; flag ? (j <= i) : (j >= 0); flag ? ++j : --j)
			{
				if ( isIn(i - j, j) )
				{
					if (o)  putchar(' ');
					printf("%d", d[i - j][j]);
					o = true;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
/***********************************************************************************/



/*********************************************************
//最开始的程序只得了30分，使用421ms，空间直接就用满了，256MB
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <memory.h>
using namespace std;

int main()
{
	int n, i, j;
	int matrix[501][501];
	ifstream cin("test.txt");

	while (cin>>n)
	{
		int sum = 2;

		memset(matrix, 0, sizeof(matrix));
		for (i = 1;i <= n;i++)
			for (j = 1;j <= n;j++)
				cin >> matrix[i][j];

		if (n == 1)
		{
			cout << matrix[1][1] << endl;
			continue;
		}

		for (i = 1;; i++)
		{
			if (i == sum)
			{
				i = 1;
				sum++;
			}

			if (sum > n + 1) break;

			if (sum % 2 == 1)   cout << matrix[i][sum - i] << " ";
			else   cout << matrix[sum - i][i] << " ";
		}

		for (i = n;; i--)
		{
			if ((sum-i) == (n+1))
			{
				i = n;
				sum++;
			}

			if (sum == 2*n ) break;

			if (sum % 2 == 0)   cout << matrix[i][sum - i] << " ";
			else   cout << matrix[sum - i][i] << " ";
		}

		cout << matrix[n][n] << endl;
	}

	return 0;
}
***********************************************************************/