#include <bits/stdc++.h>
 
using namespace std;
 
const int M = 2e5 + 5;
int n, m, ans, sz;
bool vis[M];
vector <int> adj[M], v;
set <int> s;
 
void dfs (int u) {
    s.erase(u);
    sz++;
    for (int i = 0; i+1 < adj[u].size(); i++) {
        int l = adj[u][i];
        int r = adj[u][i+1];
        if (l <= r) {
            while (s.size()) {
                auto it = s.upper_bound(l);
                if (it == s.end() || *it >= r) break;
                int nxt = *it;
                //s.erase(it);
                dfs(nxt);
            }
        }
    }
}
 
int main () {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back (v);
        adj[v].push_back (u);
    }
    for (int i = 1;i <= n; i++) {
        s.insert (i);
        adj[i].push_back (0);
        adj[i].push_back (n+1);
        sort (adj[i].begin(), adj[i].end());
    }
    for (int i = 1; i <= n; i++) {
        if (s.find(i) == s.end()) continue;
        dfs (i);
        ans++;
        v.push_back (sz);
        sz = 0;
    }
    printf("%d\n", ans-1);
}