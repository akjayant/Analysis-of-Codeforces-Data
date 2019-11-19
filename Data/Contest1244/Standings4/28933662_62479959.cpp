#include  <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
using ll = long long;

int n;
ll c[3][maxn];
vector<int> g[maxn];
vector<bool> vis(maxn);
vector<int> order;

vector<int> color(vector<int> p) {
	vector<int> ret(n);
	for(int i = 0; i < n; i++) {
		ret[i] = p[i % 3];
	} return ret;
}

ll cost(vector<int> p) {
	ll ret = 0;
	for(int i = 0; i < n; i++) {
		ret += c[p[i]][order[i]];
	} return ret;
}

void dfs(int u) {
	order.emplace_back(u);
	vis[u] = 1;
	for(int v : g[u]) if(!vis[v]) {
		dfs(v);
	}
}

int main(int argc, char const *argv[])
{
	// freopen("in", "r", stdin);
	cin >> n;
	for(int j = 0; j < 3; j++) {
		for(int i = 0; i < n; i++) {
			cin >> c[j][i];
		}
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	for(int i = 0; i < n; i++) {
		if(g[i].size() > 2) {
			cout << "-1" << endl;
			exit(0);
		}
	}
	int s = -1;
	for(int i = 0; i < n; i++) {
		if(g[i].size() == 1) {
			s = i;
			break;
		}
	}
	dfs(s);
	ll opt = 1e18;
	vector<int> arg;
	vector<int> p = {0, 1, 2};
	do {
		vector<int> tmp = color(p);
		if(cost(tmp) < opt) {
			opt = cost(tmp);
			arg = tmp;
		}
	} while(next_permutation(p.begin(), p.end()));
	vector<int> col(n);
	for(int i = 0; i < n; i++) {
		col[order[i]] = arg[i];
	}
	cout << cost(arg) << endl;
	for(int i : col) cout << i + 1 << ' '; cout << endl;
	return 0;
}