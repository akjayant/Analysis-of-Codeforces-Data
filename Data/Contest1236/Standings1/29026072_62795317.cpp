#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1e9+7;

ll powd(ll a, ll b) {
    ll res = 1LL;
    for (ll i=b; i; i>>=1) {
        if (i&1) res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    ll x=(powd(2, m)-1LL+MOD)%MOD;
    ll y=powd(x, n);
    cout<<y;
    return 0;
}