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
		cin.getline(buffer, 81);  //������з�
		for (i = 0;i < m;i++)
		{
			cin.getline(buffer, 81);
			string sTemp(buffer);         //!!!!��char����ת��Ϊstring
			v.push_back(sTemp);
		}

		for (j = 0;j < n;j++)  //�������
		{
			char temp_val[105];
			memset(temp_val, 0, sizeof(temp_val));
			cin >> varible;
			cin.getline(temp_val, 105);
			string value(temp_val);

			for (i = 0;i < m;)
			{
				string::size_type found = v[i].find(varible);
				if (found != string::npos)  //�����
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



//����1��100��
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
			//�õ������Լ�ӳ�� 
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




//����2
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;

int main()
{
	int n, m, i, j, start, end;
	//varStr[][0]������
	//varStr[][1]�����洢������
	ifstream cin("test.txt");
	string inputStr[101], outputStr[102], varStr[102][2], tempVar;
	cin >> n >> m;
	getchar();//�Ե�һ���س���
			  //����֮����ʹ��getline(cin,str)����Ϊÿ�ο��Զ�ȡһ�����ݣ��ո�Ҳ����Ϊ��ȡ�����ı�־��
			  //�����cin>>str�Ļ��������ո����ʾ���ݶ�ȡ������
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
		//flag��ʾvar�����Ƿ���ڶ���
		bool flag = true;
		while (1)
		{
			flag = false;
			start = inputStr[i].find("{{ ");
			end = inputStr[i].find(" }}");
			if (start<0 || end<0) break; //��δ�ҵ�"{{ "����" }}",���˳�ѭ�� 
			tempVar = inputStr[i].substr(start + 3, end - start - 3);//ȡ��������ֵ��name
			for (j = 0; j<m; j++)
			{
				if (tempVar == varStr[j][0])
				{
					flag = true;
					tempVar = varStr[j][1];
					break;
				}
			}
			//�����ڶ���
			if (flag == false) tempVar = "";
			outputStr[i] = outputStr[i] + inputStr[i].substr(0, start) + tempVar;
			inputStr[i] = inputStr[i].substr(end + 3, inputStr[i].length() - end - 3);
		}
		outputStr[i] = outputStr[i] + inputStr[i];//��Ҫ���˼������ʣ�µ�һ������
		cout << outputStr[i] << endl;
	}
	return 0;
}