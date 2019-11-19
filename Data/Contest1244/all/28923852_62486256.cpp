#define _CRT_SECURE_NO_WARNINGS

/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/

#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <math.h>
#include <bitset>
#include <map>
#include <deque>
#include <queue>
#include <unordered_map>
#include <stack>
#include <random>
#include <tuple>
#include <string.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pp;
typedef tuple<int, int, int> tt;
typedef unsigned int ui;

const int inf = (int)1e9;
const int mod = inf + 7;
//const int mod = 998244353;
//const ll inf = (ll)1e18;

#define umap unordered_map
#define Power ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()

vector<vector<int>> c;
vector<vector<int>> t;
vector<int> q;

void dfs(int v, int p=-1) {
	q.push_back(v);
	for (auto to : t[v])
		if (to != p)
			dfs(to, v);
}

int main() {

	Power;

	int n;
	cin >> n;
	c = vector<vector<int>>(3, vector<int>(n));
	t.resize(n);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < n; j++)
			cin >> c[i][j];

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		t[a].push_back(b);
		t[b].push_back(a);
		if (t[a].size() > 2 || t[b].size() > 2) {
			cout << -1;
			return 0;
		}
	}

	int s = -1;

	for (int i = 0; i < n; i++)
		if (t[i].size() == 1) {
			s = i;
			break;
		}

	dfs(s);

	ll ans = -1;
	int a, b;

	for (int aa = 0; aa < 3; aa++)
		for (int ba = 0; ba < 3; ba++) {
			if (aa == ba)
				continue;
			int x, y;
			x = aa;
			y = ba;
			ll sum = c[x][q[0]] + c[y][q[1]];
			for (int i = 2; i < n; i++) {
				sum += c[3 - x - y][q[i]];
				int z = 3 - x - y;
				x = y;
				y = z;
			}
			if (ans == -1 || ans > sum)
				ans = sum, a = aa, b = ba;
		}

	cout << ans << "\n";
	vector<int> e(n);
	e[q[0]] = a;
	e[q[1]] = b;
	int x = a;
	int y = b;
	for (int i = 2; i < n; i++) {
		e[q[i]] = 3 - x - y;
		int z = 3 - x - y;
		x = y;
		y = z;
	}

	for (auto it : e)
		cout << it + 1 << " ";

	return 0;
}