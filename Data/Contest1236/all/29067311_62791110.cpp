#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

ll qpow(ll a, ll b)
{
    ll ans = 1, base = a;
    while(b != 0) {
        if(b&1) ans = (ans*base)%mod;
        base = (base*base) % mod;
        b >>= 1;
    }
    ans = (ans+mod) % mod;
    return ans;
}

int main()
{
    ll n, m;
    while(cin >> n >> m) {
        ll ans = 1;
        ll p1 = (qpow(2, m)-1+mod) % mod;
        ans = ans * qpow(p1, n)%mod;
        cout << ans << endl;
    }
}