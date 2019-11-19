#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2000;
int n;
int a[MAX_N + 9];
int b[MAX_N + 9];
int c[MAX_N + 9];
int d[MAX_N + 9];
vector<tuple<long long, int, int>> vEdge;
int par[MAX_N + 9];
long long ans1;
vector<int> ans2;
vector<pair<int, int>> ans3;

void makeSet(int x) {
	par[x] = x;
}

int findSet(int x) {
	if(par[x] != x) {
		par[x] = findSet(par[x]);
	}
	return par[x];
}

void unionSet(int x, int y) {
	x = findSet(x);
	y = findSet(y);
	if(x == y) {
		return;
	}
	par[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	for(int i = 1; i <= n; i++) {
		vEdge.push_back(make_tuple(c[i], i, n + 1));
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			vEdge.push_back(make_tuple((long long)(d[i] + d[j]) * (abs(a[i] - a[j]) + abs(b[i] - b[j])), i, j));
		}
	}
	sort(vEdge.begin(), vEdge.end());
	for(int i = 1; i <= n + 1; i++) {
		makeSet(i);
	}
	ans1 = 0;
	for(int i = 0; i < vEdge.size(); i++) {
		int z = get<0>(vEdge[i]);
		int x = get<1>(vEdge[i]);
		int y = get<2>(vEdge[i]);
		if(findSet(x) != findSet(y)) {
			unionSet(x, y);
			ans1 += z;
			if(y == n + 1) {
				ans2.push_back(x);
			}
			else {
				ans3.push_back(make_pair(x, y));
			}
		}
	}
	cout << ans1 << "\n";
	cout << ans2.size() << "\n";
	for(int i = 0; i < ans2.size(); i++) {
		cout << ans2[i] << " ";
	}
	cout << "\n";
	cout << ans3.size() << "\n";
	for(int i = 0; i < ans3.size(); i++) {
		cout << ans3[i].first << " " << ans3[i].second << "\n";
	}
	return 0;
}