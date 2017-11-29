#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

int main()
{
	int val;
	int n, m, i, j;
	int num[32][32];
	int handle[32][32];
	ifstream cin("test.txt");

	while (cin >> n >> m)
	{
		memset(num, 0, sizeof(num));
		memset(num, 0, sizeof(handle));
		//输入矩阵
		for (i = 1;i <= n;i++)
		{
			for (j = 1;j <= m;j++)
			{
				cin >> val;
				num[i][j] = handle[i][j] = val;
			}
		}

		//对每行进行处理
		for (i = 1;i <= n;i++)
			for (j = 1;j <= m - 2;j++)
				if (num[i][j] == num[i][j + 1] && num[i][j + 1] == num[i][j + 2])
					handle[i][j] = handle[i][j + 1] = handle[i][j + 2] = 0;
		//对每列进行处理
		for (i = 1;i <= m;i++)
			for (j = 1;j <= n - 2;j++)
				if (num[j][i] == num[j+1][i] && num[j+1][i] == num[j+2][i])
					handle[j][i] = handle[j + 1][i] = handle[j + 2][i] = 0;
		//消除后的输出
		for (i = 1;i <= n;i++)
		{
			for (j = 1;j < m;j++)
			{
				cout << handle[i][j] << " ";
			}
			cout << handle[i][m] << endl;
		}
	}

	return 0;
}
**************************************************************************/


//代码2
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 35;
int   grid[maxn][maxn], temp[maxn][maxn];
int   n, m;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> grid[i][j];

	for (int i = 0; i < n; ++i)
	{
		int cnt = 1;
		for (int j = 1; j < m; ++j)
		{
			if (grid[i][j] == grid[i][j - 1])
				cnt++;
			else cnt = 1;

			if (cnt >= 3)
			{
				for (int k = j; k > j - cnt; --k) 
					temp[i][k] = 1;
			}
		}
	}

	for (int j = 0; j < m; ++j)
	{
		int cnt = 1;
		for (int i = 1; i < n; ++i)
		{
			if (grid[i][j] == grid[i - 1][j]) cnt++;
			else cnt = 1;
			if (cnt >= 3)
			{
				for (int k = i; k > i - cnt; --k) temp[k][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (temp[i][j] == 1) cout << 0 << " ";
			else cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}


