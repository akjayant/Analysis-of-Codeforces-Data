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
  
  ll n,m;
  cin >> n >> m;
  ll maxm = max(n, m);
  ll arr[maxm + 1];
  arr[0]=1; arr[1] = 1; arr[2] = 2;
  f(i,3,maxm+1)
  {
    arr[i] = (arr[i-1] % MOD) + (arr[i-2]%MOD);
  }
  ll a=(((arr[m] + arr[n] - 1)%MOD + MOD)*2)%MOD;
  cout << a;
  return 0;
}