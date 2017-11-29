#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

int main()
{
	string s;
	ifstream cin("test.txt");
	while(cin>>s)
	{
		int sum;
		sum=(s[0]-'0')*1+(s[2]-'0')*2+(s[3]-'0')*3+(s[4]-'0')*4+(s[6]-'0')*5
		+(s[7]-'0')*6+(s[8]-'0')*7+(s[9]-'0')*8+(s[10]-'0')*9;
		
		if( (sum%11==10 && s[12]=='X') || ( (sum%11+'0')==s[12] ))
		{
			cout<<"Right"<<endl;
		}
		else if(sum%11==10)
		{
			s[12]='X';
			cout<<s<<endl;
	    }
	    else
	    {
			s[12]=sum%11+'0';
			cout<<s<<endl;
		}
	}
	return 0;
} 
