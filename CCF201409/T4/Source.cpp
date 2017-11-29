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



//������ԣ�����������
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





//BFS������
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





/************************����������Ĵ���û��bug,�����ȷ**********************************
˼·��
    ���ö��н��й���������������Խ����зֵ�һ������ջȻ����й������������������ʹ��map��¼����
��λ�ã��������mapֵΪ-2���ʾ�õ㲻��ͨ�������mapֵΪ-1���ʾ�õ�λ�ֵ��λ�ã����ֵ����
0���ʾ����λ�ã�����0��ʱ���ʾû�ж��͵�λ�ã�����0��ʱ���ʾ���͵�λ�ã���ֵΪ�����͵�������
ע����������Ϊ( x > 0 && x <= n && y > 0 && y <= n && map[x][y] != -2 && minstep[x][y] == 0)
�ŶԸõ���й�����������������õ���ջ��
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
		map[mx][my] = -1;  //����ֵ� 
		queue[++rear].x = mx;
		queue[rear].y = my;
		queue[rear].depth = 0;  //���ֵ���ջ�� 
	}

	while (k--)
	{
		cin >> mx >> my >> ci;
		map[mx][my] = ci;  //��ʾ�����������Է���mapֵ����0��λ��һ�����Ƿֵ���ϰ� 
	}

	while (d--)
	{
		cin >> mx >> my;
		map[mx][my] = -2;  //��ʾ�ϰ��� 
	}

	//��ʼ�����
	BFS();  //���ö��н��й����������
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
