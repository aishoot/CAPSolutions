/************************************************************************
#include <iostream>
#include <string>
#include <memory.h>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	bool flag;
	char c;
	char num[101][101];
	int i, j, m, n, q, k;
	int x, y, x1, y1, x2, y2;
	ifstream cin("test.txt");

	while (cin >> m >> n >> q)
	{
		memset(num, '.', sizeof(num));   //全部初始化为小数点
		for (k = 0;k < q;k++)
		{
			cin >> flag;
			if (flag == 0)
			{
				cin >> x1 >> y1 >> x2 >> y2;
				x1 = min(x1, x2);x2 = max(x1, x2);
				y1 = min(y1, y2);y2 = max(y1, y2);

				if (y1 == y2)  //如果纵坐标相等
				{
					for (i = x1;i <= x2;i++)
					{
						if (num[i][y1] == '|')
						{
							num[i][y1] = '+';
							continue;
						}
						num[i][y1] = '-';
					}
				}

				else if (x1 == x2)   //如果横坐标相等
				{
					for (j = y1;j <= y2;j++)
					{
						if (num[x1][j] == '-')
						{
							num[x1][j] = '+';
							continue;
						}
						num[x1][j] = '|';
					}
				}
			}

			else   //flag=1的时候
			{
				cin >> x >> y >> c;
				num[x][y] = c;
				//向四左上角扩散
				








			}


		}

		for (i = 0;i <m;i--)
		{
			for (j = 0;j < m-1;j++)
			{
				cout << num[i][j];
			}
			cout << num[i][m-1] << endl;
		}




	}



	return 0;
}
***************************************************************************/



/*************************代码1******************************
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MS(a,b) memset(a,b,sizeof(a))
int dir[4][2] = { 1,0,-1,0,0,1,0,-1 }, n, m, vis[200][200], v[200][200];
char mat[200][200];

void dfs(int i, int j, char s)
{
	int tx, ty, k;
	mat[i][j] = s;
	for (k = 0;k<4;k++)
	{
		tx = i + dir[k][0];
		ty = j + dir[k][1];
		if (tx<0 || tx >= m || ty<0 || ty >= n) continue;
		if (mat[tx][ty] == '-' || mat[tx][ty] == '|' || mat[tx][ty] == '+' || mat[tx][ty] == s)
			continue;
		dfs(tx, ty, s);
	}
}

int main()
{
	char s;
	int q, i, h, x1, y1, x2, y2, x, y, j, k, h1, h2;
	int vis[200][200], v[200][200];
	cin >> n >> m >> q;
	for (i = 0;i<m;i++)
		for (j = 0;j<n;j++)
			mat[i][j] = '.';
	for (i = 0;i<q;i++)
	{
		cin >> h;
		if (h == 1)
		{
			cin >> x >> y >> s;
			dfs(m - 1 - y, x, s);
		}
		else
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2)
			{
				h1 = max(m - 1 - y1, m - 1 - y2);
				h2 = min(m - 1 - y1, m - 1 - y2);
				for (j = h2;j <= h1;j++)
				{
					if (mat[j][x1] == '.' || mat[j][x1] == '|' || mat[j][x1] == 'A'&&mat[j][x1] >= 'Z' || mat[j][x1] == 'a'&&mat[j][x1] == 'z')
						mat[j][x1] = '|';
					else
						mat[j][x1] = '+';
				}
			}
			if (y1 == y2)
			{
				h1 = max(x1, x2);
				h2 = min(x1, x2);
				for (j = h2;j <= h1;j++)
				{
					if (mat[m - 1 - y1][j] == '.' || mat[m - 1 - y1][j] == '-' || mat[m - 1 - y1][j] >= 'A'&&mat[m - 1 - y1][j] <= 'Z' || mat[m - 1 - y1][j] >= 'a'&&mat[m - 1 - y1][j] <= 'z')
						mat[m - 1 - y1][j] = '-';
					else
						mat[m - 1 - y1][j] = '+';

				}

			}
		}
	}
	for (i = 0;i<m;i++)
	{
		for (j = 0;j<n;j++)
			cout << mat[i][j];
		cout << endl;
	}
	return 0;
}**********/



//代码2
#include <iostream>
#include <cstring>
#include <fstream>
#define N 100
using namespace std;
int hei, wid;
char graph[N][N];
bool vis[N][N];
int d_x[4] = { -1,1,0,0 };
int d_y[4] = { 0,0,-1,1 };

bool isTrue(int x, int y)
{
	if (x<0 || x >= hei || y<0 || y >= wid) return 0;
	if (graph[x][y] == '-' || graph[x][y] == '|' || graph[x][y] == '+') return 0;
	if (vis[x][y]) return 0;
	return 1;
}

void dfs(int x, int y, char c)
{
	vis[x][y] = 1;
	graph[x][y] = c;
	for (int i = 0;i<4;i++)
	{
		int tpx = x + d_x[i], tpy = y + d_y[i];
		if (isTrue(tpx, tpy))
			dfs(tpx, tpy, c);
	}
}

int main()
{
	int n;
	ifstream cin("test.txt");
	cin >> wid >> hei >> n;
	memset(graph, '.', sizeof(graph));
	while (n--)
	{
		int op;
		cin >> op;
		//划线
		if (op == 0)
		{
			int x1, x2, y1, y2;
			cin >> y1 >> x1 >> y2 >> x2;
			if (x1>x2) swap(x1, x2);
			if (y1>y2) swap(y1, y2);
			//横线
			if (x1 == x2)
				for (int i = y1; i <= y2; i++)
					//这里先上来没有判断遇到+的情况，有些样例会覆盖掉+ 
					if (graph[x1][i] == '|' || graph[x1][i] == '+')
						graph[x1][i] = '+';
					else graph[x1][i] = '-';
					//竖线 
					if (y1 == y2)
						for (int i = x1; i <= x2; i++)
							if (graph[i][y1] == '-' || graph[i][y1] == '+')
								graph[i][y1] = '+';
							else graph[i][y1] = '|';
		}
		//填充
		if (op == 1)
		{
			int x, y;
			char c;
			cin >> y >> x >> c;
			dfs(x, y, c);
			//如果不加这句话，在下一次填充的话就不会有效果，以为vis没置零 
			memset(vis, 0, sizeof(vis));
		}
	}
	//记住一定要倒着输出
	for (int i = hei - 1;i >= 0;i--)
	{
		for (int j = 0;j <= wid - 1;j++)
			cout << graph[i][j];
		cout << endl;
	}
	return 0;
}