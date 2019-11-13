#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<ll, ll> mpii;
typedef unordered_map<ll, ll> umpii;
 
#define pb(v) push_back(v)
#define all(v) v.begin(), v.end()
#define upb(v, key) (upper_bound(all(v), key) - v.begin())
#define lob(v, key) (lower_bound(all(v), key) - v.begin())
 
ll inf = 1e9;
ll INF = inf * inf;
ll mod = 1e9 + 7;
double eps = 1e-9;
const ld pi = ld(3.1415926535897932384626433832795);
ll dr[] = {-1, 0, 0, 1};
ll dc[] = {0, 1, -1, 0};

void mod_add(ll &a, ll b) {
  a += b;
  if(a > mod) a -= mod;
}
void mod_sub(ll &a, ll b) {
  a -= b;
  if(a < 0) a += mod;
}
ll mod_pow(ll b, ll p) {
  ll res = 1; 
  while(p) {
    if(p & 1) {
      res = res * b % mod;
    }
    p >>= 1;
    b = b * b % mod;
  }
  return res;
}

//only for variables and vectors; 
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}
template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

/*...................................................*/

main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);

  ll t, n, m, i, j, k, q, u, v;
  // cin >> t;
  // ll tc = t;
  t = 1;
  while (t--) {
    cin >> n;
    ll a[n][n];
    ll c = 1;
    for(j = 0; j < n; j++)
    if(!(j & 1))
    for(i = 0; i < n; i++) {
      a[i][j] = c++;
    } else {
      for(i = n - 1; i >= 0; i--) {
        a[i][j] = c++;
      }
    }
    for(i = 0; i < n; i++) {
      for(j = 0; j < n; j++) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}