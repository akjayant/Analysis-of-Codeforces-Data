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
umap<ll,uset<ll>>loc_s,loc_t;
vll res;

void sw(ll i,ll j){
  loc_s[s[i]-'a'].erase(i);
  loc_s[t[j]-'a'].insert(i);
  loc_t[t[j]-'a'].erase(j);
  loc_t[s[i]-'a'].insert(j);
  swap(s[i],t[j]);
  res.pb({i+1,j+1});
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin>>q;
  rep(_q,0,q){
    cin>>n>>s>>t;
    loc_s.clear(),loc_t.clear();
    res.clear();
    rep(i,0,n){
      loc_s[s[i]-'a'].insert(i);
      loc_t[t[i]-'a'].insert(i);
    }
    rep(i,0,n){
      ll sm_s=0,sm_t=0;
      // trav(_,loc_s)sm_s+=sz(_.se);
      // trav(_,loc_t)sm_t+=sz(_.se);
      // cout<<"T "<<sm_s<<" "<<sm_t<<endl;
      ll c_s=s[i]-'a',c_t=t[i]-'a';
      loc_s[c_s].erase(i);
      if(s[i]!=t[i]){
        if(sz(loc_s[c_s])){
          // cout<<"across\n";
          sw(*begin(loc_s[c_s]),i);
        }
        // check last ineq
        else if(sz(loc_t[c_s])){
          // cout<<"zig\n";
          sw(i+1,*begin(loc_t[c_s]));
          sw(i+1,i);
        }
        else{
          cout<<"No\n";
          goto outer;
        }
      }
      loc_t[c_s].erase(i);
    }
    cout<<"Yes\n";
    cout<<sz(res)<<"\n";
    rep(i,0,sz(res))cout<<res[i].fi<<" "<<res[i].se<<"\n";
    outer:;
  }
  
  
  return 0;
}