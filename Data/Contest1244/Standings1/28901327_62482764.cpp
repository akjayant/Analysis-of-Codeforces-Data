#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

ll INF = (ll) 1e20;
int iINF = (int) 1e20;
ll mod = (ll) 1e9 + 7;

ll c1[100001];
ll c2[100001];
ll c3[100001];

ll get(ll v, vector<vector<ll>> &nodes, ll a, ll b, ll c, vector<ll> &cols, ll now, ll p) {
    ll ans = 0;
    if (now % 3 == 0) {
        cols[v] = a;
        if (a == 1) {
            ans = c1[v];
        }
        if (a == 2) {
            ans = c2[v];
        }
        if (a == 3) {
            ans = c3[v];
        }
    }
    if (now % 3 == 1) {
        cols[v] = b;
        if (b == 1) {
            ans = c1[v];
        }
        if (b == 2) {
            ans = c2[v];
        }
        if (b == 3) {
            ans = c3[v];
        }
    }
    if (now % 3 == 2) {
        cols[v] = c;
        if (c == 1) {
            ans = c1[v];
        }
        if (c == 2) {
            ans = c2[v];
        }
        if (c == 3) {
            ans = c3[v];
        }
    }
    for (auto i : nodes[v]) {
        if (p != i) {
            ans += get(i, nodes, a, b, c, cols, now + 1, v);
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c2[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c3[i];
    }
    vector < vector < ll > > nodes(n);
    for (int i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    ll start = 0;
    for (int i = 0; i < n; ++i) {
        if (nodes[i].size() > 2) {
            cout << -1;
            return 0;
        }
        if (nodes[i].size() == 1) {
            start = i;
        }
    }
    vector < ll > vec, tmp;
    ll sum;
    ll ans = INF;
    tmp.clear();
    tmp.resize(n);
    sum = get(start, nodes, 1, 2, 3, tmp, 0, -1);
    if (sum < ans) {
        vec = tmp;
        ans = sum;
    }
    tmp.clear();
    tmp.resize(n);
    sum = get(start, nodes, 1, 3, 2, tmp, 0, -1);
    if (sum < ans) {
        vec = tmp;
        ans = sum;
    }
    sum = get(start, nodes, 2, 1, 3, tmp, 0, -1);
    if (sum < ans) {
        vec = tmp;
        ans = sum;
    }
    tmp.clear();
    tmp.resize(n);
    sum = get(start, nodes, 2, 3, 1, tmp, 0, -1);
    if (sum < ans) {
        vec = tmp;
        ans = sum;
    }
    sum = get(start, nodes, 3, 1, 2, tmp, 0, -1);
    if (sum < ans) {
        vec = tmp;
        ans = sum;
    }
    tmp.clear();
    tmp.resize(n);
    sum = get(start, nodes, 3, 2, 1, tmp, 0, -1);
    if (sum < ans) {
        vec = tmp;
        ans = sum;
    }
    cout << ans << '\n';
    for (auto i : vec) {
        cout << i << ' ';
    }
}
