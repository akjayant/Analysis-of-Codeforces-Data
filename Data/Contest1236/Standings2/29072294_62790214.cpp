#include <bits/stdc++.h>

#define SZ(x) (((int)x.size()))

typedef long long ll;
typedef long double ld;

using namespace std;

const int maxn = 310;
int n;
vector<int> v[maxn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i & 1)
				v[j].push_back(i * n + j + 1);
			else
				v[n - 1 - j].push_back(i * n + j + 1);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (auto w : v[i])
			cout << w << " ";
		cout << endl;
	}
	return 0;
}
