#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define fastio() ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define int long long
#define pb push_back
#define eb emblace_back
#define fi first
#define se second
#define PI acos(-1)
#define all(c) (c).begin(),(c).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

int modpow(int x, int n, int m) {
    x %= m;
    int res = 1;
    while(n > 0) {
        if(n & 1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

const ll inf = 2e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int32_t main() {
    fastio();
    srand(chrono::steady_clock::now().time_since_epoch().count());
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    int a[3][n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[0][i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[1][i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[2][i];
    }
    vi g[n + 1];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi d1;
    for(int i = 1; i <= n; i++) {
        if(g[i].size() == 1) {
            d1.pb(i);
        }
    }
    if(d1.size() != 2) {
        cout << -1;
        return 0;
    }
    vi v;
    bool vis[n + 1] = {0};
    int cur = d1[0];
    while(!vis[cur]) {
        v.pb(cur);
        vis[cur] = 1;
        for(auto it : g[cur]) {
            if(!vis[it]) {
                cur = it;
            }
        }
    }
    string s = "abc";
    int mn = inf;
    string ms;
    do {
        int tmp = 0;
        for(int i = 0; i < v.size(); i++) {
            if(s[i % 3] == 'a') {
                tmp += a[0][v[i]];
            }
            else if(s[i % 3] == 'b') {
                tmp += a[1][v[i]];
            }
            else {
                tmp += a[2][v[i]];
            }
        }
        mn = min(mn, tmp);
        if(mn == tmp) {
            ms = s;
        }
    } while(next_permutation(all(s)));
    cout << mn << endl;
    vi ans(n + 1);
    for(int i = 0; i < v.size(); i++) {
        if(ms[i % 3] == 'a') {
            ans[v[i]] = 1;
        }
        else if(ms[i % 3] == 'b') {
            ans[v[i]] = 2;
        }
        else {
            ans[v[i]] = 3;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}


