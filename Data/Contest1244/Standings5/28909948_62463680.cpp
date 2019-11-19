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
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	int x = (a + c - 1) / c;
	int y = (b + d - 1) / d;
	if (x + y > k) {
		cout << -1 << '\n';
	}
	else {
		cout << x << ' ' << y << '\n';
	}
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