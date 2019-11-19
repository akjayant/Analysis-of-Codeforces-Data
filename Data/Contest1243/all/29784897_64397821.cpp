#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define int long long

const int N = 1e5 + 1;
set<int> g[N];

int p[N];
int sz[N];
int get(int v) {
    if (p[v] == v) {
        return v;
    }
    return  p[v] = get(p[v]);
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    p[b] = a;
    if (sz[a] == sz[b]) {
        ++sz[a];
    }
}

void dfs(int v, vector<int> &used, set<int> &left) {
    used[v] = true;
    left.erase(v);
    int last = 0;
    while (true) {
        auto it = left.upper_bound(last);
        if (it != left.end()) {
            last = *it;
            if (g[v].find(last) == g[v].end()) {
                unite(last, v);
                dfs(last, used, left);
            }
        } else {
            break;
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);

   int n, m;
   cin >> n >> m;
   for (int i = 1; i <= n; ++i) {
       p[i] = i;
   }
   for (int i = 0; i < m; ++i) {
       int a, b;
       cin >> a >> b;
       g[a].insert(b);
       g[b].insert(a);
   }
   vector<int> v(n);
   vector<int> used(n + 1);
   set<int> left;
   for (int i = 0; i < n; ++i) {
       v[i] = i + 1;
       left.insert(i + 1);
   }
   sort(all(v), [&](int a, int b) {
       return g[a].size() < g[b].size();
   });
    for (auto u : v) {
        if (!used[u]) {
            dfs(u, used, left);
        }
    }
   vector<int> clr(n + 1);
   for (int i = 1; i <= n; ++i) {
       clr[get(i)] = 1;
   }
   cout << count(all(clr), 1) - 1;
}