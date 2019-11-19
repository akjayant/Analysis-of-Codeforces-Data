#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100000 + 5;

int n, m, p[N], sz[N], conn[N];

map <pair <int, int>, int> mp;
vector <vector <int> > v;
vector <int> comp[N];

int get_anc(int x){
    if (p[x] == x) return x;
    return p[x] = get_anc(p[x]);
}

void unite(int x, int y){
    x = get_anc(x);
    y = get_anc(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    for (auto u: comp[y]){
        comp[x].push_back(u);
        for (auto it: v[u]){
            if (get_anc(it) == x && mp[{u, it}])
            {
                conn[it]--;
                conn[u]--;
            }
        }
    }
    p[y] = x;
    sz[x] += sz[y];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        p[i] = i, sz[i] = 1;
        comp[i].push_back(i);
    }
    v.resize(n);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        --x; --y;
        v[x].push_back(y);
        v[y].push_back(x);
        conn[x]++;
        conn[y]++;
        mp[{x, y}] = mp[{y, x}] = 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (mp[{i, j}]) continue;
            unite(i, j);
            if (sz[get_anc(i)] + conn[i] == n) break;
        }
    }
    set <int> ms;
    for (int i = 0; i < n; i++)
        ms.insert(get_anc(i));
    cout << ms.size() - 1;
}
