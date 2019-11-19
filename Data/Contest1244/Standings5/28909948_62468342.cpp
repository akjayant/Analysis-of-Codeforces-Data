#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
using namespace std;

#define F first
#define S second
#define pb push_back
#define pii pair <int, int>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define reunique(x) (x).resize(std::unique(all(x)) - (x).begin())
#define roflan ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ld long double
#define int long long

void Solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int fst = -1, lst = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] != '1') continue;
		if (fst == -1)
			fst = i;
		lst = i;
	}
	if (fst == -1) {
		cout << n << '\n';
		return;
	}
	int t1 = lst + 1 + n - lst;
	int t2 = (lst + 1) * 2;
	int t3 = fst + 1 + n - fst;
	int t4 = (n - fst) * 2;
	int ans = max({t1, t2, t3, t4});
	cout << ans << '\n';
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int Q;
	cin >> Q;
	while (Q--)
		Solve();

	return 0;
}