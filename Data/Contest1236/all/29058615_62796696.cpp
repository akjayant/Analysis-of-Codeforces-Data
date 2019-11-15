#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> plll;
typedef pair<pll,pll> ppll;
typedef long double ld;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fst first
#define snd second
#define ins insert
#define pb push_back

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
ll bin_pow(ll x,ll p){
    ll ret = 1;
    while(p){
        if(p & 1)
            ret *= x;
        x *= x;
        x %= MOD;
        ret %= MOD;
        p >>= 1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ll n,m;
    cin >> n >> m;
    ll ans = bin_pow(2,m);
    ans += MOD - 1;
    ans %= MOD;
    ans = bin_pow(ans,n);
    cout << ans;
    return 0;
}
