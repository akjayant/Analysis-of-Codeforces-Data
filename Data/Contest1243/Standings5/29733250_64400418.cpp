#pragma GCC target ("avx2,sse2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree <pair <ll, int>, null_type, less <pair <ll, int> >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define db long double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define mp make_pair
#define up_b upper_bound
#define low_b lower_bound
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define endl "\n"

#define left fsdkfsdfsdfd
#define sum dfsdfsdfsdf
#define assign sdkfskdfkk

//#define int long long

using namespace std;

void dout() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << H << ' ';
    dout(T...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <ll, int> pii;

int bit(signed x) {
    return __builtin_popcount(x);
}
int bit(ll x) {
    return __builtin_popcountll(x);
}

const int N = 1e5 + 7;
int n, m, comp;
set <int> q[N], st;
bool used[N];

void dfs(int v) {
    used[v] = true;
    st.erase(v);
    int x = 0;
    for (auto i : q[v]) {
        while (true) {
            auto it = st.upper_bound(x);
            if (it == st.end() || *it >= i) {
                break;
            }
            dfs(*it);
        }
        x = i;
    }
}

void solve(int tc) {
    // check for (int i = 0; i < n; j++)
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
        q[i].insert(n + 1);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        q[a].insert(b);
        q[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i);
            comp++;
        }
    }
    cout << comp - 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int tc = 1;
//    cin >> tc;
    for (int i = 0; i < tc; i++) {
        solve(i);
//        cleanup();
    }
}
