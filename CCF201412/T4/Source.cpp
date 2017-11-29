//*******************************对最小生成树的考察*************************************
/*******************************************
//201412-4
//最优灌溉  Kruskal
#include<iostream>  
#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;

#define LL long long int  
#define MAXEDGE 100005  
#define MAXNODE 1005  
int n, m;

struct Edge
{
	int a;
	int b;
	int c;
}e[MAXEDGE];

int parent[MAXNODE];

int cmp(const void* x, const void* y)
{
	return  ((Edge*)x)->c>((Edge*)y)->c ? 1 : -1;
}

int find_parent(int* parent, int f)
{
	while (parent[f]>0)
	{
		f = parent[f];
	}
	return f;
}

LL kruskal()
{
	LL ans = 0;
	int x, y;
	memset(parent, 0, sizeof(parent));

	for (int i = 0;i<m;i++)
	{
		x = find_parent(parent, e[i].a);
		y = find_parent(parent, e[i].b);
		if (x != y)
		{
			parent[x] = y;
			ans += e[i].c;
		}
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	for (int i = 0;i<m;i++)
	{
		cin >> e[i].a >> e[i].b >> e[i].c;
	}

	qsort(e, m, sizeof(e[0]), cmp);
	LL ans = kruskal();
	cout << ans << endl;
	return 0;
}
***************************************************/


//************************************************
//prim算法求解
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

#define MAX 1010
#define MAXX 10010

bool vis[MAX];
int dis[MAX];
int map[MAX][MAX];
int n, m;

void Prim()
{
	memset(vis, 0, sizeof(vis));
	int i, j, k = 0;
	for (i = 1;i <= n;i++)
		dis[i] = map[1][i];

	for (i = 1;i <= n;i++)
	{
		int temp = MAXX;
		for (j = 1;j <= n;j++)
		{
			if (!vis[j] && dis[j]<temp)
			{
				temp = dis[j];
				k = j;
			}
		}

		vis[k] = 1;
		for (j = 1;j <= n;j++)
		{
			if (!vis[j] && dis[j] > map[k][j])
				dis[j] = map[k][j];
		}
	}

	for (i = 2;i <= n;i++)
		dis[1] += dis[i];
	cout << dis[1] << endl;
}

int main()
{
	ifstream cin("test.txt");
	cin >> n >> m;
	int i, j;
	for (i = 0;i <= n;i++)
	{
		for (j = 0;j <= n;j++)
		{
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = MAXX;
		}
	}

	for (i = 0;i<m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = map[b][a] = c;
	}

	Prim();
	return 0;
}
/**************************************************/


/**************************************************
//并查集解法
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

struct node
{
	int x, y, cost;
}s[100005];

int tree[1005];

int find(int x)//找到根
{
	if (x != tree[x])
	{
		tree[x] = find(tree[x]);//如果不等于，就继续找
	}
	return tree[x];
}

bool cmp(node a, node b)
{
	return a.cost<b.cost;//价钱要最低，肯定让花费小的在前面
}

int main()
{
	int m, n, i;
	int sum;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 0;i<m;i++)
		{
			scanf("%d%d%d", &s[i].x, &s[i].y, &s[i].cost);
		}

		for (i = 0;i <= n;i++)
		{
			tree[i] = i;//先把每一个作为它自己的根
		}

		sort(s, s + m, cmp);
		sum = 0;
		int xx, yy;

		for (i = 0;i<m;i++)
		{
			xx = find(s[i].x);
			yy = find(s[i].y);
			if (xx != yy)//如果根不同，那么代表他俩不连通
			{
				tree[xx] = yy;//让其中一个变为另一个的根
				sum += s[i].cost;//修造渠道所花的钱
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
****************************************************************/


/************************************************************
//更牛逼的解法
#include<iostream>  
#include<algorithm>  
using namespace std;

struct List
{
	int a, b, v;
};

List l[100000];
int f[10001];

int find(int a)
{
	if (a != f[a])
		f[a] = find(f[a]);
	return f[a];
}

bool cmp(List x, List y)
{
	return x.v<y.v;
}

int main()
{
	int n, m, i, sum, a, b, num;
	while (cin >> n >> m)
	{
		sum = 0;num = 0;
		for (i = 0;i<m;i++)
			cin >> l[i].a >> l[i].b >> l[i].v;

		sort(l, l + m, cmp);

		for (i = 0;i<10001;i++)
			f[i] = i;

		for (i = 0;num<n - 1;i++)
		{
			a = l[i].a;
			b = l[i].b;
			a = find(a);
			b = find(b);

			if (a != b)
			{
				sum += l[i].v;
				num++;
				f[a] = b;
			}
		}

		cout << sum << endl;
	}
	return 0;
}
****************************************************************/