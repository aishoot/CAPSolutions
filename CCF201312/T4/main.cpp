/****************************************************** 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <list>
using namespace std;

long long f[2000][3][2];
// f[seq_k to place][0: to place 0 , 1: ethier 0 or 1, 2 : must be 1][3 is placed ?1 : 0]
int dp(int n, int p1, int p3)
{
    long long &now = f[n][p1][p3];
    if (now != -1)
       return now;

    if (n == 0)
    {
       if (p1 == 2 && p3 == 1)
          now = 1;
	   else
          now = 0;
       return now;
    }

    now = 0;
    if (p1 == 0)
       now += dp(n-1, 1, p3); // go 0
	else if (p1 == 1)
    {
        now += dp(n-1, 1, p3); // go 0
        now += dp(n-1, 2, p3); // go 1
    }
	else // p1 == 2
        now += dp(n-1, 2, p3); // go 1

    if (p3 == 0)
    {
       now += dp(n-1, p1, p3); // go 2;
       now += dp(n-1, p1, 1); // go 3;
    }
	else
        now += dp(n-1, p1, 1); // go 3;

    now %= 1000000007;
}

int main()
{
    int n;
    cin >> n;
    memset(f, -1, sizeof(f));
    int ans = dp(n - 1, 0, 0); // seq[n] is 2
    cout << ans << endl;
    return 0;
}
******************************************************************/

//Solution¨1 
#include <iostream>
using namespace std;

int dp[1001][16] = { 0 };
const int prime = 1000000007;

int main()
{
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < 16; j++)
		{
            if (dp[i][j] == 0) continue;
            
            if ((j & 2) == 0 && i != 0)
                dp[i + 1][j | 1] = (dp[i + 1][j | 1] + dp[i][j]) % prime;

            dp[i + 1][j | 2] = (dp[i + 1][j | 2] + dp[i][j]) % prime;

            if ((j & 8) == 0)
                dp[i + 1][j | 4] = (dp[i + 1][j | 4] + dp[i][j]) % prime;

            dp[i + 1][j | 8] = (dp[i + 1][j | 8] + dp[i][j]) % prime;
        }
    }
    cout << dp[n][15] << endl;
}



/***************************Solution·¨2
#include <iostream>
using namespace std;

int main()
{
   long long mod = 1000000007;
   long long n;
   cin>>n;
   
   long long **states = new long long*[n+1];
   for(long long i =0;i<n+1;i++)
       states[i]=new long long[6];
   for(long long i =0;i<6;i++)
       states[0][i]=0;
   /*6ÖÖ×´Ì¬
    * 0£­£­Ê£013
    * 1£­£­Ê£13
    * 2£­£­Ê£01
    * 3£­£­Ê£3
    * 4£­£­Ê£1
    * 5£­£­ÎÞ
    *
   for(long long i=1;i<=n;i++)
   {
       long long j = i-1;
       states[i][0] = 1;
       states[i][1] = (states[j][0] + states[j][1] * 2) % mod;
       states[i][2] = (states[j][0] + states[j][2]) % mod;
       states[i][3] = (states[j][1] + states[j][3] * 2) % mod;
       states[i][4] = (states[j][1] + states[j][2] + states[j][4] * 2) % mod;
       states[i][5] = (states[j][3] + states[j][4] + states[j][5] * 2) % mod;
   }
   
   cout<<states[n][5]<<endl;
   return 0;
} 
****************************************************/ 


