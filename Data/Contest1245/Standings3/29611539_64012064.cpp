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

const ll mo = 1e9 + 7;
const int maxn = 1e5 + 5;

ll fib[maxn];

void init()
{
  fib[1] = 1;
  fib[2] = 2;
  for(int i = 3; i < maxn; ++i)
  {
    fib[i] = fib[i-1] + fib[i-2];
    fib[i] %= mo;
  }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    init();
    int n = s.length();
    vector<ll> co;
    char cur = '-';
    ll fr = 0;
    for(int i = 0; i < n; ++i)
    {
      if(s[i] =='w' || s[i] =='m')
      {
        cout<<"0\n";
        return 0;
      }
      if(s[i] == cur)
        fr++;
      else
      {
        if(cur == 'u' || cur == 'n')
        {
          co.pb(fr);
        }
        cur = s[i];
        fr = 1;
      }
    }
    if( fr > 0)
    {
      if ( cur =='u' || cur == 'n')
      {
        co.pb(fr);
      }
    }
    ll ans = 1;
    for(ll x:co)
    {
      ans *= fib[x];
      ans %= mo;
    }
    cout<<ans<<'\n';
}








