/*****************************************************************************
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
int n, m, k, d;
short map[1005][1005], dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
bool within(int x, int y) {
	if (x <= 0 || x>n || y <= 0 || y>n)
		return false;
	return true;
}
struct node {
	int x, y, step;
	node(int a = 0, int b = 0, int c = 0) {
		x = a;
		y = b;
		step = c;
	}
};
queue<node> q;
long long bfs() {
	node n;
	int t = 0;
	long long sum = 0;
	while (!q.empty()) {
		n = q.front();
		q.pop();
		int i, x, y;
		for (i = 0;i<4;i++) {
			x = n.x + dir[i][0];
			y = n.y + dir[i][1];
			if (within(x, y) && !(map[x][y] & 1)) {
				map[x][y] |= 1;
				if (map[x][y] & 2) {
					sum += (map[x][y] >> 2)*(n.step + 1);
					t++;
					if (t == k)
						return sum;
				}
				q.push(node(x, y, n.step + 1));
			}
		}
	}
}
int main() {
	while (scanf("%d %d %d %d", &n, &m, &k, &d) != EOF) {
		int i, j, x, y;
		memset(map, 0, sizeof(map));
		for (i = 0;i<m;i++) {
			scanf("%d %d", &x, &y);
			map[x][y] |= 1;
			q.push(node(x, y, 0));
		}
		for (i = 0;i<k;i++) {
			scanf("%d %d %d", &x, &y, &j);
			map[x][y] = (map[x][y] | 2) + (j << 2);
		}
		for (i = 0;i<d;i++) {
			scanf("%d %d", &x, &y);
			map[x][y] |= 1;
		}
		printf("%I64d\n", bfs());
	}
	return 0;
}



//结果不对，代码有问题
//#include <bits/stdc++.h>
#include <stdio.h>
#include <queue>
#include <iostream>
#include <fstream>

#define pii pair<int,int>
#define LL long long
using namespace std;

const int maxn = 1010;
const int dir[4][2] = { -1,0,0,-1,1,0,0,1 };
int n, m, k, d, e[maxn][maxn] = { 0 };

struct node
{
	int x, y, step;
	node(int a = 0, int b = 0, int c = 0)
	{
		x = a;
		y = b;
		step = c;
	}
};
queue<node>q;

bool isIn(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= n;
}

LL bfs()
{
	LL ans = 0;
	int cnt = 0;

	while (!q.empty())
	{
		node now = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = now.x + dir[i][0];
			int ny = now.y + dir[i][1];
			if (isIn(nx, ny) && !(e[nx][ny] & 1))
			{
				e[nx][ny] |= 1;
				q.push(node(nx, ny, now.step + 1));
				if (e[nx][ny] & 2)
				{
					ans += (now.step + 1)*(e[nx][ny] >> 2);
					if (++cnt == k) return ans;
				}
			}
		}
	}
	return ans;
}

int main()
{
	int x, y, z;
	ifstream cin("test.txt");

	while (cin>>n>>m>>k>>d)
	{
		for (int i = 0; i < m; ++i)
		{
			cin >> y >> x;
			q.push(node(x, y, 0));
			e[x][y] |= 1;
		}

		for (int i = 0; i < k; ++i)
		{
			cin >> y >> z >> x;
			e[x][y] = (e[x][y] | 2) + (z << 2);
		}

		for (int i = 0; i < d; ++i)
		{
			cin >> y >> x;
			e[x][y] |= 1;
		}

		printf("%I64d\n", bfs());
	}

	return 0;
}





//BFS就行了
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;

int data[1005][1005] = { 0 };
struct State
{
	int x, y;
	int layer;
	State(int _x, int _y, int _l = 0) :x(_x), y(_y), layer(_l) {}
	State()
	{
		x = y = layer = 0;
	}
};

queue<State> que;
int n, m, k, d, x, y, z;
long long ans;
void bfs();

int main()
{
	cin >> n >> m >> k >> d;
	for (int i = 0; i<m; i++)
	{
		cin >> x >> y;
		que.push(State(x, y));
	}

	for (int i = 0; i<k; i++)
	{
		cin >> x >> y >> z;
		data[x][y] = (data[x][y] | 2) + (z << 2);
	}

	for (int i = 0;i<d;i++)
	{
		cin >> x >> y;
		data[x][y] |= 1;
	}

	bfs();
	return 0;
}

void bfs()
{
	ans = 0;
	State tmp, cur;

	while (!que.empty())
	{
		cur = que.front();que.pop();
		int curx = cur.x, cury = cur.y, curl = cur.layer;

		if (curx>0 && cury>0 && curx <= n&&cury <= n && !(data[curx][cury] & 1))
		{
			data[curx][cury] |= 1;
			que.push(State(curx + 1, cury, curl + 1));
			que.push(State(curx, cury + 1, curl + 1));
			que.push(State(curx - 1, cury, curl + 1));
			que.push(State(curx, cury - 1, curl + 1));
			if (data[curx][cury] & 2)
				ans += (data[curx][cury] >> 2)*curl;
		}
	}

	cout << ans;
}
************************************************************************************/





