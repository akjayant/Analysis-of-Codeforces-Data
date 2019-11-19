#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll LINF = (1LL << 60) - 1LL;
constexpr ll MOD = 1e9 + 7;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<ll>> c(3, vector<ll>(n));
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        cin >> c[0][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[1][i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[2][i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int st = -1;
    for (int i = 0; i < n; i++) {
        if (G[i].size() >= 3) {
            cout << -1 << endl;
            return 0;
        }
        if (G[i].size() == 1) {
            st = i;
        }
    }
    vector<int> v;
    v.push_back(st);
    int id = G[st][0];
    int p = st;
    while (G[id].size() >= 2) {
        v.push_back(id);
        int tm = id;
        if (G[id][0] == p) {
            id = G[id][1];
        } else {
            id = G[id][0];
        }
        p = tm;
    }
    v.push_back(id);
    vector<int> co(n);
    ll mi = LINF;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                continue;
            }
            int a = i, b = j;
            ll s = c[i][v[0]] + c[j][v[1]];
            for (int k = 2; k < n; k++) {
                int d = 3 - (a + b);
                s += c[d][v[k]];
                a = b;
                b = d;
            }
            if (mi > s) {
                mi = s;
                co[v[0]] = i;
                co[v[1]] = j;
                a = i, b = j;
                for (int k = 2; k < n; k++) {
                    int d = 3 - (a + b);
                    co[v[k]] = d;
                    a = b;
                    b = d;
                }
            }
        }
    }
    cout << mi << endl;
    for (int i = 0; i < n; i++) {
        cout << co[i] + 1;
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}