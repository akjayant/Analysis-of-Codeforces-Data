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

ll t;
ll n;
string s;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin>>t;
  rep(_t,0,t){
    cin>>n>>s;
    ll mx = -inf, mn = inf;
    rep(i,0,n){
      if (s[i] == '1') {
        mn = min(mn, i);
        mx = max(mx, i);
      }
    }
    if (mx == -inf) {
      cout<<n<<"\n";
    }
    else {
      cout<< max(2 * (n - mn), 2* (mx + 1) ) << "\n";
    }
  }
  
  
  return 0;
}