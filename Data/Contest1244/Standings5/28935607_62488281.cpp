/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<int>  os;
#define up_bound(i) os.order_of_key(i) << endl; // the number of elements in the os less than i
#define access_idx(i) *os.find_by_order(i) // print the i-th smallest number in os(0-based)

#define ll long long int
#define ld double 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define deb cerr << "Line no." << __LINE__
#define nl '\n'
#define pb push_back
#define all(a) a.begin(),a.end()
#define P pair<ll,ll> 
#define F first
#define S second
const ll p_mod=9999999999999983;
const long double pi = 3.14159265358979323;
const ll N=1e6+9;
const ll mod=1e9+7;
typedef double f80;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){uniform_int_distribution<int> uid(l, r); return uid(rng); }
ll powerk(ll x, ll y);

ll a[4][N],dp[N],vis[N],aa[N];
vector<ll> v[N], res, temp,temp1;

  ll n,m;

void dfs(ll x , ll parent)
{
  if(v[x].size()>2)return ;
  temp1.pb(x);
  vis[x]=1;
  for(auto it: v[x])
  {
    if(!vis[it])dfs(it,x);
  }
}

ll go(ll i, ll j, ll id)
{
  if(id==n)return 0;
    rep(l,1,4)
    {
      if(l!=i && l!=j)
      {temp.pb(l);
        return a[l][temp1[id]]+go(j,l,id+1);
      }
    }
}

void solve()
{    
  cin>>n;
  rep(i,1,n+1)cin>>a[1][i];
  rep(j,1,n+1)cin>>a[2][j];
  rep(k,1,n+1)cin>>a[3][k];
  rep(i,1,n)
  {
    ll l, r;
    cin>>l>>r;
    v[l].pb(r);
    v[r].pb(l);
  }
  ll cnt=0,cnt2=0,flag=0;
  rep(i,1,n+1)
  {
    if(v[i].size()==1){cnt=i;break;}
  }
  dfs(cnt,-1);
  rep(i,1,n+1)if(!vis[i])flag=1;
  if(flag){cout<<-1;return ;}
  else
  {
    ll ans=1e18;
    rep(i,1,4)
    {
      rep(j,1,4)
      {

        if(i!=j)
        {
          temp.clear();
          temp.pb(i);
          temp.pb(j);
          ll x =go(i,j,2)+a[i][temp1[0]]+a[j][temp1[1]];
          if(ans>x)
          {
            ans = x;
            res = temp;
          }
        }
      }
    }
    cout<<ans<<nl;
    rep(i,0,n)aa[temp1[i]]=res[i];
    rep(i,1,n+1)cout<<aa[i]<<" ";
    /*rep(i,1,n+1)dp[i]=1e16;
    rep(i,0,2)dp[i] = min({a[1][i],a[2][i],a[3][i]});
    dp[2] = min({min(a[2][1],a[3][1])+a[1][2],min(a[1][1],a[3][1])+a[2][2],min(a[2][1],a[1][1])+a[3][2]});
    rep(i,3,n+1)
    {
      rep(j,1,4)
      {
        rep(k,1,4)
        {
          rep(l,1,4)
          {
            if(k!=j && l!=k && l!=j)
            {
              dp[i] = min(dp[i-3]+a[j][i-2]+a[k][i-1]+a[l][i],dp[i]);
            }
          }
        }
      }
    }*//*
    rep(i,1,n)cout<<dp[i]<<" ";
    cout<<dp[n];*/
  }

}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t=1;
    //pre();
    //cin>>t;
    while(t--)
    {
      solve();
    }  
}
ll powerk(ll x, ll y)
{
  if(y==0)return 1;
  if(y==1)return x%mod;
  if(y&1)
    return ((powerk((x*x)%mod, y/2)%mod)*x)%mod;
  else return powerk((x*x)%mod,y/2)%mod;
}

// Xorawar