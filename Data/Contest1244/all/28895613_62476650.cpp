#include <stdio.h>
#include <stack>
#include <map>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#include <climits>
#include <unordered_map>
#include <iterator> 
#include <bitset>
#include <complex>
#include <random>
#include <chrono>
#include <functional>
using namespace std;
typedef complex<double> cd;
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define mp make_pair
#define inf32 INT_MAX
#define inf64 LLONG_MAX
#define PI acos(-1)
#define cos45 cos(PI/4)
#define ld long double
#define inf INT_MAX
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pil pair<int, ll>
#pragma GCC optimize("O3")
//#define x first
//#define y second
const int mods[10] = { 1000000007, 999999937, 999999929, 999999893, 999999883, 999999797, 999999761, 999999757, 999999751, 999999739 };
const int mod = 1000000007;
int rand_mods[2];
const long double eps = 1e-10;
const int siz = 1e5 + 5, siz2 = (1 << 20) + 5, lg = 21, block = 448, block2 = 1000, mxv = 5e5, sqrt_mod = 31630;
const int alpha_sz = 26;

int n, c[siz][4], bc[siz][4][4], leaf, ans[siz];
vector<int> adj[siz];
ll dp[siz][4][4];

ll solve(int node, int p, int pc, int ppc) {
	ll &dpv = dp[node][pc][ppc];
	if (dpv != -1) {
		return dpv;
	}
	ll mn = LLONG_MAX;
	for (int i = 1; i <= 3; i++) {
		if (i != pc && i != ppc) {
			bool ent = 0;
			for (int a : adj[node]) {
				if (a != p) {
					ent = 1;
					ll op = c[node][i] + solve(a, node, i, pc);
					if (op < mn) {
						bc[node][pc][ppc] = i;
						mn = op;
					}
				}
			}
			if (!ent) {
				if (c[node][i] < mn) {
					bc[node][pc][ppc] = i;
					mn = c[node][i];
				}
			}
		}
	}
	return dpv = mn;
}

void fillans(int node, int p, int pc, int ppc) {
	ans[node] = bc[node][pc][ppc];
	for (int a : adj[node]) {
		if (a != p) {
			fillans(a, node, ans[node], pc);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i][1]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i][2]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i][3]);
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		int sz = adj[i].size();
		if (sz > 2) {
			printf("-1\n");
			return 0;
		}
		else if (sz == 1) {
			leaf = i;
		}
	}
	if (leaf == 0) {
		leaf = 1;
	}
	memset(dp, -1, sizeof dp);
	printf("%I64d\n", solve(leaf, 0, 0, 0));
	fillans(leaf, 0, 0, 0);
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
 	return 0;
}