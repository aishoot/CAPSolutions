/*********************************100·Ö*************************
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, num, i, len;
	vector<int> myvector;
	ifstream cin("test.txt");
	
	while (cin >> n)
	{
		for (i = 0;i < n;i++)
		{
			cin >> num;
			myvector.push_back(num);
		}

		vector<int>::iterator it;
		it = unique(myvector.begin(), myvector.end());
		myvector.erase(it, myvector.end());

		len = myvector.size();
		cout << len << endl;

		myvector.clear();
	}

	return 0;
}
**************************************************************/


//´úÂë2
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int a[1010];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int sum = 1;

	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[i - 1])
			sum++;
	}

	printf("%d\n", sum);

	return 0;
}

