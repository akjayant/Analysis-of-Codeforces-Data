
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <functional>
#include <map>
#include <cassert>
#include <bitset>
#include <iomanip>
#include <random>

using namespace std;

typedef long long ll;
#define pii pair<int, int>
#define mp make_pair

ll read() {
	int f = 1;
	ll res = 0;
	char ch;
	do {
		ch = getchar();
		if (ch == '-') f = -f;
	} while (ch < '0' || ch > '9');
	do {
		res = res * 10 + ch - '0';
		ch = getchar();
	} while (ch >= '0' && ch <= '9');
	return f == 1 ? res : -res;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int N = 2010;
int mod = 1000000007;
const ll INF = 1e18;
int n, m, q;

int A[N], B[N];
char str[N];

int head[N], to[N * 2], nxt[N * 2], tot = 1;
void addEdge(int u, int v, int val) {
	tot++;
	nxt[tot] = head[u];
	to[tot] = v;
	head[u] = tot;
}

template <class T>
T mmax(T a, T b) {
	return a < b ? b : a;
}

template <class T>
T mmin(T a, T b) {
	return a < b ? a : b;
}

int countOne(ll set) {
	int res = 0;
	while (set) {
		res++;
		set &= set - 1;
	}
	return res;
}

bool contain(int set, int i) {
	return (set & (1 << i)) > 0;
}

ll myPow(ll a, int p) {
	if (p == 0) return 1;
	ll res = myPow(a, p / 2);
	res *= res;
	res %= mod;
	if (p % 2 == 1) {
		res *= a;
		res %= mod;
	}
	return res;
}

void addMode(ll &a, ll b) {
	a = (a + b) % mod;
	if (a < 0) a += mod;
}

ll mul(ll a, ll b) {
	ll res = a * b % mod;
	if (res < 0) res += mod;
	return res;
}

template <class T>
void mySwap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int father[N];
int x[N], y[N];
int c[N], k[N];

int find(int x) {
	if (father[x] == x) return x;
	return father[x] = find(father[x]);
}

int table[12][12];
double dp[12][12][2];

void solve(int i, int j) {
	double ans = 1;
	for (int k = 1; k <= 6; k++) {
		int ni = i;
		int nj = j;
		if (i % 2 == 0) {
			nj = j - k;
			if (nj < 0) {
				ni--;
				nj = -nj - 1;
			}
		}
		else {
			nj = j + k;
			if (nj >= 10) {
				ni--;
				nj = 10 - (nj - 9);
			}
		}
		if (ni >= 0) {
			ans += min(dp[ni][nj][0], dp[ni][nj][1]) / 6;
		}
		else {
			ans += 1;
		}
	}
	dp[i][j][0] = dp[i][j][1] = ans;
	if (table[i][j]) {
		dp[i][j][1] = min(dp[i][j][1], dp[i - table[i][j]][j][0]);
	}
}

int main() {

	fast_io();
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
		cin >> table[i][j];
	}
	dp[0][0][0] = dp[0][0][1] = 0;
	for (int i = 0; i < 10; i++) 
		if (i % 2 == 0) for (int j = 0; j < 10; j++) {
			if (i == 0 && j == 0) continue;
			solve(i, j);
		}
		else {
			for (int j = 9; j >= 0; j--) {
				solve(i, j);
			}
		}
	cout.precision(12);
	cout << min(dp[9][0][0], dp[9][0][1]) << endl;
	//system("pause");
	return 0;
}