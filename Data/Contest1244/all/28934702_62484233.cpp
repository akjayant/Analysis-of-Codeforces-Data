#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <set>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <cmath>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e18, MOD = 1e9 + 7, MOD2 = 1e6 + 3;

ll c[100000][3], b[100000];

vector <int> g[100000];

vector <int> v;

void dfs (int x, int p) {

	for (int to : g[x]) 
		if (to != p) {
			dfs (to, x);
		}
	v.push_back (x);
}

int main () {
	int start, n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf ("%lld", &c[i][0]);
	}
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &c[i][1]);
	}
	for (int i = 0; i < n; i++) {
		scanf ("%lld", &c[i][2]);
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf ("%d%d", &u, &v);
		g[u-1].push_back (v - 1);
		g[v-1].push_back (u - 1);
	}

	for (int i = 0; i < n; i++) {
		if (g[i].size () > 2) {
			cout << -1 << endl;
			return 0;
		}
		if (g[i].size () == 1)
			start = i;
	}

	dfs (start, -1);

	ll r[6], p[3], mn = INF;

	for (int k = 0; k < 6; k++) {
		r[k] = 0;
		p[0] = k / 2 + 1;
		if (p[0] == 1) {
			p[1] = 2;
			p[2] = 3;
		}
		else if (p[0] == 2) {
			p[1] = 1;
			p[2] = 3;
		}
		else {
			p[1] = 1;
			p[2] = 2;
		}

		if (k & 1) swap (p[1], p[2]);

		for (int i = 0; i < n; i++) {
			r[k] += c[v[i]][p[i % 3] - 1];
		}
	}

	for (int i = 0; i < 6; i++) {
		mn = min (mn, r[i]);
	}

	for (int i = 0; i < 6; i++) 
		if (r[i] == mn) {
			cout << mn << endl;

			p[0] = i / 2 + 1;
			if (p[0] == 1) {
				p[1] = 2;
				p[2] = 3;
			}
			else if (p[0] == 2) {
				p[1] = 1;
				p[2] = 3;
			}
			else {
				p[1] = 1;
				p[2] = 2;
			}

			if (i & 1) swap (p[1], p[2]);

			for (int i = 0; i < n; i++) {
				b[v[i]] = p[i % 3];
			}

			break;
		}

	for (int i = 0; i < n; i++)
		printf("%lld ", b[i]);
}