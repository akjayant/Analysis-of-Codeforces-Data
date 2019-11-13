#pragma GCC optimize("O3")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi >
#define ppl pair<ll,pl >
#define ld long double
#define pb push_back
#define mod 1000000007

ll poww(ll a, ll b)
{
    if(b==0)
        return 1;
    ll ans=poww(a,b/2);
    if(b%2==0)
        return (ans*ans)%mod;
    return (((ans*ans)%mod)*a)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin>>n>>m;
    ll ans=poww(2,m);
    ans=(ans-1+mod)%mod;
    cout<<poww(ans,n);

    return 0;
}