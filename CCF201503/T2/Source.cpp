#include <iostream>
#include <fstream>
#include <memory.h>
#include <algorithm>
using namespace std;

struct NumSort
{
	int id;
	int count;
};

bool fun(NumSort x, NumSort y)
{
	if (x.count != y.count)
		return x.count > y.count;
	else
		return x.id < y.id;
}

int main()
{
	NumSort num[1001];
	int i, j;
	int n, val;
	ifstream cin("test.txt");

	//while (cin >> n)
	//{
	cin >> n;
		int max_num = 0;
		memset(num, 0, sizeof(num));

		for (i = 0;i < n;i++)
		{
			cin >> val;
			if (val > max_num)
				max_num = val;
			num[val].count++;
			num[val].id = val;
		}

		//进行排序
		sort(num, num + max_num + 1, fun);

		for (j = 0;num[j].count > 0;j++)
		{
			cout << num[j].id << " " << num[j].count << endl;
		}

	//}

	return 0;
}



/*****************只得70分，估计会超时，但方法新颖
#include <iostream>  
#include <string.h>  
using namespace std;

int main()
{
	int a[1005];
	int n, num;
	int i, j;
	memset(a, 0, sizeof(int) * 1005);

	cin >> n;
	for (i = 0;i<n;i++)
	{
		cin >> num;
		a[num]++;
	}

	for (i = 1004;i>0;i--)
		for (j = 0;j<1005;j++)
			if (a[j] == i)
				cout << j << " " << a[j] << endl;
	return 0;
}
*******************************************************/