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

void solve()
{
  int n;
  int rr, pp, ss;
  string s;
  cin>>n>>rr>>pp>>ss>>s;
  string res = s;
  for(int i = 0; i < n; ++i)
  {
    res[i] = '1';
    if (s[i] == 'R')
    {
      if ( pp > 0)
      {
        res[i] = 'P';
        pp--;
      }
    }
    if (s[i] == 'P')
    {
      if ( ss > 0)
      {
        res[i] = 'S';
        ss--;
      }
    }
    if (s[i] == 'S')
    {
      if ( rr > 0)
      {
        res[i] = 'R';
        rr--;
      }
    }
  }

  for ( int i = 0; i < n; ++i) 
  {
    if(res[i] != '1')continue;

    if (s[i] == 'R')
    {
      if ( rr > 0)
      {
        res[i] = 'R';
        rr--;
      }
    }
    if (s[i] == 'P')
    {
      if ( pp > 0)
      {
        res[i] = 'P';
        pp--;
      }
    }
    if (s[i] == 'S')
    {
      if ( ss > 0)
      {
        res[i] = 'S';
        ss--;
      }
    }
  }

  for ( int i = 0; i < n; ++i)
  {
    if(res[i] != '1')continue;

    if( rr > 0)
    {
      res[i] = 'R';
      rr--;
    }
    else if (pp > 0)
    {
      res[i] = 'P';
    }
    else if (ss > 0)
    {
      res[i] = 'S';
    }
  }

  int w = 0;
  for (int i = 0; i < n; ++i) 
  {
    if (res[i] =='P' && s[i] == 'R')
    {
      w++;
    }
    if (res[i] =='S' && s[i] == 'P')
    {
      w++;
    }
    if (res[i] =='R' && s[i] == 'S')
    {
      w++;
    }
  }
  int req = (n+1)/2;
  if (w >= req)
  {
    cout<<"YES\n";
    cout<<res<<'\n';
  }
  else cout<<"NO\n";


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--)
    {
      solve();
    }
}
