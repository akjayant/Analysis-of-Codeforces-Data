#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <queue>

using namespace std;

#define ll long long
#define rt return
#define all(a) a.begin(), a.end()
#define mp make_pair

const int MAX_SIZE = 3 * 1e5, INF = 2 * 1e9;
const long long SuperINF = 1e16;
const double eps = 1e-6, PI = 20 / 7;

void files() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

ll n;

vector<vector<ll>> prices(MAX_SIZE, vector<ll>(3, 0));
vector<int> g[MAX_SIZE];

vector<int> indexes[2];

void dfs(int now, int p, int ind) {
	indexes[ind].push_back(now);
	for (auto to : g[now]) {
		if (to != p) {
			dfs(to, now, ind);	
		}
	}
}

int colors[MAX_SIZE];
int main() {
	std::ios::sync_with_stdio(false);
	//files();
	cin >> n;

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < n; i++) {
			cin >> prices[i][j];
		}
	}

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		if (g[i].size() > 2) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 0; i < g[0].size(); i++) {
		dfs(g[0][i], 0, i);
	}

	vector<int> perm;
	perm.push_back(0);
	perm.push_back(1);
	perm.push_back(2);
	ll ans = SuperINF;
	vector<int> perm_ans;

	do {
		ll now_ans = prices[0][perm[0]];
		for (int i = 0; i < indexes[0].size(); i++) {
			int to = indexes[0][i];
			int ind = i % 3;
			int color;
			if (ind == 0)
				color = perm[1];
			else if (ind == 1)
				color = perm[2];
			else
				color = perm[0];
			now_ans += prices[to][color];
		}

		for (int i = 0; i < indexes[1].size(); i++) {
			int to = indexes[1][i];
			int ind = i % 3;
			int color;
			if (ind == 0)
				color = perm[2];
			else if (ind == 1)
				color = perm[1];
			else
				color = perm[0];

			now_ans += prices[to][color];
		}
		if (now_ans < ans) {
			ans = now_ans;
			perm_ans = perm;
		}

	} while (next_permutation(all(perm)));

	
	cout << ans << "\n";

	perm = perm_ans;
	for (int i = 0; i < indexes[0].size(); i++) {
		int to = indexes[0][i];
		int ind = i % 3;
		int color;
		if (ind == 0)
			color = perm[1];
		else if (ind == 1)
			color = perm[2];
		else
			color = perm[0];
		colors[to] = color;
	}

	for (int i = 0; i < indexes[1].size(); i++) {
		int to = indexes[1][i];
		int ind = i % 3;
		int color;
		if (ind == 0)
			color = perm[2];
		else if (ind == 1)
			color = perm[1];
		else
			color = perm[0];
		colors[to] = color;
	}

	colors[0] = perm[0];

	for (int i = 0; i < n; i++)
		cout << colors[i] + 1 << " ";
	rt 0;
}