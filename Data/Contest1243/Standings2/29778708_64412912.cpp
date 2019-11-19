#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ii pair <int, int>
#define MP make_pair
#define F first
#define S second
#define L(x) ((x << 1) + 1)
#define R(x) ((x << 1) + 2)
#define mid(l, r) (l + r >> 1)
#define PB push_back
#define trace(x) cerr << #x << " = " << x << endl;
#define MAX 100010

int nxt[MAX];
bool visited[MAX];
int n;
map <int, bool> edgeMap[MAX];

int getNext(int pos) {
	if (nxt[pos] >= MAX)
		return nxt[pos];
	if (visited[nxt[pos]])
		return nxt[pos] = getNext(nxt[pos]);
	return nxt[pos];

}

void dfs(int pos) {
	visited[pos] = true;

	for (int i=getNext(0) ; i<=n ; ) {
		if (!visited[i] and !edgeMap[pos].count(i))
			dfs(i);
		i = getNext(i);
	}
}

signed main() {
	fast_io;

	int m;

	cin >> n >> m;

	for (int i=0 ; i<MAX ; ++i)
		nxt[i] = i + 1;

	int u, v;
	for (int i=0 ; i<m ; ++i) {
		cin >> u >> v;
		edgeMap[u][v] = true;
		edgeMap[v][u] = true;
	}

	int comps = 0;
	for (int i=1 ; i<=n ; ++i) {
		if (!visited[i]) {
			dfs(i);
			comps++;
		}
	}

	cout << comps - 1 << endl;
}