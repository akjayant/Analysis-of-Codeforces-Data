#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace std;

typedef unsigned long long ull;

int n;
const int MAX_N = 100001;
ull c[3][MAX_N];
vector<int>tree[MAX_N];
bool used[MAX_N];
int color[MAX_N];
ull sum = 0;
int start;

void dfs(int v, int color1, int color2) {
	used[v] = true;
	color[v] = 3 - color1 - color2;
	sum += c[color[v]][v];
//	cerr << v << ' ' << color1 << ' ' << color2 << ' ' << sum << '\n';
	for (int i = 0; i < tree[v].size(); i++) {
		if (!used[tree[v][i]]) {
			dfs(tree[v][i], color2, color[v]);
		}
	}
}

ull f(int color1, int color2) {
	for (int i = 0; i < n; i++) {
		used[i] = false;
		color[i] = -1;
	}

	sum = 0;
	color[start] = color1;
	color[tree[start][0]] = color2;
	used[start] = true;
	used[tree[start][0]] = true;
	sum += c[color1][start];
	sum += c[color2][tree[start][0]];
	int v2 = tree[start][0];

//	cout << start << ' ' << tree[start][0] << '\n';

	for (int i = 0; i < tree[v2].size(); i++) {
		if (!used[tree[v2][i]]) {
			dfs(tree[v2][i], color1, color2);
		}
	}

//	cout << sum << endl;
	return sum;

}

int main() {
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u - 1].push_back(v - 1);
		tree[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < n; i++) {
		if (tree[i].size() == 1) {
			start = i;
		}
		if (tree[i].size() > 2) {
			cout << -1;
			return 0;
		}
	}

	int ans[MAX_N];
	ull m = LLONG_MAX;

	if (f(0, 1) < m) {
		m = f(0, 1);
		for (int i = 0; i < n; i++) {
			ans[i] = color[i];
		}
	}
	if (f(0, 2) < m) {
		m = f(0, 2);
		for (int i = 0; i < n; i++) {
			ans[i] = color[i];
		}
	}
	if (f(1, 0) < m) {
		m = f(1, 0);
		for (int i = 0; i < n; i++) {
			ans[i] = color[i];
		}
	}
	if (f(1, 2) < m) {
		m = f(1, 2);
		for (int i = 0; i < n; i++) {
			ans[i] = color[i];
		}
	}
	if (f(2, 0) < m) {
		m = f(2, 0);
		for (int i = 0; i < n; i++) {
			ans[i] = color[i];
		}
	}
	if (f(2, 1) < m) {
		m = f(2, 1);
		for (int i = 0; i < n; i++) {
			ans[i] = color[i];
		}
	}
	
	cout << m << endl;
	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1 << ' ';
	}



}