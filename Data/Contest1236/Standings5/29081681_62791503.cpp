#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target ("avx2,avx,fma")
#define ll long long int
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for(i=l;i<r;i++)
#define bep(i,l,r) for(i=l;i>=r;i--)
#define ld long double
#define ff first
#define ss second
#define pii pair<int,int>
#define pi 3.1415926535897932384626433832
#define mod 1000000007
//vector<ll>dp;
//vector<vector<ll> >fact;
//map<ll,ll>prime[100005];
ll m;
ll powe(ll i,ll j)
{
    if(j==0)
        return 1;
    ll ans=1;
    while(j>0)
    {
        if(j%2!=0)
            ans=((ans%mod)*(i%mod))%mod;
            i=((i%mod)*(i%mod))%mod;
            j/=2;
    }
    return ans;
}
int main()
{
    ll n,m;
    cin>>n>>m;
    cout<<powe(powe(2,m)-1,n);
}
