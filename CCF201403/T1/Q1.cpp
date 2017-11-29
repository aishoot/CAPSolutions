/***********************201403-1**************************/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int N, i, j, k;
	ifstream cin("test.txt");
	while (cin >> N)
	{
		int num[500];
		int count = 0;
		for (i = 0;i < N;i++)
		{
			cin >> num[i];
		}
		for (i = 0;i < N;i++)
			for (j = i + 1;j < N;j++)
				if (num[i] + num[j] == 0)
					count++;
		cout << count << endl;
	}
	return 0;
}