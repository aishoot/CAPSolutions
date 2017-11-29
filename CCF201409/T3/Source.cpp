#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int main()
{
	int n, i, j;
	bool option;
	string str, S;
	ifstream cin("test.txt");
	
	while (cin >> S)
	{
		int len_S, len_str;
		cin >> option;
		cin >> n;

		for (i = 0;i < n;i++)
		{
			cin >> str;
			string::iterator it;

			if (option == 1)
			{
				string::size_type found = str.find(S);
				if (found != string::npos)
					cout << str << endl;
			}

			else
			{
				string temp_S = S;
				string temp_str = str;
				len_S = temp_S.length();
				len_str = temp_str.length();

				for (j = 0;j < len_S;j++)
				{
					if (temp_S[j] >= 'A' && temp_S[j] <= 'Z')
					{
						temp_S[j] += 32;
					}
				}
				
				for (j = 0;j < len_str;j++)
				{
					if (temp_str[j] >= 'A' && temp_str[j] <= 'Z')
					{
						temp_str[j] += 32;
					}
				}

				string::size_type found = temp_str.find(temp_S);
				if (found != string::npos)
					cout << str << endl;

				temp_str.clear();
				temp_S.clear();
			}

			str.clear();
		}

		S.clear();
	}

	return 0;
}



#include<iostream>
#include<string>
using namespace std;
string s1, s2;

void exchange(string &s)
{
	int k = s.size();
	for (int i = 0;i<k;i++)
	{
		if (s[i] >= 'A' &&  s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
}
int main()
{
	string s;
	int n;
	cin >> s;
	cin >> n;
	if (n)
	{
		int m;
		cin >> m;
		for (int i = 0; i< m; i++)
		{
			cin >> s1;
			if (s1.find(s) != s1.npos)
				cout << s1 << endl;
		}
	}
	else
	{
		int m;
		exchange(s);
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> s2;
			string s3 = s2;
			exchange(s2);
			if (s2.find(s) != s2.npos)
				cout << s3 << endl;
		}
	}
	return 0;
}