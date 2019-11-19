#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <iomanip>
#include <bitset>
#include <unordered_map>
#include <stack>
#include <memory.h>
#include <list>
#include <numeric>
#include <functional>
#include <complex>
#include <cassert>
#include <regex>
#include <random>

#define ll long long
#define ld long double
#define ull unsigned ll
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pii pair<int,int> 
#define pll pair<ll, ll> 
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vector<int>>
#define forn(it,from,to) for(ll (it)=from; (it)<to; (it)++)
ld pi = acos(-1.0);
using namespace std;
int n;
vi c[3];
vvi gr;
vi perm, used;

void dfs(int v) {
	used[v] = 1;
	perm.push_back(v);
	for (auto to : gr[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("hotel.in", "r", stdin);
	//freopen("hotel.out", "w", stdout);
	//reopen("input.txt", "r", stdin);
	//reopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	forn(i, 0, 3) {
		c[i].resize(n);
		forn(j, 0, n) cin >> c[i][j];
	}

	gr.resize(n);
	forn(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}

	int st = -1;
	forn(i, 0, n) {
		if (gr[i].size() > 2) {
			cout << -1;
			return 0;
		}
		if (gr[i].size() == 1) {
			st = i;
		}
	}
	used.resize(n);
	dfs(st);
	ll ANS = 1e18;
	int c1 = -1, c2;
	
	forn(i, 0, 3) {
		forn(j, 0, 3) {
			if (i == j) continue;
			vi colors;
			int v1 = perm[0], v2 = perm[1];
			ll ans = c[i][v1] + c[j][v2];
			colors.push_back(i);
			colors.push_back(j);
			forn(k, 2, n) {
				vi usd(3);
				usd[colors[colors.size() - 1]] = 1;
				usd[colors[colors.size() - 2]] = 1;
				forn(kk, 0, 3) {
					if (!usd[kk]) {
						colors.push_back(kk);
						ans += c[kk][perm[k]];
					}
				}
			}
			if (ans < ANS) {
				ANS = ans;
				c1 = i, c2 = j;
			}
		}
	}
	cout << ANS << '\n';
	vi anss(n);
	anss[perm[0]] = c1;
	anss[perm[1]] = c2;
	vi colors;
	colors.push_back(c1);
	colors.push_back(c2);
	forn(k, 2, n) {
		vi usd(3);
		usd[colors[colors.size() - 1]] = 1;
		usd[colors[colors.size() - 2]] = 1;
		forn(kk, 0, 3) {
			if (!usd[kk]) {
				colors.push_back(kk);
				anss[perm[k]] = kk;
			}
		}
	}
	forn(i, 0, n) {
		cout << anss[i] + 1 << ' ';
	}
	return 0;
}