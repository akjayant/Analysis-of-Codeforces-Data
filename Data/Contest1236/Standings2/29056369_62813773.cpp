#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mod 1000000007LL
#define pb emplace_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);i++)
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}

signed main()
{
    fast;
    ll n;
    cin>>n;
    vi ans[n];
    if(n%2==0)
    {
        ll mid=n*n/2;
        ll mm=mid+1;
        for(ll i=0;i<(n);i++)
        {
            for(ll j=0;j<(n/2);j++)
            {
                ans[i].pb(mid--);
                ans[i].pb(mm++);
            }
        }
        for(ll i=0;i<(n);i++)
        {
            for(ll j=0;j<(n);j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else
    {
        ll del=n;
        ll mid=(n*n-n)/2+del;
        ll mm=mid+1;
        del=1;
        for(ll i=0;i<(n);i++)
        {
            ans[i].pb(del++);
            for(ll j=0;j<(n/2);j++)
            {
                ans[i].pb(mid--);
                ans[i].pb(mm++);
            }
        }
        for(ll i=0;i<(n);i++)
        {
            for(ll j=0;j<(n);j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
