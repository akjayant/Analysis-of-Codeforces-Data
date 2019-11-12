#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long li;
typedef unsigned long long uli;
typedef pair<int, int> pii;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define forb(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define vi vector<int>
#define x first
#define y second

const int INF = 2e9;
const li INF64 = 1e18;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = 3.14159265359;
const int N = 100 * 1000 + 10;

li binpow(li a, li n) {
	li res = 1ll;
	while (n)
		if (n & 1ll) {
			res = (res * a) % MOD;
			--n;
		}
		else {
			a = (a * a) % MOD;
			n /= 2;
		}
	return res;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> a(n);

	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i % 2 == 0) a[j - 1].pb(i * n + j);
			else a[n - j].pb(i * n + j);
		}
	}

	forn(i, n) {
		forn(j, n)
			cout << a[i][j] << " ";
		cout << '\n';
	}
}


