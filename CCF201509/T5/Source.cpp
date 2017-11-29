//代码-只有70分
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct trie
{
	int next[105][26], fail[105], end[105];
	int root, L;
	int newnode()
	{
		for (int i = 0;i<26;i++)
			next[L][i] = -1;
		end[L++] = -1;
		return L - 1;
	}

	void init()
	{
		L = 0;
		root = newnode();
	}

	void insert(char s[], int id)
	{
		int len = strlen(s);
		int now = root;
		for (int i = 0;i<len;i++)
		{
			if (next[now][s[i] - 'a'] == -1)
				next[now][s[i] - 'a'] = newnode();
			now = next[now][s[i] - 'a'];
		}
		end[now] = id;
	}

	void build()
	{
		queue<int> Q;
		fail[root] = root;
		for (int i = 0;i<26;i++)
		{
			if (next[root][i] == -1)
				next[root][i] = root;
			else
			{
				fail[next[root][i]] = root;
				Q.push(next[root][i]);
			}
		}

		while (!Q.empty())
		{
			int now = Q.front();
			Q.pop();
			for (int i = 0;i<26;i++)
			{
				if (next[now][i] == -1)
					next[now][i] = next[fail[now]][i];
				else
				{
					fail[next[now][i]] = next[fail[now]][i];
					Q.push(next[now][i]);
				}
			}
		}
	}
};

trie ac;
char buf[105];
int dp[100005][105];
bool exist[100005][105];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	ac.init();
	for (int i = 1;i <= n;i++)
	{
		scanf("%s", buf);
		ac.insert(buf, i);
	}

	ac.build();
	memset(dp, 0, sizeof(dp));
	memset(exist, false, sizeof(exist));
	exist[0][0] = true;

	for (int i = 1;i <= m;i++)
		for (int j = 0;j<105;j++)
		{
			if (exist[i - 1][j])
			{
				for (int k = 0;k<26;k++)
				{
					exist[i][ac.next[j][k]] = true;
					int state = ac.next[j][k];
					int temp = state;
					int v = 0;
					while (temp != ac.root)
					{
						if (ac.end[temp] != -1)
							v++;
						temp = ac.fail[temp];
					}
					dp[i][state] = max(dp[i][state], dp[i - 1][j] + v);
				}
			}
		}

	int ans = 0;
	for (int i = 0;i<105;i++)
		ans = max(ans, dp[m][i]);
	printf("%d\n", ans);
}