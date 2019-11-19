/*----------------
     Smit Patel
     DA-IICT
----------------*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ins insert
#define fori(i,a,n) for(int i=a; i<n; i++)
#define ford(i,a,n) for(int i=a; i>n; i--)
#define clr(a,b) memset(a,b,sizeof(a))
#define deb(x) cout<<#x<<" : "<<x<<endl;
#define debug(x,y) cout<<#x<<" : "<<x<<"\t"<<#y<<" : "<<y<<endl;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define bp __builtin_popcount
#define mod 1000000007
#define eps 1e-6
#define infi 1000000002
#define infll 1e18+5
#define N 200005
#define LN 20

typedef long double ld;
typedef long long ll;
typedef map<ll,ll> mll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef set<ll> sll;

ll choose(ll n,ll k);
bool isprime(ll n);
ll power(ll x,ll y,ll p);
ll power(ll x,ll y);
ll gcd(ll a,ll b);
vll adj[N];
ll vis[N];
vll v;
void dfs(ll x)
{
  vis[x]=1;
  v.pb(x);
  for(auto it:adj[x])
  {
    if(!vis[it])
    {
      dfs(it);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin>>n;
  ll a[n],b[n],c[n];
  fori(i,0,n)
  {
    cin>>a[i];
  }
  fori(i,0,n)
  {
    cin>>b[i];
  }
  fori(i,0,n)
  {
    cin>>c[i];
  }
  fori(i,0,n-1)
  {
    ll x,y;
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  ll fl=0,tmp=-1;
  fori(i,1,n+1)
  {
    if(adj[i].size()==1)
    {
      tmp=i;
    }
    if(adj[i].size()>2) fl=1;
  }
  if(fl || tmp==-1) return cout<<-1<<endl,0;
  dfs(tmp);
  string s="123",ansss="123";
  ll ans=LLONG_MAX;
  fori(tt,0,6)
  {
    ll cnt=0;
    fori(i,0,v.size())
    {
      if(s[i%3]=='1')
      {
        cnt+=a[v[i]-1];
      }
      else if(s[i%3]=='2')
      {
        cnt+=b[v[i]-1];
      }
      else
      {
        cnt+=c[v[i]-1];
      }
    }
    if(ans>cnt)
    {
      ans=cnt;
      ansss=s;
    }
    next_permutation(all(s));
  }
  cout<<ans<<endl;
  ll arr[N]={};
  fori(i,0,v.size())
  {
    arr[v[i]]=ansss[i%3]-'0';
  }
  fori(i,1,n+1)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}

ll gcd(ll a,ll b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}

ll choose(ll n,ll k)
{
  if(k==0)
    return 1;
  return (n* choose(n-1,k-1))/k;
}

bool isprime(ll n)
{
  for(ll i=2;i*i<=n;i++)
  {
    if(n%i==0)
      return false;
  }
  return true;
}

ll power(ll x,ll y,ll p)
{
  ll res=1;
  x=x%p;
  while(y>0)
  {
    if(y&1)
      res=(res*x)%p;
    y=y>>1;
    x=(x*x)%p;
  }
  return res;
}

ll power(ll x,ll y)
{
  ll res=1;
  while(y>0)
  {
    if(y&1)
      res=res*x;
    y=y>>1;
    x=x*x;
  }
  return res;
}
