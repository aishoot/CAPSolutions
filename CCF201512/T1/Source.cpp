//��ֻ��˵ˮ��һ��
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string str;
	ifstream cin("test.txt");
	while (cin >> str)
	{
		int sum = 0;
		for (string::iterator it = str.begin();it != str.end();it++)
			sum += (*it - '0');
		cout << sum << endl;
		str.clear();
	}
	return 0;
}



//�����ֱ�ӽⷨ
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    long n;
    while(scanf("%ld", &n)!=EOF)
	{
        int sum = 0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        printf("%d\n", sum);
    } 
    return 0;
}
