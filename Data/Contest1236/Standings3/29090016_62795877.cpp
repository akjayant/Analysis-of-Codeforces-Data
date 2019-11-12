#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")
#include"bits/stdc++.h"
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define ends ' '
#define endl '\n'
#define pb emplace_back
#define x first
#define y second
#define pii pair<int, int>
#define sz(x) (int)(x).size()

int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	IOS;

	int n;
	cin >> n;

	int cur = 0;

	int a[n][n];

	bool odd = 0;

	for(int i = 0; i < n; ++i) {
		odd = !odd;
		for(int j = 0; j < n; ++j) {
			++cur;

			if(!odd)
				a[i][j] = cur;
			else
				a[i][n-j-1] = cur;
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << a[j][i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}