/************************这才是真正的大神，没有bug,结果正确**********************************
思路：
    利用队列进行广度优先搜索，可以将所有分店一起先入栈然后进行广度优先搜索。在这里使用map记录所有
的位置，其中如果map值为-2则表示该点不能通过，如果map值为-1则表示该点位分店的位置，如果值大于
0则表示其他位置，等于0的时候表示没有订餐的位置，大于0的时候表示订餐的位置，且值为订订餐的数量。
注意搜索条件为( x > 0 && x <= n && y > 0 && y <= n && map[x][y] != -2 && minstep[x][y] == 0)
才对该点进行广度优先搜索，即将该点入栈。
******************************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

#define MAX_N 1002
int map[MAX_N][MAX_N] = { 0 };

typedef struct node
{
	int x, y;
	int depth;
}Node;

Node queue[MAX_N*MAX_N] = { 0 };
int minstep[MAX_N][MAX_N] = { 0 };
int curdep = 0;
int n;
int rear = -1, front = -1;

void search_point(int x, int y, int dep)
{
	if (x > 0 && x <= n && y > 0 && y <= n && map[x][y] != -2 && minstep[x][y] == 0)
	{
		queue[++rear].x = x;
		queue[rear].y = y;
		queue[rear].depth = dep + 1;
		minstep[x][y] = queue[rear].depth;
	}
}

void BFS()
{
	while (++front <= rear)
	{
		search_point(queue[front].x + 1, queue[front].y, queue[front].depth);
		search_point(queue[front].x - 1, queue[front].y, queue[front].depth);
		search_point(queue[front].x, queue[front].y + 1, queue[front].depth);
		search_point(queue[front].x, queue[front].y - 1, queue[front].depth);
	}
}

int main()
{
	int m, k, d;
	int mx, my, ci;
	ifstream cin("test.txt");
	cin >> n >> m >> k >> d;

	while (m--)
	{
		cin >> mx >> my;
		map[mx][my] = -1;  //代表分店 
		queue[++rear].x = mx;
		queue[rear].y = my;
		queue[rear].depth = 0;  //将分店入栈中 
	}

	while (k--)
	{
		cin >> mx >> my >> ci;
		map[mx][my] = ci;  //表示定餐量，所以凡是map值大于0的位置一定不是分店和障碍 
	}

	while (d--)
	{
		cin >> mx >> my;
		map[mx][my] = -2;  //表示障碍物 
	}

	//初始化完成
	BFS();  //利用队列进行广度优先搜索
	int sum = 0;

	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			if (map[i][j] > 0)
				sum = sum + map[i][j] * minstep[i][j];
		}
	}
	cout << sum << endl;
	return 0;
}
