/******
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	int i,j,N;
	ifstream cin("test.txt");
	while(cin>>N)
	{
		int num;
		
		vector<int> v;
		for(i=0;i<N;i++)
		{
			cin>>num;
			v.push_back(num);
		}
		
		sort(v.begin(),v.end(),less<int>());
		num=v[0];
		int count=1,min_num=v[0],min_count=1;
		for(i=1;i<N-1;i++)
		{
			if(v[i]>v[i-1])
			{
				count=1;
				if(count>min_count)
				   min_num=v[i];
			}
			else if(v[i]==v[i-1])
			{
				count++;
				if(count>min_count)
				{
				   	min_count=count;
				   	min_num=v[i];
				}
			}	
		}
		
		if(v[N-1]==min_num)
		    min_count++;
		
		cout<<min_num<<endl;
	}
	return 0;
}**********/ 



#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <map>
using namespace std;
int main()
{
   int n;
   cin >> n;
   map<int, int> f;
   for (int i = 0; i < n; i++)
   {
      int t;
      cin >> t;
      f[t]++;
   }
   
   int ans, m = 0;
   for (map<int, int>::iterator it = f.begin(); it != f.end(); it++)
   {
       if (it->second > m)
       {
          m = it->second;
          ans = it->first;
       }
   }
   cout << ans << endl;
   return 0;
}
