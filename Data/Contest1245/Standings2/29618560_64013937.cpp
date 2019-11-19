#include <bits/stdc++.h>
using namespace std;

const int dim = 2010;
const int mod = 1000000007;

int dsu[dim];
int get_root(int node) {
    int aux = node;
    while (dsu[node] > 0)
        node = dsu[node];
    int root = node;
    node = aux;
    while (node != root) {
        aux = dsu[node];
        dsu[node] = root;
        node = aux;
    }
    return root;
}
bool join(int x, int y) {
    x = get_root(x);
    y = get_root(y);
    if (x == y)
        return false;
    if (dsu[x] < dsu[y])
        dsu[x] += dsu[y], dsu[y] = x;
    else
        dsu[y] += dsu[x], dsu[x] = y;
    return true;
}

void solve() {
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    vector<int> c(n);
    for (auto& it : c)
        cin >> it;
    vector<int> k(n);
    for (auto& it : k)
        cin >> it;
    
    vector<tuple<long long, int, int>> edges;
    for (int i = 0; i < n; ++i)
        edges.emplace_back(c[i], i, n);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            edges.emplace_back(1LL * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), i, j);
    
    sort(edges.begin(), edges.end());
    memset(dsu, -1, sizeof dsu);
    long long ans = 0;
    vector<int> stations;
    vector<pair<int, int>> connections;
    for (auto&& edge : edges) {
        long long cst; int a, b;
        tie(cst, a, b) = edge;
        if (join(a, b)) {
            ans += cst;
            if (b == n)
                stations.push_back(a + 1);
            else
                connections.emplace_back(a + 1, b + 1);
        }
    }

    cout << ans << '\n';
    cout << stations.size() << '\n';
    for (auto it : stations)
        cout << it << ' ';
    cout << '\n' << connections.size() << '\n';
    for (auto it : connections)
        cout << it.first << ' ' << it.second << '\n';

}

int main() {
    #ifdef LOCAL
        freopen("date.in", "r", stdin);
    #endif
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}