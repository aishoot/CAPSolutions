#include <iostream>
#include <stdio.h>
#include <fstream>
#include <memory.h>
using namespace std;

int main()
{
	int n, i, x;
	int num[1001];
	ifstream cin("test.txt");
	
	while (cin >> n)
	{
		memset(num, 0, sizeof(num));
		for (i = 0;i < n-1;i++)
		{
			cin >> x;
			num[x]++;
			cout << num[x] << " ";
		}

		cin >> x;
		num[x]++;
		cout << num[x] << endl;
	}

	return 0;
}


//´úÂë2£º
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, int> reader;
	int n, reader_no;
	cin >> n;

	while (n--)
	{
		cin >> reader_no;
		reader[reader_no]++;
		cout << reader[reader_no] << " ";
	}
	cout << endl;

	return 0;
}