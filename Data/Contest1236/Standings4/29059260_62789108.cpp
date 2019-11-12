#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const ll maxn = 2e5+10;
const ll mod = 1e9+7;

ll pw(ll a, ll b)
{
    if(b == 0) return 1;
    if(b == 1) return a;
    ll k = pw(a,b/2); k = (k*k) % mod;
    if(b&1) k = (k*a) % mod;
    return k;
}

ll n, m, q;
ll a[maxn];

int main()
{
    cin>> n >> m;
    cout<< pw(pw(2,m)-1, n);
}