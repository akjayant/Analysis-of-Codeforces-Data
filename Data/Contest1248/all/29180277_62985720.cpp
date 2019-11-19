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
  
  ll n;
  cin >> n;
  ll arr[n];
  f(i,0,n)
  {
    cin >> arr[i];
  }
  sort(arr, arr+n);
  ll x = 0, y = 0;
  f(i,0,n/2)
  {
    y += arr[i];
  }
  f(i,n/2,n)
  {
    x += arr[i];
  }
  ll ans = x*x + y*y;
  cout << ans;
  return 0;
}