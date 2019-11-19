#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned ll
#define vi vector<ll>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair<ll, ll>
#define mt make_tuple
#define mn(a, b) a = min(a, b)
#define mx(a, b) a = max(a, b)
 
using namespace std;
 
const ll INF = (ll)2e9;
const ll inf = (ll)2e18;
const ld eps = (ld)1e-6;
const ll mod = (ll)1e9 + 7;
const ll MAXN = 2510;
const ll MAXC = (ll)6e6;
const ll MAXLOG = 65;
const ll maxlen = (ll)1e5;
const ll asci = (ll)256;
const ll block = 707;
//
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<
ll,
null_type,
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;*/
 
template <class T>
istream& operator >>(istream &in, vector<T> &arr){
     for (T &cnt : arr) {
        in >> cnt;
    }
    return in;
};

struct edge{
    int u, c, f = 0;
    edge* back;

    edge(int _u, int _c): u(_u), c(_c){}
    edge() {}
};

vector<edge*> graph[MAXN];
edge g[4 * MAXN];
int used[MAXN];
int dist[MAXN];
pair<int, edge*> p[MAXN];

int sz = 0;
void push(edge e) {
    g[sz] = e;
    sz++;
}

void add(int v, int u, int cap) {
    push(edge(u, cap));
    push(edge(v, cap));
    g[sz - 1].back = &g[sz - 2];
    g[sz - 2].back = &g[sz - 1];
    graph[v].push_back(&g[sz - 2]);
    graph[u].push_back(&g[sz - 1]);
}

void bfs(int s, int c) {
    queue<int> q;
    q.push(s);
    used[s] = c;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto e : graph[v]) {
            if (used[e->u] != c && e->c - e->f) {
                dist[e->u] = dist[v] + 1;
                used[e->u] = c;
                p[e->u] = {v, e};
                q.push(e->u);
            }
        }
    }
}

int karp(int s, int t, int c) {
    bfs(s, c);
    if (used[t] != c) return 0;
    int minc = INF;
    int v = t;
    while (v != s) {
        minc = min(minc, p[v].second->c - p[v].second->f);
        v = p[v].first;
    }
    v = t;
    while (v != s) {
        p[v].second->f += minc;
        p[v].second->back->f -= minc;
        v = p[v].first;
    }
    return minc;
}
 
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int mn, mx;
    for (int i = 0; i < n; ++i) {
        if (s[i] - '0') {mn = i; break;}
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] - '0') {mx = i; break;}
    }
    if (s == string(n, '0')) cout << n << "\n";
    else cout << max((mx + 1) * 2, (n - mn) * 2) << "\n";
}
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    cout.precision(30);
    int t; cin >> t;
    while(t--)
    solve();
 
    return 0;
}