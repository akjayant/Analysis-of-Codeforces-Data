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

ll n,p1;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin>>n;
  p1=-1;
  rep(i,2,sqrt(n)+10){
    if(i>=n)break;
    if(n%i==0){
      ll n_=n;
      while(n_%i==0)n_/=i;
      if(n_==1)p1=i;
      else p1=-2;
      break;
    }
  }
  if(p1==-1)cout<<n<<"\n";
  else if(p1==-2)cout<<"1\n";
  else cout<<p1<<"\n";
  return 0;
}