#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pll> vll;
typedef vector<pdd> vdd;
typedef vector<vl> vvl;
typedef vector<vd> vvd;
const int mod = 1000000007;
const vi mods = {998244353,1000000007,1000000009};
const ll inf = 3e18;
const double pi = acos(-1.0);
const double eps = 0.0000001;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) ((int)(x).size())
#define fll(xs,x,a) fill(&x,&x+sizeof(xs)/sizeof(x),a)
#define has(x,a) (x.find(a)!=end(x))
#define pc(x) __builtin_popcountll(x)
#define pb push_back
#define fi first
#define se second
template<class...K> using umap = unordered_map<K...>;
template<class...K> using uset = unordered_set<K...>;

#define N 300100
ll k;
ll n,res;
vl a;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin>>k;
  rep(_k,0,k){
    res=0;
    cin>>n;
    a.clear();
    rep(i,0,n){
      ll a_;cin>>a_;
      a.pb(a_);
    }
    sort(all(a),greater<ll>());
    rep(i,0,n){
      if(a[i]>=(i+1))res=max(res,i+1);
    }
    cout<<res<<"\n";
  }
  return 0;
}