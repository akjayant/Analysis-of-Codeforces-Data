#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define ll long long
#define ull unsigned long long
 
ll md=(1e9)*1e9+7;
ll MOD=1e9+7;
int INF=1e9+7;
 
ll binpow (ll a, ll n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return (binpow (a, n-1) * a) % MOD;
	else {
		int b = binpow (a, n/2)% MOD;
		return (b * b) % MOD;
	}
}
 
pair<int,ll> rev(pair<ll,int> x)
{
    return mp(x.sec,x.fir);
}
 
void update()
{
    
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll d=-1;
    if (n==1)
    {
        cout<<1;
        return 0;
    }
    for (ll i=2;i*i<=n;i++)
        if (n%i==0)
        {
            d=i;
            break;
        }
    if (d<0)
    {
        cout<<n;
    }
    else
    {
        while (n%d==0)
        {
            n/=d;
        }
        if (n>1)
        {
            cout<<1;
        }
        else
        {
            cout<<d;
        }
    }
    return 0;
}
/*
0 0 0
0 0 1
0 1 0
1 0 0
*/