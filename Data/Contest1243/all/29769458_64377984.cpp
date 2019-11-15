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

ll q,n;
string s,t;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin>>q;
  rep(_q,0,q){
    cin>>n>>s>>t;
    ll diff=-1;
    bool done=false;
    bool res=false;
    rep(i,0,n){
      if(s[i]!=t[i]){
        if(done){
          res=false;
        }else if(diff!=-1){
          if(s[diff]==s[i]&&t[diff]==t[i]){
            res=true;
          }
          done=true;
        }else if(diff==-1){
          diff=i;
        }
      }
    }
    if(res)cout<<"Yes\n";
    else cout<<"No\n";
  }
  
  
  return 0;
}