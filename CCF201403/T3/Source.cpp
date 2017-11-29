/************************************************************
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	int N, i, first, second, index, flag;
	string letters, cmds, tmp, parameter;
	map<string, string> m;
	cin >> letters >> N;
	getline(cin, cmds);

	for (i = 0; i < N; i++)
	{
		getline(cin, cmds);
		first = cmds.find(" ");
		flag = 0;
		while (first > 0)
		{
			cmds = cmds.substr(first + 1, cmds.length() - first - 1);
			second = cmds.find(" ");
			if (second < 0)
			{
				flag = 1;
				second = cmds.length();
			}// break;

			tmp = cmds.substr(0, second);
			if (tmp.length() == 2 && tmp[0] == ' - ')
			{
				index = letters.find(tmp[1]);
				if (index >= 0)
				{
					if (index + 1 < letters.length() && letters[index + 1] == ':')
					{
						if (flag == 1) break;
						else
						{
							cmds = cmds.substr(second + 1, cmds.length() - second - 1);
							second = cmds.find(" ");
							if (second < 0) second = cmds.length();
							parameter = cmds.substr(0, second);
							if (m.count(tmp))
								m.erase(tmp);
							m.insert(pair<string, string>(tmp, parameter));
						}
					}

					else
					{
						if (m.count(tmp))
							m.erase(tmp);
						m.insert(pair<string, string>(tmp, ""));
					}

					first = cmds.find(" ");
				}
				else break;
			}
			else break;
						 //first = cmds.find(" ");  
		}

		cout << "Case " << i + 1 << ":";
		map<string, string>::iterator it = m.begin();

		while (it != m.end())
		{
			cout << " " << it->first;
			if (it->second != "")
				cout << " " << it->second;
			++it;
		}
		cout << endl;
		m.clear();
	}
	return 0;
}
****************************************************************************************/


#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream cin("test.txt");
	string s;
	cin >> s;
	char buffer[260];
	int n;
	cin >> n;
	cin.getline(buffer, 260);

	for (int i = 1;i <= n;i++)
	{
		cin.getline(buffer, 260);
		string a(buffer); 
		vector<string> v;

		map<string, string> map1;     

		for (int t = (int)a.find(" ");t != -1; t = (int)a.find(" "))
		{
			string temp = a.substr(0, t);
			v.push_back(temp);
			a = a.substr(t + 1);
		}
		v.push_back(a); 

		for (int j = 0;j<v.size();j++)
		{
			if (v[j].size() == 2 && v[j][0] == '-')
			{
				char c = v[j][1];
				int next = (int)s.find(c);

				if (next == -1) 
					break;
				if (map1.find(v[j]) == map1.end()) 
					map1.insert(pair<string, string>(v[j], ""));

				if (next + 1<s.size() && s[next + 1] == ':' && j + 1<v.size())
				{
					map<string, string>::iterator it = map1.find(v[j]);
					it->second = v[j + 1];
					j++;
				}
			}
			else if (j != 0)
				break;
		}

		cout << "Case " << i << ":";
		for (map<string, string>::iterator it = map1.begin();it != map1.end();it++)
		{
			cout << " " << it->first;
			if (it->second != "")
				cout << " " << it->second;
		}
		cout << endl;
	}
	return 0;
}