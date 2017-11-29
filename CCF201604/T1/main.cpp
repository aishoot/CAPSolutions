#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int n,i,value;
	ifstream cin("test.txt");
	while(cin>>n)
	{
		int num=0;
		int Sales[1000]={0};
		for(i=0;i<n;i++)
		{
			cin>>value;
			Sales[i]=value;
		}
		for(i=2;i<n;i++)
		{
			value=(Sales[i-1]-Sales[i-2])*(Sales[i]-Sales[i-1]);
			if(value<0) num++;
		}
		if(n==1 || n==2)
		  cout<<'0'<<endl;
		else cout<<num<<endl;
	}
	return 0;
}
