#include <bits/stdc++.h>
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define N 100005
#define mod 1000000007

using namespace std;

int n, m, dd[N], cnt, res;
vector<int> g[N];
set<int> s;

void DFS(int u) {
    dd[u] = 1;
    cnt++;
    set<int> tmp = s;
    for (auto v : g[u])
        tmp.erase(v);
    for (auto v : tmp) {
        s.erase(v);
    }
    for (auto v : tmp) {
        DFS(v);
    }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("INP.TXT", "r")) {
		freopen("INP.TXT", "r", stdin);
    }
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].PB(v);
        g[v].PB(u);
    }
    FOR(i, 1, n) s.insert(i);
    //int res = 0;
    FOR(i, 1, n) {
        if (dd[i]) continue;
        res++;
        s.erase(i);
        DFS(i);
    }
    cout <<res-1;
}

