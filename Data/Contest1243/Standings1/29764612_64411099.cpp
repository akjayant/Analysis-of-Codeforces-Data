#include <bits/stdc++.h>
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int p[100005], sz[100005];
void init(int n) {
	for(int i=1;i<=n;i++)
		p[i] = i, sz[i] = 1;
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}
bool unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return false;
	if(sz[rx] < sz[ry]) swap(rx, ry);
	p[ry] = rx;
	sz[rx] += sz[ry];
	return true;
}

map<pi, bool> rm;
set<int> s;

vi G[100005];

int cnt, n, m, bk[100005], b[100005], a[100005];

void dfs(int u, int k) {
	bk[u] = k;
	for(int v:G[u]) {
		if(s.count(v)) cnt++;
		else cnt--;
	}
	if(cnt == s.size() * (n - s.size())) return;
	vi adj;
	for(auto v:s) if(!rm[{u, v}]) adj.PB(v);
	for(int v:adj) s.erase(v);
	for(int v:adj) dfs(v, k);
}

signed main()
{
	
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		cin >> a[i] >> b[i];
		G[a[i]].PB(b[i]), G[b[i]].PB(a[i]);
		rm[{a[i], b[i]}] = rm[{b[i], a[i]}] = true;
	}
	for(int i=1;i<=n;i++) s.insert(i);
	int k = 1;
	while(s.size()) {
		int a = *s.begin(); s.erase(a);
		cnt = 0;
		dfs(a, k++);
	}
	init(k);
	int ans = 0;
	for(int i=0;i<m;i++) {
		if(unite(bk[a[i]], bk[b[i]]))
			ans++;
	}
	cout << ans << endl;
}
