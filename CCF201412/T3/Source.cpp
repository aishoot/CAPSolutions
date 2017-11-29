//    �Լ۸�����, Ȼ��ö��ÿ���۸�����ǰ׺��(sell)�ͺ�׺��(buy)�ó���ǰ�۸������
//    ʵ����, Ϊ�˽������ͬ�۸�ļ�¼�ϲ�, ʹ����map���д洢;
#include <cstdio>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 5005;

struct GP
{
	bool buy;
	double price;
	int tot;
	void read(bool b)
	{
		buy = b;
		cin >> price >> tot;
	}
}gp[N];

map<double, long long> buy, sell;
set<double> price;

int main()
{
	char op[10];
	ifstream cin("test.txt");

	for (int line = 1; cin>>op; line++)
	{
		if (op[0] == 'c')
		{
			int x;
			cin >> x;
			(gp[x].buy ? buy : sell)[gp[x].price] -= gp[x].tot;
		}
		else
		{
			gp[line].read(op[0] == 'b');
			price.insert(gp[line].price);
			(gp[line].buy ? buy : sell)[gp[line].price] += gp[line].tot;
		}
	}

	long long bsum = 0;
	for (map<double, long long>::iterator i = buy.begin(); i != buy.end(); i++)bsum += i->second;
	long long ssum = 0;
	double ansprice = 0;
	long long anstot = 0;

	for (set<double>::iterator i = price.begin(); i != price.end(); i++)
	{
		if (!(sell[*i] || buy[*i])) continue;
		ssum += sell[*i];
		long long x = min(ssum, bsum);//�ڵ�ǰ�۸��£��ɽ���Ӧ�õ��ںϷ�����ɽ������߿��ԺϷ������ɽ����е���Сֵ��

		if (x >= anstot)
		{
			anstot = x;
			ansprice = *i;
		}
		bsum -= buy[*i];
	}

	printf("%.2f %lld\n", ansprice, anstot);
	return 0;
}



/******************************ֻ��10��***********************************
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <set>
#include <iomanip>
#include <vector>
#include <memory.h>
using namespace std;

struct share
{
	string bors;
	float price;
	long num;   //��������Ϊ������
};

long min(long x1, long x2)
{
	return x1 < x2 ? x1 : x2;
}


int main()
{
	int x, j;
	int len_cancel, len_v;
	float price_now;

	vector<share> v;
	vector<int> cancel;  //��������ɾ���ı��
	set<float> pri;      //�������еļ۸��¼��û���ظ�
	string temp;
	ifstream cin("test.txt");

	//��ȫ����������
	v.resize(5000);
	int i = 0;
	while (cin >> temp)
	{
		if (temp == "cancel")
		{
			cin >> x;
			//v.erase(v.begin()+(x-1));
			cancel.push_back(x);
			continue;
		}

		v[i].bors = temp;
		cin >> v[i].price >> v[i].num;
		pri.insert(v[i].price);
		i++;
	}

	//ɾ�����еļ�¼
	if (cancel.size() != 0)
	{
		len_cancel = cancel.size();
		for (j = 0;j < len_cancel;j++)
		{
			v.erase(v.begin() + (cancel[j] - 1));
		}
	}
	
	int len_pri = pri.size();
	float res_pri;   //��¼������ļ۸�
	long max_num=0;    //���ĳɽ���
	len_v = v.size();

	for (set<float>::iterator it = pri.begin();it != pri.end();it++)
	{
		long sell = 0, buy = 0;
		price_now = *it;   //��ǰ��ȡ�ļ۸�
		for (i = 0;i < len_v;i++)
		{
			if (v[i].price >= price_now && v[i].bors == "buy")
			{
				buy += v[i].num;
			}

			if (v[i].price <= price_now && v[i].bors == "sell")
			{
				sell += v[i].num;
			}
		}

		if (min(buy, sell) > max_num)
		{
			max_num = min(buy, sell);
			res_pri = price_now;
		}
	}

	pri.clear();
	cancel.clear();
	v.clear();

	cout << setiosflags(ios::fixed) << setprecision(2) << res_pri << " " << max_num << endl;

	return 0;
}
*********************************************************************/