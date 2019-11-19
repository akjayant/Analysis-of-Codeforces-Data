#include <cstdio>
#include <cassert>
#include <algorithm>    
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <bitset>
#define pb push_back
#define mk make_pair
#define eb emplace_back
#define eps 1e-8
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define int long long
using namespace std;

typedef long double ld;
typedef unsigned int ui;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<long double> vd;
const int inf = 1e9;
const long long INF = 1e18;
const int M = 1e9 + 7;
//__int128

int d[2002][2002];

signed main() {
  // freopen("in.txt", "r", stdin);
  #ifndef ONLINE_JUDGE
      freopen("in.txt", "r", stdin);
      // freopen("out.txt", "w", stdout);
  #endif
  
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  cout.setf(ios::fixed); cout.precision(10);
  int n;
  cin >> n;
  std::vector<int> x(n), y(n);
  std::vector<int> c(n), k(n);
  for(int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  for(int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for(int i = 0; i < n; ++i) {
    cin >> k[i];
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      d[i][j] = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
    }
  }
  int res = 0;
  int u = min_element(all(c)) - c.begin();
  res += c[u];
  int T = n - 1;
  std::vector<bool> vis(n, 0);
  std::vector<int> dp(n, INF);
  std::vector<int> fa(n, -1);
  vis[u] = 1;
  for(int i = 0; i < n; ++i) {
    dp[i] = min(dp[i], c[i]);
    if(d[u][i] < dp[i]) {
      fa[i] = u;
      dp[i] = d[u][i];
    }
  }
  std::vector<int> v;
  v.eb(u);
  std::vector<pii> e;
  while(T--){
    int mn = INF, t = -1;
    for(int i = 0; i < n; ++i) {
      if(!vis[i]) {
        if(dp[i] < mn) {
          mn = dp[i];
          t = i;
        }
      }
    }
    u = t;
    vis[u] = 1;
    res += dp[u];
    if(dp[u] == c[u]) {
      v.eb(u);
    } else {
      e.eb(u, fa[u]);
    }
    for(int i = 0; i < n; ++i) {
      if(d[u][i] < dp[i]) {
        fa[i] = u;
        dp[i] = d[u][i];
      }
    }
  }
  cout << res << endl;
  cout << (int)v.size() << endl;
  for(int i : v) {
    cout << i + 1 << ' ';
  }
  cout << endl;
  cout << (int)e.size() << endl;
  for(auto i : e) {
    cout << i.fi + 1 << ' ' << i.se + 1 << endl;
  }
  return 0;
}