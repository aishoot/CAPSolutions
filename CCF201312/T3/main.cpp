#include <iostream>
#include <algorithm>
#include <vector> 
#include <fstream>
using namespace std;

int main()
{
	int num,i,j;
	ifstream cin("test.txt");
	while(cin>>num)
	{
		int area, max_area=0, t;
		vector<int> height;
		for(i=0;i<num;i++)
		{
			cin>>t;
			height.push_back(t);
			for(j=i;j>=0;j--)
			{
				area=(*min_element(height.begin()+(i-j),height.begin()+i+1))*(j+1);
				if(area>max_area)
				{
					max_area=area;
				}
			}
		}
		cout<<max_area<<endl;
	}
	return 0;
}
