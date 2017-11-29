//找一棵树中距离最长的两个点之间的距离：
//思想：首先任取一个点，从该点出发，找到距离该初始点最远的一个点v，再从v出发，
//同样的方法找出从v开始的最长路径的点x，则v到x即为所求最长路径
#include <iostream>
#include <vector>
#include <fstream>
#include <memory.h>
using namespace std;
const int maxn = 20005;   //一直初始化为10001，错误50分
int vis[maxn];
int ma, s;

//int i;
vector <int> G[maxn];

void init()
{
	for (int i = 0;i<maxn;i++)
		G[i].clear();
}

void dfs(int u, int cost)
{
	vis[u] = 1; //是否通过
	if (ma<cost)
	{
		ma = cost; //记录最长路径距离
		s = u;  //记录最长距离的最后一个点
	}
	for (int i = 0;i<G[u].size();i++) //对U的每一个邻接点遍历
	{
		if (!vis[G[u][i]])  //若该邻接点未标记，则距离加1，继续递归调用
			dfs(G[u][i], cost + 1);
	}
}

int main()
{
	ifstream cin("test.txt");
	int n, m, x, i;
	cin >> n >> m;
	init();

	for (i = 2;i <= n + m;i++)
	{
		cin >> x;
		G[i].push_back(x);
		G[x].push_back(i);
	}

	ma = -1;  //每次调用dfs函数时，首先要对最大值初始化为-1，且vis初始化为0
	memset(vis, 0, sizeof(vis));
	dfs(1, 0);
	ma = -1;

	memset(vis, 0, sizeof(vis));
	dfs(s, 0);
	cout << ma << endl;
	return 0;
}




//BFS求解

/*******************************************************************************************
现有如下结论,主要是利用了反证法：

假设 s-t这条路径为树的直径，或者称为树上的最长路
    现有结论，从任意一点u出发搜到的最远的点一定是s、t中的一点，然后在从这个最远点开始搜，就可以搜到另一个最长路的端点，
即用两遍广搜就可以找出树的最长路

证明：
    1、设u为s-t路径上的一点，结论显然成立，否则设搜到的最远点为T则
dis(u,T) >dis(u,s)     且  dis(u,T)>dis(u,t)   则最长路不是s-t了，与假设矛盾

    2、设u不为s-t路径上的点
    首先明确，假如u走到了s-t路径上的一点，那么接下来的路径肯定都在s-t上了，而且终点为s或t，在1中已经证明过了

所以现在又有两种情况了：
    1：u走到了s-t路径上的某点，假设为X，最后肯定走到某个端点，假设是t ，则路径总长度为dis(u,X)+dis(X,t)
    2：u走到最远点的路径u-T与s-t无交点，则dis(u-T) >dis(u,X)+dis(X,t);显然，如果这个式子成立，
则dis(u,T)+dis(s,X)+dis(u,X)>dis(s,X)+dis(X,t)=dis(s,t)最长路不是s-t矛盾

    那我们就可以先用一遍BFS找到最长路径的一个端点，再用一遍BFS即可以求出最长路径
****************************************************************************************************

#include <iostream>  
#include <vector>  
#include <string.h>  
#include <queue>  
#define N 20005  
using namespace std;

int v[N];
int d[N];
vector<int> G[N];
queue<int> q;
int n, m, answer = 0, p;

void BFS(int st)
{
	int vis;
	memset(v, 0, sizeof(v));
	memset(d, 0, sizeof(d));
	q.push(st);
	v[st] = 1;

	while (!q.empty())
	{
		st = q.front();
		q.pop();
		for (int j = 0;j<G[st].size();j++)
		{
			vis = G[st][j];
			if (v[vis] == 0)
			{
				v[vis] = 1;
				d[vis] = d[st] + 1;
				q.push(vis);
				if (answer<d[vis])
				{
					answer = d[vis];
					p = vis;
				}
			}
		}
	}
}

int main()
{
	int x, sign = 1;
	cin >> n >> m;
	for (int i = 0;i<n - 1;i++)
	{
		cin >> x;
		G[x].push_back(++sign);
		G[sign].push_back(x);
	}

	for (int i = 0;i<m;i++)
	{
		cin >> x;
		G[x].push_back(++sign);
		G[sign].push_back(x);
	}

	BFS(1);
	BFS(p);
	cout << answer << endl;
	return 0;
}**/