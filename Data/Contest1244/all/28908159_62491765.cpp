#include <bits/stdc++.h>
using namespace std;
const double pi=2*acos(0.0);
double inff=1.0/0.0;
#define ll           long long int
#define inf          100000000000000000
#define MOD          1000000007
#define pb           push_back
#define sz(x)        (int)x.size()
#define mp           make_pair
#define lbd          lower_bound
#define ubd          upper_bound
#define ipair        pair<ll,ll> 
#define all(v)       v.begin(),v.end()
#define watch(x)     cout<<(#x)<<" is "<<(x)<<endl;
#define rep(a,b,c)   for(a=(int)b;a<(int)c;a++)    
#define bac(a,b,c)   for(a=(int)b;a>=(int)c;a--)
#define se           second
#define f            first
#define ios          ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
#define mem(a,val)   memset(a,val,sizeof a)
#define endl         "\n"
#define mxn          100002
#define vi           vector<ll>
#define vii          vector<ipair> 
#define si           set<ll> 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
/*Variables Start*/
ll x,y,n,i,z,j,k,w,u,q,m,t;
ll col[mxn][3];vi v[mxn];
ll v1[10][mxn];
/*Variables End*/
void solve()
{
  ll root=0;
  cin>>n;
  rep(j,0,3)
  {
    rep(i,1,n+1)
    {
      cin>>col[i][j];
    }
  }
  rep(i,1,n)
  {
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
  }
  rep(i,1,n+1)
  {
    if(v[i].size()>2) 
    {
      cout<<"-1"<<endl;
      return;
    }
    else if(v[i].size()==1)
    {
      root=i;
    }
  }
  vi perm({0,1,2});
  ll ans=inf;
  y=0;j=0;
  do
  {
    x=root;
    z=root;
    w=0;
    rep(i,1,n+1)
    {
      w+=col[x][perm[(i-1)%3]];
      v1[j][x]=perm[(i-1)%3];
      if(v[x].size() and v[x][0]==z and i<n)
      {
        z=x;
        x=v[x][1];
      }
      else if(v[x].size() and i<n)
      {
        z=x;
        x=v[x][0];
      }
    }
    if(ans>w)
    {
      ans=w;
      y=j;
    }
    j++;
  }while(next_permutation(all(perm)));
  cout<<ans<<endl;
  rep(i,1,n+1)
  {
    cout<<v1[y][i]+1<<" ";
  }
}
int main() 
{ 
  int TESTS=1;
  ios;
  while(TESTS--)
  {
    solve();
  }
}