#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
ll qpow(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)   ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll n,m;
    cin >> n >> m;
    ll tmp = qpow(2,m) - 1;
    ll ans = qpow(tmp,n);
    cout << ans << endl;
    return 0;
}