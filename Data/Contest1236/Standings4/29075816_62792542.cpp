#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define endl '\n'

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed << setprecision(20);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n * n);
	for (int i = 0; i < n * n; ++i) {
		int x = ((i / n) % 2 ? -1 : 1);
		a[i] = x * (i % n + 1);
		if (a[i] < 0) a[i] += n + 1;
		--a[i];
	}

	vector<vector<int> > res(n);
	for (int i = 0; i < n * n; ++i) res[a[i]].pb(i + 1);
	for (auto& i : res) {
		for (auto& j : i) cout << j << ' ';
		cout << endl;
	}
}