/****************************代码1******************************
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

const int maxn = 10005;
int n, m;

int dfn[maxn];
int low[maxn];
int in_stack[maxn];
int col_num[maxn];
int vis[maxn];

vector<int> G[maxn];
stack<int> s;

int cur_time, color;
void tarjan(int u)
{
	dfn[u] = low[u] = ++cur_time;
	s.push(u);
	in_stack[u] = 1;
	vis[u] = 1;

	int d = G[u].size();
	for (int i = 0; i < d; i++)
	{
		int v = G[u][i];
		if (!vis[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (in_stack[v] == 1)
		{
			low[u] = min(low[u], dfn[v]);
		}
	}

	if (dfn[u] == low[u])
	{
		color++;
		int v;
		do {
			v = s.top();
			s.pop();
			in_stack[v] = 0;
			col_num[color] ++;
		} while (v != u);
	}
}

int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
		}

		while (!s.empty()) s.pop();
		memset(col_num, 0, sizeof(col_num));
		memset(in_stack, 0, sizeof(in_stack));
		memset(vis, 0, sizeof(vis));
		cur_time = 0, color = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i]) tarjan(i);
		}

		int ans = 0;
		for (int i = 1; i <= color; i++)
		{
			if (col_num[i] > 1)
			{
				int x = col_num[i];
				ans += (x * (x - 1) / 2);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}*****/



//代码2-先求强连通分量，再从各个元素大于1的强连通分量中选2个城市的组合，最后再相加，tarjan算法。
#include<iostream>  
#include<string.h>  
#include<algorithm>
using namespace std;

int n, m;
int head[10010], stackn[10010], DFN[10010], Low[10010];
int Belong[10010], instack[10010], cnt, top, f, scnt;

struct node
{
	int e, next;
}edge[100010];

void add(int s, int e)
{
	edge[f].e = e;
	edge[f].next = head[s];
	head[s] = f++;
}

void tarjan(int s)
{
	int t, k, i;
	DFN[s] = Low[s] = ++cnt;
	stackn[top++] = s;
	instack[s] = 1;
	for (i = head[s];i != -1;i = edge[i].next)
	{
		k = edge[i].e;
		if (!DFN[k])
		{
			tarjan(k);
			Low[s] = min(Low[k], Low[s]);
		}
		else if (instack[k])
		{
			Low[s] = min(Low[s], DFN[k]);
		}
	}
	if (Low[s] == DFN[s])
	{
		scnt++;
		do
		{
			t = stackn[--top];
			Belong[t] = scnt;
			instack[t] = 0;
		} while (s != t);
	}
}

int main()
{
	int i, j, a, b, v[10010];
	cin >> n >> m;
	f = 1;
	memset(head, -1, sizeof(head));
	memset(v, 0, sizeof(v));
	for (i = 0;i<m;i++)
	{
		cin >> a >> b;
		add(a, b);
	}
	memset(DFN, 0, sizeof(DFN));
	for (i = 1;i <= n;i++)
	{
		if (!DFN[i])
			tarjan(i);
	}
	for (i = 1;i <= n;i++)
		v[Belong[i]]++;
	long long sum = 0;
	for (i = 0;i <= n;i++)
	{
		if (v[i]>1)
			sum = sum + v[i] * (v[i] - 1) / 2;
	}
	cout << sum << endl;
	return 0;
}



//代码及分析3
//附链接：http://blog.csdn.net/lishuhuakai/article/details/50346129


//代码4-最简洁
#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 10005  
vector<int> g[MAXN];     //使用vector动态数组而不是静态数组，节省了很多空间
vector<int> component[MAXN];
int STACK[MAXN], TOP = 0;
bool instack[MAXN];
int dfn[MAXN];
int low[MAXN];
int index = 1;
int cnt = 0;

void tarjan(int x)
{
	dfn[x] = low[x] = index++;
	instack[x] = true;
	STACK[++TOP] = x;
	int j;

	for (int i = 0;i<g[x].size();i++)     //每个节点都只遍历了一次，节省了时间
	{
		j = g[x][i];
		if (dfn[j] == -1)
		{
			tarjan(j);
			low[x] = min(low[x], low[j]);
		}
		else if (instack[j])
		{
			low[x] = min(low[x], dfn[j]);
		}
	}
	if (dfn[x] == low[x])
	{
		cnt++;
		do {
			j = STACK[TOP--];
			instack[j] = false;
			component[cnt].push_back(j);
		} while (x != j);
	}
}

int main()
{
	int n, m, x, y;
	int ans = 0;
	cin >> n >> m;
	memset(dfn, -1, sizeof(dfn));  //使用memset而不是循环初始化，节省了时间
	memset(low, -1, sizeof(low));
	memset(instack, 0, sizeof(instack));
	memset(STACK, -1, sizeof(STACK));

	for (int i = 1;i <= m;i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
	}
	for (int i = 1;i <= n;i++)
		if (dfn[i] == -1)
			tarjan(i);

	for (int i = 1;i <= cnt;i++)
	{
		vector<int> vec = component[i];
		int sz = vec.size();
		if (sz == 1) continue;
		else ans += sz*(sz - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}