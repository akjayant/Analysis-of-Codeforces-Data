#include <bits/stdc++.h>
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define out(t, a) copy(all(a), ostream_iterator<t>(cout, " ")); cout << "\n";
// #define int long long
// #define DEBUG

using namespace std;
 
void set_program() {
	#ifdef DEBUG
		freopen ("test.in", "r", stdin);
		freopen ("test.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
 
// typedef long long ll;

// const int INF = 1e9 + 1;
// const int MOD = 1e9 + 7;

 
main() {
	set_program();
	int n;
	cin >> n;
	vector <vector <int>> ans(n);
	vector <int> cur(n);
	iota(all(cur), 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans[cur[j]].push_back(n * i + j + 1);
		}
		reverse(all(cur));
	}
	for (auto v : ans) {
		out(int, v);
	}
 	return 0;
}
