#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll powi(ll a, ll b)
{
    ll p;
    if(!b) return 1;
    p = powi(a, b/2);
    p = (p*p)%MOD;
    if(b%2) p = (p*a)%MOD;
    return p;
}

int main()
{
    int n, m;
    cin>>n>>m;

    ll ans = powi(powi(2, m)-1, n);
    cout<<ans<<"\n";

    return 0;
}
