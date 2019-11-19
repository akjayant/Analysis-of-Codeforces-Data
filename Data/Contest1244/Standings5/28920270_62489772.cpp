#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define ll long long
#define f first
#define s second
using namespace std;

vector<vector<ll>> c(3, vector<ll> (100000));
vector<vector<ll>> g(100000);
vector<ll> order;

void dfs(int v, int p) {
    for(int i: g[v]) {
        if(i != p) {
            dfs(i, v);
        }
    }
    order.push_back(v);
}


int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> c(3, vector<ll> (n));
    for(ll i = 0; i < 3; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    for(ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    for(ll i = 0; i < n; i++) {
        if(g[i].size() > 2) {
            cout << -1;
            return 0;
        }
    }
    ll s = -1;
    for(ll i = 0; i < n; i++) {
        if(g[i].size() == 1) {
            s = i;
            break;
        }
    }
    dfs(s, -1);
    ll ans = 1e18, a1 = -1, a2 = -1, a3 = -1;
    for(int c1 = 0; c1 < 3; c1++) {
        for(int c2 = 0; c2 < 3; c2++) {
            if(c2 != c1) {
                int c3 = 1 + 2 - c1 - c2;
                ll cnt = 0;
                for(ll i = 0; i < n; i++) {
                    if(i % 3 == 0){
                        cnt += c[c1][order[i]];
                    }
                    if(i % 3 == 1){
                        cnt += c[c2][order[i]];
                    }
                    if(i % 3 == 2){
                        cnt += c[c3][order[i]];
                    }
                }
                if(cnt < ans) {
                    ans = cnt;
                    a1 = c1;
                    a2 = c2;
                    a3 = c3;
                }
            }
        }
    }
    cout << ans << "\n";
    vector<int> ac(n);
    for(ll i = 0; i < n; i++) {
        if(i % 3 == 0){
            ac[order[i]] = a1 + 1;
        }
        if(i % 3 == 1){
            ac[order[i]] = a2 + 1;
        }
        if(i % 3 == 2){
            ac[order[i]] = a3 + 1;
        }
    }
    for(int i : ac) cout << i << " ";
    return 0;
}