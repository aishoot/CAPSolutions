//³ÌÐò1£¬50·Ö£¬³¬Ê±

#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

int n, q, k;

mat mul(mat& A, mat& B)
{
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < (int)A.size(); ++i)
		for (int j = 0; j < (int)B[0].size(); ++j)
			for (int k = 0; k < (int)B.size(); ++k)
				C[i][j] ^= A[i][k] & B[k][j];
	return C;
}

mat pow(mat A, int p)
{
	mat E(A.size(), vec(A.size()));
	for (int i = 0; i < (int)A.size(); ++i) E[i][i] = 1;
	while (p) {
		if (p & 1) E = mul(E, A);
		A = mul(A, A);
		p >>= 1;
	}
	return E;
}

int main()
{
//#ifdef LOCAL
	//fstream cin("data.in");
//#endif // LOCAL

	cin >> n;

	mat A(n, vec(n));

	char ch;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> ch;
			A[i][j] = ch - '0';
		}
	}

	mat b(n, vec(1));
	for (int i = 0; i < n; ++i)
	{
		cin >> ch;
		b[i][0] = ch - '0';
	}

	cin >> q;
	while (q--)
	{
		cin >> k;
		mat t = pow(A, k);
		mat ans = mul(t, b);
		for (int i = 0; i < (int)ans.size(); ++i) cout << ans[i][0];
		cout << endl;
	}

	return 0;
}