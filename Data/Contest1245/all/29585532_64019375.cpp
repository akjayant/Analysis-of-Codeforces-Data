//be name khoda
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5+10;
const ll mod = 1e9+7;

ll pw(ll a, ll b)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    ll k = pw(a,b/2); k = (k*k) % mod;
    if(b&1) k = (k*a) % mod;
    return k;
}

ll fac[maxn];
ll C(ll n, ll k)
{
    if(k > n) return 0;
    ll x = (fac[k] * fac[n-k]) % mod;
    return (fac[n] * pw(x,mod-2)) % mod;
}

ll f(ll siz)
{
    ll ans = 0;
    for(ll x = 0; x <= siz; x++)
        (ans += C(siz-x,x)) %= mod;
    return ans;
}

ll n;
string s;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> s; n = s.size();

    fac[0] = 1;
    for(ll i = 1; i < maxn; i++) fac[i] = (fac[i-1] * i) % mod;

    ll x = 0, ans = 1;
    if(s[0] == 'w' || s[0] == 'm') return cout<< 0, 0;
    for(ll i = 1; i < n; i++)
    {
        if(s[i] == 'w' || s[i] == 'm')
            return cout<< 0, 0;
        if(s[i] != s[i-1])
        {
            if(s[i-1] == 'n' || s[i-1] == 'u')
                ans = (ans * f(i-x)) % mod;
            x = i;
        }
    }
    if(s[n-1] == 'n' || s[n-1] == 'u')
        ans = (ans * f(n-x)) % mod;
    cout<< ans;
}
