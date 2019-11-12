#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
typedef long long ll;


//returns a^pw % mod
ll fastPow(ll a, ll pw, ll mod) {
    ll res = 1;
    a %= mod;
    while(pw > 0) {
        if(pw & 1) res = (res*a)%mod;
        a = (a*a)%mod;
        pw >>= 1;
    }
    return res;
}

const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    cout << fastPow((fastPow(2,m,mod)-1+mod),n,mod);


}
