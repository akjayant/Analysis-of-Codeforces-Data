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
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}
ll n,m;
ll arr[100100];
vector<pii> blockage;
map<pii,ll> leftmax;
map<pii,ll> rightmax;
void solveLeft()
{
    map<ll,vector<pii>> samexminy;
    for(ll i=0;i<blockage.size();i++)
    {
        samexminy[blockage[i].fi-blockage[i].sec].pb(blockage[i].sec,i);
    }
    for(auto &v:samexminy)
        sort(all(v.sec));
    for(ll i=0;i<blockage.size();i++)
    {
        ll xx=blockage[i].fi-1;
        ll yy=blockage[i].sec;
        if(leftmax.find(mp(xx,yy))!=leftmax.end())
        {
            leftmax[blockage[i]]=leftmax[mp(xx,yy)];
        }
        else
        {
            ll xminy=xx-yy;
            auto val=lower_bound(all(samexminy[xminy]),mp(yy,0LL));
            if(val==samexminy[xminy].begin())
            {
                leftmax[blockage[i]]=yy-xx;
            }
            else
            {
                val--;
                leftmax[blockage[i]]=leftmax[blockage[(*val).sec]];
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        ll xx=m+1;
        ll yy=i;
        if(leftmax.find(mp(xx,yy))==leftmax.end())
        {
            ll xminy=xx-yy;
            auto val=lower_bound(all(samexminy[xminy]),mp(yy,0LL));
            if(val==samexminy[xminy].begin()){
                leftmax[mp(xx,yy)]=yy-xx;
            }
            else
            {
                val--;
                leftmax[mp(xx,yy)]=leftmax[blockage[(*val).sec]];
            }
        }
    }
}
 
void solveRight()
{
    map<ll,vector<pii>> samexplusy;
    for(ll i=0;i<blockage.size();i++)
    {
        samexplusy[blockage[i].fi+blockage[i].sec].pb(blockage[i].sec,i);
    }
    for(auto &v:samexplusy)
        sort(all(v.sec));
 
    for(ll i=0;i<blockage.size();i++)
    {
        ll xx=blockage[i].fi-1;
        ll yy=blockage[i].sec;
        if(rightmax.find(mp(xx,yy))!=rightmax.end())
        {
            rightmax[blockage[i]]=rightmax[mp(xx,yy)];
        }
        else
        {
            ll xminy=xx+yy;
            auto val=upper_bound(all(samexplusy[xminy]),mp(yy,mod));
            if(val==samexplusy[xminy].end()){
                rightmax[blockage[i]]=yy+xx;
            }
            else
            {
                rightmax[blockage[i]]=rightmax[blockage[(*val).sec]];
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        ll xx=m+1;
        ll yy=i;
        if(rightmax.find(mp(xx,yy))==rightmax.end())
        {
            ll xminy=xx+yy;
            auto val=upper_bound(all(samexplusy[xminy]),mp(yy,mod));
            if(val==samexplusy[xminy].end()){
                rightmax[mp(xx,yy)]=yy+xx;
            }
            else
            {
                rightmax[mp(xx,yy)]=rightmax[blockage[(*val).sec]];
            }
        }
    }
}
signed main()
{
    fast;
    cin>>n>>m;
    if(n==1)
    {
    	cout<<0;
    	return 0;
    }
    for(ll i=0;i<m;i++)
    {
        cin>>arr[i];
        blockage.pb(i+1,arr[i]);
    }  
    solveLeft();
    solveRight();
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        ll xx=m+1,yy=i;
        ll lo=max(1LL,leftmax[mp(xx,yy)]);
        ll hi=min(n,rightmax[mp(xx,yy)]);
        ans+=hi-lo+1;
    }
    cout<<ans<<"\n";
}