//只得30分 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ifstream cin("test.txt");
	int p,i,j;

	while(cin>>p)
	{	
	    string InitStr,CurrentStr,temp;
		int InitLength,CurrentLength;
		cin>>InitStr;
		InitLength=InitStr.length();
		
		for(i=0;i<p;i++) 
		{
			cin>>CurrentStr;
			CurrentLength=CurrentStr.length();
			
			//对最后一位的'/'进行处理
			string::iterator it;
			it=CurrentStr.end();
			if(CurrentStr[CurrentLength-1]=='/')
		       CurrentStr.erase(it-1,it);
			
			//对以".."开头进行处理
			if(CurrentStr[0]=='.' && CurrentStr[1]=='.')
			{
				it=CurrentStr.begin();
				CurrentStr.erase(it,it+2);
				
				temp=InitStr;
				it=temp.end();
				
				temp.erase(it-3,it);
				CurrentStr=temp+CurrentStr;
			}
			
			//对".."在中间时进行处理
			int flag1=0;
			for(j=1;j<=5;j++)
			{
				 for(it=CurrentStr.begin();it!=CurrentStr.end();it++)
				{
					if(*it=='/' && *(it+1)=='.' && *(it+2)=='.')
					{
						CurrentStr.erase(it-3,it+3);
					}
				}
				
				if(CurrentStr[0]=='/' && CurrentStr[1]=='.' && CurrentStr[2]=='.')
				{
					it=CurrentStr.begin();
					CurrentStr.erase(it,it+3);
				}
			}
			
			//处理连续'/'
			string::iterator end_unique = unique( CurrentStr.begin(), CurrentStr.end() ); // 移动重复到最后
            CurrentStr.erase( end_unique, CurrentStr.end() ); //删除重复
			
			//处理'/.'
			for(it=CurrentStr.begin();it!=CurrentStr.end();it++)
			{
				if(*it=='/' && *(it+1)=='.')
				{
					CurrentStr.erase(it,it+2);
				}
			}
			
			cout<<CurrentStr<<endl;
			CurrentStr.clear();
			temp.clear();
		}
	}
	return 0;
}
