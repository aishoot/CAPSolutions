//��һ�����о������������֮��ľ��룺
//˼�룺������ȡһ���㣬�Ӹõ�������ҵ�����ó�ʼ����Զ��һ����v���ٴ�v������
//ͬ���ķ����ҳ���v��ʼ���·���ĵ�x����v��x��Ϊ�����·��
#include <iostream>
#include <vector>
#include <fstream>
#include <memory.h>
using namespace std;
const int maxn = 20005;   //һֱ��ʼ��Ϊ10001������50��
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
	vis[u] = 1; //�Ƿ�ͨ��
	if (ma<cost)
	{
		ma = cost; //��¼�·������
		s = u;  //��¼���������һ����
	}
	for (int i = 0;i<G[u].size();i++) //��U��ÿһ���ڽӵ����
	{
		if (!vis[G[u][i]])  //�����ڽӵ�δ��ǣ�������1�������ݹ����
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

	ma = -1;  //ÿ�ε���dfs����ʱ������Ҫ�����ֵ��ʼ��Ϊ-1����vis��ʼ��Ϊ0
	memset(vis, 0, sizeof(vis));
	dfs(1, 0);
	ma = -1;

	memset(vis, 0, sizeof(vis));
	dfs(s, 0);
	cout << ma << endl;
	return 0;
}




//BFS���

/*******************************************************************************************
�������½���,��Ҫ�������˷�֤����

���� s-t����·��Ϊ����ֱ�������߳�Ϊ���ϵ��·
    ���н��ۣ�������һ��u�����ѵ�����Զ�ĵ�һ����s��t�е�һ�㣬Ȼ���ڴ������Զ�㿪ʼ�ѣ��Ϳ����ѵ���һ���·�Ķ˵㣬
����������ѾͿ����ҳ������·

֤����
    1����uΪs-t·���ϵ�һ�㣬������Ȼ�������������ѵ�����Զ��ΪT��
dis(u,T) >dis(u,s)     ��  dis(u,T)>dis(u,t)   ���·����s-t�ˣ������ì��

    2����u��Ϊs-t·���ϵĵ�
    ������ȷ������u�ߵ���s-t·���ϵ�һ�㣬��ô��������·���϶�����s-t���ˣ������յ�Ϊs��t����1���Ѿ�֤������

��������������������ˣ�
    1��u�ߵ���s-t·���ϵ�ĳ�㣬����ΪX�����϶��ߵ�ĳ���˵㣬������t ����·���ܳ���Ϊdis(u,X)+dis(X,t)
    2��u�ߵ���Զ���·��u-T��s-t�޽��㣬��dis(u-T) >dis(u,X)+dis(X,t);��Ȼ��������ʽ�ӳ�����
��dis(u,T)+dis(s,X)+dis(u,X)>dis(s,X)+dis(X,t)=dis(s,t)�·����s-tì��

    �����ǾͿ�������һ��BFS�ҵ��·����һ���˵㣬����һ��BFS����������·��
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