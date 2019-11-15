
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

const int N = 300010;
int mod = 998244353;
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

int main() {

	fast_io();
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		cin >> n;
		int a, b, c;
		cin >> a >> b >> c;
		cin >> str;
		int cnt = 0;
		vector<char> res(n, ' ');
		for (int i = 0; i < n; i++) {
			char ch = str[i];
			if (ch == 'R') {
				if (b > 0) {
					res[i] = 'P';
					b--;
					cnt++;
				}
			}
			else if (ch == 'P') {
				if (c > 0) {
					res[i] = 'S';
					c--;
					cnt++;
				}
			}
			else {
				if (a > 0) {
					res[i] = 'R';
					a--;
					cnt++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (res[i] == ' ') {
				if (a > 0) {
					res[i] = 'R';
					a--;
				}
				else if (b > 0) {
					res[i] = 'P';
					b--;
				}
				else {
					res[i] = 'S';
					c--;
				}
			}
		}
		if (cnt >= (n + 1) / 2) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) {
				cout << res[i];
			}
			cout << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	//system("pause");
	return 0;
}