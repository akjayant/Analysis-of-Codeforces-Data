#pragma GCC optimize("03")
#pragma GCC target("avx2")

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sqr(a) (a)*(a)
#define um unordered_map 
#define us unordered_set
using namespace std;

hash<string> hfn;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef double dbl;
typedef unsigned int ui;
const int inf = 1e9;
const ll mod = 1e9 + 7;
const ld eps = 1e-7;
const ll biginf = 1e18;

void solve()
{
  ll n;
  cin >> n;
  vector<ll> del;
  ll nn = n;
  for(ll i = 2; i * i <= nn; i++)
  {
    if(n % i == 0)
    {
      del.pb(i);
      while(n % i == 0)
        n /= i;
    }
  }
  if(n > 0 && n < nn && n != 1)
    del.pb(n);
  if(del.empty())
  {
    cout << n;
    return;
  }
  if(del.size() == 1)
  {
    cout << del[0];
    return;
  }
  cout << 1;
}

void multisolve()
{
  int t;
  cin >> t;
  while(t--)
    solve();
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  //freopen("points.in", "r", stdin);
  //freopen("points.out", "w", stdout);
  solve();
  //multisolve();
}