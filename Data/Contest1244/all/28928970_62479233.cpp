#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef pair<double,double> pt;
const double pi = acos(-1.0);
const int mod = 1000000007;
const vi mods = {998244353,1000000007,1000000009};
const ll inf = 3e18;
const double eps = 0.0000001;
const mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) ((int)(x).size())
#define fll(xs,x,a) fill(&x,&x+sizeof(xs)/sizeof(x),a)

ll n,p,w,d;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin>>n>>p>>w>>d;
  ll g=__gcd(w,d);
  if(p%g != 0) {
    cout<<"-1\n";
    return 0;
  }
  p/=g;
  w/=g;
  d/=g;
  ll x = p/w;
  for (int i = 0; i <= 2 * d; i++) {
    if (x < 0) break;
    ll rst = p - x * w;
    if (rst < 0) break;
    if  (rst % d == 0) {
      ll y = rst / d;
      if (x + y <= n) {
        cout << x << " "<< y <<" " << (n - x - y) << "\n";
        return 0;
      }
      else break;
    }
    x--;
  }
  cout << "-1\n";
  return 0;
}