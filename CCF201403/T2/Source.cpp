/************************************************************************
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <memory.h>
using namespace std;

int main()
{
	int N, M;
	int i, j, k, t;
	int x, y;
	int num;
	int result;
	ifstream cin("test.txt");

	while (cin >> N >> M)
	{
		int flag[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
		int loc[11][5];
		memset(loc, 0, sizeof(loc));

		for (i = 1;i <= N;i++)
		{
			for (j = 1;j <= 4;j++)
			{
				cin >> loc[i][j];
			}
		}

		for (i = 1;i <= M;i++)
		{
			cin >> x >> y;
			for (j = N;j >0;j--)
			{
				//ÕÒµ½¸Ãµã
				if (x >= loc[flag[j]][1] && x <= loc[flag[j]][3] && 
					y >= loc[flag[j]][2] && y <= loc[flag[j]][4])
				{
					num = flag[j];
					for (k = j;k < N;k++)
					{
						flag[k] = flag[k + 1];
					}

					if (j != N)
					{
						flag[N] = j;
					}
					
					cout << num << endl;
					break;
				}
			}

			if (j == 0)
			{
				cout << "IGNORED" << endl;
			}
		}
	}

	return 0;
}
********************************************************************************/


/**********************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;

struct window
{
	int x1;
	int y1;
	int x2;
	int y2;
	int id;
}w[12];

int main()
{
	//freopen("in.txt","r",stdin) ;
	int n, m;
	//scanf("%d %d", &n, &m);
	cin >> n >> m;
	int i, j;
	for (i = 1; i <= n; i++)
	{
		//scanf("%d%d%d%d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);
		cin >> w[i].x1 >> w[i].y1 >> w[i].x2 >> w[i].y2;
		w[i].id = i;
	}

	int x, y, num;
	while (m--)
	{
		//scanf("%d%d", &x, &y);
		cin >> x >> y;
		for (i = n; i >= 1; i--)
		{
			if (x >= w[i].x1 && x <= w[i].x2 && y >= w[i].y1 && y <= w[i].y2)
			{
				num = w[i].id;
				window temp = w[i];
				for (int k = i; k <= n; k++)
					w[k] = w[k + 1];
				w[n] = temp;
				break;
			}
		}

		if (i != 0)
			printf("%d\n", num);
		else
			printf("IGNORED\n");
	}

	return 0;
}



