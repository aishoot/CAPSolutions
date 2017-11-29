#include <iostream>
#include <memory.h>
#include <fstream>
using namespace std;

int max(int a, int b)
{
	return a>b ? a : b;
}

int main()
{
	int n;  //原矩阵的行，现在矩阵的列
	int m;  //原矩阵的列，现在矩阵的行
	int i, j;
	int num;
	int max_num;
	//int matrix[1001][1001];
	ifstream cin("test.txt");

	while (cin>>n>>m)
	{
		max_num = max(n, m);
		int matrix[max_num + 1][max_num + 1];
		memset(matrix, 0, sizeof(matrix));

		for (i = 1;i <= n;i++)
		{
			for (j = 1;j <= m;j++)
			{
				//cin >> num;
				cin >> matrix[m + 1 - j][i];
			}
		}

		for (i = 1;i <= m;i++)
		{
			for (j = 1;j < n;j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << matrix[i][n] << endl;
		}

	}

	return 0;
}