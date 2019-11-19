//============================================================================
// Name        : codeforces.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stack>
using namespace std;

typedef long long ll;
const int MAX = 100005;
const int INF = 1e9;

const ll MOD = 1e9 + 7;

#define start first
#define finish second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)

struct edge {
	ll w;
	int x, y;
	edge() {
	}
	edge(int _x, int _y, ll _w) {
		x = _x, y = _y, w = _w;
	}
	bool operator<(const edge &e) const {
		return w < e.w;
	}
};

int P[MAX], k[MAX], c[MAX], n;
vector<edge> E, ee;
vector<int> T;
int find(int x) {
	if (P[x] == x)
		return x;
	else
		return find(P[x]);
}

void join(int x, int y) {
	int px = find(x);
	int py = find(y);
	P[px] = py;
}

int x[MAX], y[MAX];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		P[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
	}
	for (int i = 1; i <= n; i++) {
		E.pb(edge(0, i, c[i]));
		for (int j = 1; j < i; j++) {
			ll d = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (ll)(k[i] + k[j]);
			E.pb(edge(i, j, d));
		}
	}
	sort(all(E));
	int cc = n + 1;
	ll sol = 0;
	for (int i = 0; i < sz(E) && cc > 1; i++) {
		int a = E[i].x;
		int b = E[i].y;
		ll w = E[i].w;
		if (find(a) != find(b)) {
			join(a, b);
			cc--;
			sol += w;
			if (a == 0) {
				T.pb(b);
			} else {
				ee.pb(E[i]);
			}
		}
	}
	cout << sol << endl;
	cout << sz(T) << endl;
	for (int i = 0; i < sz(T); i++) {
		if (i)
			cout << " ";
		cout << T[i];
	}
	cout << endl;
	cout << sz(ee) << endl;
	for (int i = 0; i < sz(ee); i++) {
		cout << ee[i].x << " " << ee[i].y << endl;
	}
	return 0;
}
