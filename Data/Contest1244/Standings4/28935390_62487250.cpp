//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define sqr(a) (a * a)
#define ll long long
#define ull unsigned long long
#include <bits/stdc++.h>
using namespace std;
//#define int long long

vector<vector<ll>> gr;

vector<ll> df;

void dfs(ll v, ll p) {
    df.push_back(v);
    for (ll to : gr[v]) {
        if (to == p)
            continue;
        dfs(to, v);
    }
}

void solve() {
    
    ll n;
    cin >> n;

    vector<vector<ll>> v(3, vector<ll>(n));

    for (ll & i : v[0])
        cin >> i;
    
    for (ll & i : v[1])
        cin >> i;
    
    for (ll & i : v[2])
        cin >> i;

    gr.resize(n);

    for (ll i = 0; i + 1 < n; ++i) {
        ll a, b;
        cin >> a >> b;
        --a, --b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for (ll i = 0; i < n; ++i) {
        if (gr[i].size() >= 3) {
            cout << "-1\n";
            return;
        }
    }

    ll st;

    for (ll i = 0; i < n; ++i) {
        if (gr[i].size() == 1) {
            st = i;
            break;
        }
    }

    ll ma = -1, mb = -1, mc = -1;
    long long fans = 1e18;

    dfs(st, st);

    for (ll a = 0; a < 3; ++a) {
        for (ll b = 0; b < 3; ++b) {
            if (a == b)
                continue;
            ll c = 3 - a - b;
            long long sum = 0;
            for (ll i = 0; i < n; i += 3) {
                sum += v[a][df[i]];
                if (i + 1 < n)
                    sum += v[b][df[i + 1]];
                if (i + 2 < n)
                    sum += v[c][df[i + 2]];
            }
            if (sum <= fans) {
                ma = a, mb = b, mc = c;
                fans = sum;
            }
        }
    }
    vector<ll> ans(n);
    for (ll i = 0; i < n; i += 3) {
        ans[df[i]] = ma + 1;
        if (i + 1 < n) {
            ans[df[i + 1]] = mb + 1;
        }
        if (i + 2 < n) {
            ans[df[i + 2]] = mc + 1;

        }
    }   
    cout << fans << '\n';
    for (ll & i : ans)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    srand(time(0));
    //freopen("river.in", "r", stdin);
    //freopen("river.out", "w", stdout);
    
    ll tests = 1;
    //cin >> tests;
    while (tests--) {
        solve();
    }
    
}