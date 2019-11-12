#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	bool descending = false;
	vector<int> v[n];
	for (i = 0; i < n * n; i++)
	{
		j = i % n;
		if (descending)
			v[n - 1 - j].push_back(i + 1);
		else
			v[j].push_back(i + 1);
		if ((i + 1) % n == 0)
			descending = !descending;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < v[i].size(); j++)
			cout << v[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}