/*****************************
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <cstring>
#include <list>
using namespace std;

class Move
{
    public:
    virtual bool CanMove(char from, char to, int dx, int dy) = 0;
};

class ForwardMove : public Move
{
    public:
    virtual bool CanMove(char from, char to, int dx, int dy)
    {
        if (to == '#') return false;
            switch (from)
            {
                case '+' : case 'S' : case 'T' : return true; break;
                case '-' : return dy != 0; break;
                case '|' : return dx != 0; break;
                case '.' : return dx == 1; break;
            }
        return false;
    }
};

class BackwardMove : public Move
{
    public:
    virtual bool CanMove(char from, char to, int dx, int dy)
    {
        if (to == '#') return false;
        switch (to)
        {
            case '+' : case 'S' : case 'T' : return true; break;
            case '-' : return dy != 0; break;
            case '|' : return dx != 0; break;
            case '.' : return dx == -1; break;
        }
      return false;
    }
};

char s[100][100];
typedef bool ARR[100][100];
ARR bs, bt;
int sx, sy, tx, ty;
int d[4][2] = {{-1, 0},{1, 0},{0, 1},{0, -1}};

void Bfs(ARR b, Move *move, int x, int y)
{
    if (b[x][y])
        return;
    b[x][y] = true;
    for (int o = 0; o < 4; o++)
    {
       int dx = d[o][0];
       int dy = d[o][1];
       int xx = x + dx;
       int yy = y + dy;
       if (move->CanMove(s[x][y], s[xx][yy], dx, dy))
       {
          Bfs(b, move, xx, yy);
       }
    }
}

int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            s[i][j] = '#';
    for (int i = 1; i <= n; i++)
        cin >> s[i]+1;
    for (int i = 0; i <= n + 1; i++)
        s[i][m + 1] = '#';
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
           if (s[i][j] == 'S')
           {
              sx = i;
              sy = j;
           }
           if (s[i][j] == 'T')
           {
              tx = i;
              ty = j;
           }
        }
    }
    
    Bfs(bs, new ForwardMove(), sx, sy);
    Bfs(bt, new BackwardMove(), tx, ty);
    int ans = 0;
    for (int i = 0; i <= n + 1; i++)
    {
       for (int j = 0; j <= m + 1; j++)
       {
           if (bs[i][j] && ! bt[i][j])
              ans ++;
       }
    }
    if (bs[tx][ty] == false)
        cout << "I'm stuck!" << endl;
    else
        cout << ans << endl;
    return 0;
}
******************************************************************/



//***************************
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define pii pair<int,int>
using namespace std;
const int maxn = 100;
char mp[maxn][maxn];
bool va[maxn][maxn],vb[maxn][maxn],e[maxn*maxn][maxn*maxn];
int n,m,sx,sy,tx,ty;
const int dir[4][2] = {-1,0,0,-1,1,0,0,1};

bool isIn(int x,int y)
{
    return x >= 0 && x < n && y >= 0&& y < m;
}

void select(int &x,int &y,pii &now)
{
    switch(mp[now.first][now.second])
	{
        case '+':x = 0,y = 1;break;
        case '|':x = 0,y = 2;break;
        case '-':x = 1,y = 2;break;
        case '.':x = 2,y = 2;break;
    }
}

bool bfs()
{
    queue< pii >q;
    q.push(make_pair(sx,sy));
    memset(va,false,sizeof(va));
    va[sx][sy] = true;
    memset(e,false,sizeof(e));
    while(!q.empty())
	{
        pii now = q.front();
        q.pop();
        int st,sp;
        select(st,sp,now);
        for(int i = st; i < 4; i += sp)
		{
            int ox = dir[i][0] + now.first;
            int oy = dir[i][1] + now.second;
            if(isIn(ox,oy) && mp[ox][oy] != '#')
			{
                e[ox*m+oy][now.first*m+now.second] = true;
                if(!va[ox][oy])
				{
                    va[ox][oy] = true;
                    q.push(make_pair(ox,oy));
                }
            }
        }
    }
    return va[tx][ty];
}

void bfs2()
{
    queue< pii >q;
    q.push(make_pair(tx,ty));
    memset(vb,false,sizeof(vb));
    vb[tx][ty] = true;

    while(!q.empty())
	{
        pii now = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
		{
            int ox = dir[i][0] + now.first;
            int oy = dir[i][1] + now.second;
            if(isIn(ox,oy)&&e[now.first*m+now.second][ox*m+oy]&&!vb[ox][oy])
			{
                vb[ox][oy] = true;
                q.push(make_pair(ox,oy));
            }
        }
    }
}

int main()
{
    while(~scanf("%d %d",&n,&m))
	{
        for(int i = 0; i < n; ++i)
		{
            scanf("%s",mp[i]);
            for(int j = 0; j < m; ++j)
            if(mp[i][j] == 'S')
			{
                sx = i;
                sy = j;
                mp[i][j] = '+';
            }
			else if(mp[i][j] == 'T')
			{
                tx = i;
                ty = j;
                mp[i][j] = '+';
            }
        }

        if(bfs())
		{
            bfs2();
            int ans = 0;

            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)
                    if(va[i][j] && !vb[i][j])
					   ans++;
            cout<<ans<<endl;
        }
		else puts("I'm stuck!");
    }
    return 0;
}
/**********************************************************/
