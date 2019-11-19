#include"iomanip"
#include"iostream"
#include"limits"
#include"cmath"
#include"vector"
#include"algorithm"
#include"list"
#include"queue"
#include"stack"
#include"set"
#include"map"
#include"string"
#include"cstring"
#include"assert.h"
using namespace std;
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define mp make_pair
#define pb push_back
#define mset(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn = 2000 + 3;

vector<pair<ll, pll> > ed;

pll cord[maxn];
ll c[maxn], k[maxn];

ll par[maxn];

ll find(ll x)
{
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

ll merge(ll x, ll y)
{
  x = find(x);
  y = find(y);
  if( x!=y)
    par[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    for( int i = 1; i<=n; ++i)
    {
      cin>>cord[i].ff>>cord[i].ss;
    }
    for (int i = 1; i <= n; ++i)
    {
      cin>>c[i];
    }
    for (int i = 1; i <= n; ++i)
    {
      cin>>k[i];
    }
    for (int i = 1; i<=n; ++i)
    {
      ed.pb(mp(c[i],mp(0,i)));
    }
    for(int i = 1; i <=n; ++i)
    {
      for(int j = i+1 ; j<=n; ++j)
      {
        ll dist = abs(cord[i].ff - cord[j].ff) + abs(cord[i].ss - cord[j].ss);
        ed.pb(mp( dist*(k[i] + k[j]), mp(i, j)));
      }
    }
    for(int i = 0; i< maxn; ++i)
    {
      par[i] = i;
    }
    sort(all(ed));

    ll yen = 0;
    vector<ll>pow;
    vector<pll> con;
    for (auto xx: ed)
    {
      ll a1 = xx.ss.ff, a2 = xx.ss.ss;
      if(find(a1) != find(a2))
      {
        merge(a1, a2);
        if (a1 == 0)
        {
          pow.pb(a2);
        }
        else
        {
          con.pb(mp(a1, a2));
        }
        yen += xx.ff;
      }
    }
    cout<<yen<<'\n';
    cout<<pow.size()<<'\n';
    for(ll x:pow)
    {
      cout<<x<<' ';
    }
    cout<<'\n';

    cout<<con.size()<<'\n';
    for(pll x:con)
    {
      cout<<x.ff<<' '<<x.ss<<'\n';
    }

}














