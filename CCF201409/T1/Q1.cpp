/***********************201403-1 Ïà·´Êý**************************/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int N, i, j;
	ifstream cin("test.txt");
	while (cin >> N)
	{
		int num[1000];  //sdfsdf
		int count = 0;
		for (i = 0;i < N;i++)
		{
			cin >> num[i];
		}
		for (i = 0;i < N;i++)
			for (j = i + 1;j < N; j++)
				if (num[j] - num[i] == 1 || num[j] - num[i] == -1)
					count++;
		cout << count << endl;
	}
	return 0;
}



/**********
#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{

	int n;
	cin >> n;
	vector<int> v;
	int num = 0;
	for (int i = 0; i<n; i++)
	{
		int m;
		cin >> m;
		v.push_back(m);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i<v.size() - 1; i++)
	{
		if (v[i] - v[i + 1] == -1)
			num++;
	}
	cout << num << endl;
	return 0;
}*****************/