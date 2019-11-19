
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

priority_queue<pair<ll, pair<int, int>>> pq;

int main() {

	fast_io();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		cin >> y[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	for (int i = 0; i <= n; i++) father[i] = i;

	for (int i = 0; i < n; i++) {
		pq.push(mp(-c[i], mp(i, n)));
	}
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		ll dis = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		pq.push(mp(-dis * (k[i] + k[j]), mp(i, j)));
	}

	ll res = 0;
	vector<int> build;
	vector<pair<int, int>> elect;

	while (!pq.empty()) {
		pair<ll, pair<int, int>> cur = pq.top(); pq.pop();
		int fa = find(cur.second.first);
		int fb = find(cur.second.second);
		if (fa == fb) continue;
		res += -cur.first;
		if (cur.second.second == n) {
			build.push_back(cur.second.first + 1);
		}
		else {
			elect.push_back(mp(cur.second.first + 1, cur.second.second + 1));
		}
		father[fa] = fb;
	}

	cout << res << endl;
	cout << build.size() << endl;
	for (int i = 0; i < build.size(); i++) {
		if (i != 0) cout << ' ';
		cout << build[i];
	}
	cout << endl;
	cout << elect.size() << endl;
	for (int i = 0; i < elect.size(); i++) {
		cout << elect[i].first << " " << elect[i].second << "\n";;
	}

	//system("pause");
	return 0;
}