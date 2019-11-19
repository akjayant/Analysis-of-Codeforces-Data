// Garg's Code
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
 
#define ll long long
#define vec vector < ll >
#define pb push_back
#define po pop_back
#define mp make_pair
#define mt make_tuple
#define F  first
#define S  second
#define f(i,x,n) for(ll i=x;i<n;i++)
#define rf(i,x,n) for(ll i = x; i >= x; i--) 
#define all(c) c.begin(),c.end()
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
const ll MAX = LLONG_MAX, MOD = 1000000007, MODA = 1e9 - 1;
const ll MIN = LLONG_MIN; 
int main()
{
  fast();
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w",stdout);
  #endif
  
  ll t;
  cin >> t;
  while(t--)
  {
  	ll n;
    cin >> n;
    ll ar[n];
    ll o1=0, e1=0;
    f(i,0,n)
    {
      cin >> ar[i];
      if(ar[i]%2)
      {
        o1++;
      }
      else
      {
        e1++;
      }
    }
    ll m,o2=0,e2=0;
    cin >> m;
    ll arr[m];
    f(i,0,m)
    {
      cin >> arr[i];
      if(arr[i]%2)
      {
        o2++;
      }
      else
      {
        e2++;
      }
    }
    ll ans;
    ans = (o1*o2) + (e1 * e2);
    cout << ans << endl;

  } 
  return 0;
}