/****************************
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

int main()
{
	int m, n, i, j;
	char buffer[81];
	vector<string> v;
	ifstream cin("test.txt");

	while (cin >> m >> n)
	{
		string varible;
		memset(buffer, 0, sizeof(buffer));
		cin.getline(buffer, 81);  //清除换行符
		for (i = 0;i < m;i++)
		{
			cin.getline(buffer, 81);
			string sTemp(buffer);         //!!!!把char数组转换为string
			v.push_back(sTemp);
		}

		for (j = 0;j < n;j++)  //读入变量
		{
			char temp_val[105];
			memset(temp_val, 0, sizeof(temp_val));
			cin >> varible;
			cin.getline(temp_val, 105);
			string value(temp_val);

			for (i = 0;i < m;)
			{
				string::size_type found = v[i].find(varible);
				if (found != string::npos)  //里边有
					v[i].replace(v[i].begin() + (found - 3), v[i].begin() + (found + varible.length() + 3),
						value.begin() + 2, value.end() - 1);
				else  i++;
			}
		}

		for (i = 0;i < m;i++)
		{
			cout << v[i] << endl;
		}

		v.clear();
	}

	return 0;
}



//代码1，100分
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

char s[105][105];
int m, n;

map<string, string> mp;

int main()
{
	while (scanf("%d %d", &m, &n) != EOF)
	{
		getchar();
		for (int i = 0; i < m;i++)
		{
			gets(s[i]);
			//cout << s[i] << endl;
		}

		mp.clear();
		char ss[505];
		char var[105], val[105];
		for (int i = 0; i < n; i++)
		{
			gets(ss);
			int p = 0, p1 = 0, p2 = 0;
			int len = strlen(ss);
			//得到变量以及映射 
			while (ss[p] == ' ') p++;
			while (ss[p] != ' ')var[p1++] = ss[p++];
			var[p1] = '\0';
			while (1) {
				if (ss[p++] == '\"') break;
			}
			while (ss[p] != '\"') val[p2++] = ss[p++];
			val[p2] = '\0';
			//cout << var << " " << val << endl;
			mp[var] = val;
		}

		for (int i = 0; i < m; i++)
		{
			int len = strlen(s[i]);
			for (int j = 0; j < len; )
			{
				if (s[i][j] == '{' && s[i][j + 1] == '{')
				{
					j += 3;
					char var2[105];
					int p = 0;
					while (s[i][j] != ' ') var2[p++] = s[i][j++];
					var2[p] = '\0';
					cout << mp[var2];
					j += 3;
				}
				else putchar(s[i][j++]);
			}
			printf("\n");
		}
	}
	return 0;
}
***************************************************************************/




//代码2
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
	int n, m, i, j, start, end;
	//varStr[][0]变量名
	//varStr[][1]变量存储的内容
	ifstream cin("test.txt");
	string inputStr[101], outputStr[102], varStr[102][2], tempVar;
	cin >> n >> m;
	getchar();//吃掉一个回车符
			  //这里之所以使用getline(cin,str)是因为每次可以读取一行数据，空格也不作为读取结束的标志。
			  //如果用cin>>str的话，遇到空格则表示数据读取结束。
	for (i = 0; i < n; i++)
		getline(cin, inputStr[i]);
	for (i = 0; i<m; i++)
	{
		cin >> varStr[i][0];
		getline(cin, varStr[i][1]);
		start = varStr[i][1].find("\"");
		end = varStr[i][1].rfind("\"");
		varStr[i][1] = varStr[i][1].substr(start + 1, end - start - 1);
	}
	for (i = 0; i<n; i++)
	{
		//flag表示var变量是否存在定义
		bool flag = true;
		while (1)
		{
			flag = false;
			start = inputStr[i].find("{{ ");
			end = inputStr[i].find(" }}");
			if (start<0 || end<0) break; //若未找到"{{ "或者" }}",则退出循环 
			tempVar = inputStr[i].substr(start + 3, end - start - 3);//取出变量的值如name
			for (j = 0; j<m; j++)
			{
				if (tempVar == varStr[j][0])
				{
					flag = true;
					tempVar = varStr[j][1];
					break;
				}
			}
			//不存在定义
			if (flag == false) tempVar = "";
			outputStr[i] = outputStr[i] + inputStr[i].substr(0, start) + tempVar;
			inputStr[i] = inputStr[i].substr(end + 3, inputStr[i].length() - end - 3);
		}
		outputStr[i] = outputStr[i] + inputStr[i];//不要忘了加上最后剩下的一截输入
		cout << outputStr[i] << endl;
	}
	return 0;
}