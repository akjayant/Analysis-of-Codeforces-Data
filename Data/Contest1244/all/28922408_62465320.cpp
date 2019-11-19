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

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin>>t;
  while(t--)
  {
    ll a,b,c,d,k,fl=0;
    cin>>a>>b>>c>>d>>k;
    fori(i,0,k+1)
    {
      ll x=i;
      ll y=k-i;
      if(a<=c*x && b<=(d*y))
      {
        cout<<x<<" "<<y<<endl;
        fl=1;
        break;
      }
    }
    if(!fl) cout<<-1<<endl;
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
