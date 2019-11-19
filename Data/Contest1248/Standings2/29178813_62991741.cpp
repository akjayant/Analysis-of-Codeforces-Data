// template version 1.13
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define infile "../test/sample-1.in"
#define int long long //{{{
const int INF=1e18;
const int MOD=1e9+7; //}}}

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define ceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}

int mod = 1e9+7;
struct mint { //{{{
  int x;
  mint(int x=0):x((x%mod+mod)%mod){}

  // ?= operator
  mint& operator+=(const mint a) { (x += a.x) %= mod; return *this; }
  mint& operator-=(const mint a) { (x += mod-a.x) %= mod; return *this; }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
  mint&operator/=(const mint&rhs){return *this*=rhs.inv();}

  mint operator+(const mint a) const { mint res(*this); return res+=a; }
  mint operator-(const mint a) const { mint res(*this); return res-=a; }
  mint operator*(const mint a) const { mint res(*this); return res*=a; }
  mint operator/(const mint&rhs)const{return mint(*this)/=rhs;}

  mint pow(int n)const{
    mint res(1),x(*this);
    if (n<0){
      n = -n;
      x =(*this).inv();
    }
    while(n){
      if(n&1)res*=x;
      x*=x;
      n>>=1;
    }
    return res;
  }
  mint inv()const{return pow(mod-2);}
  /*mint inv()const{
    int x,y;
    int g=extgcd(v,mod,x,y);
    assert(g==1);
    if(x<0)x+=mod;
    return mint(x);
    }*/
  friend ostream& operator<<(ostream&os,const mint&m){
    return os<<m.x;
  }
  bool operator<(const mint&r)const{return x<r.x;}
  bool operator==(const mint&r)const{return x==r.x;}
};
//}}}

int solve(){
  int n,m;cin>>n>>m;

  int z = max(n,m);

  vector<mint> dpw1(z);
  vector<mint> dpw2(z);
  vector<mint> dpb1(z);
  vector<mint> dpb2(z);
  dpw1[0] = 1;
  dpb1[0] = 1;
  rep(i, 1, z){
    dpw2[i] += dpw1[i-1];
    dpb2[i] += dpb1[i-1];

    dpw1[i] += dpb1[i-1];
    dpw1[i] += dpb2[i-1];

    dpb1[i] += dpw1[i-1];
    dpb1[i] += dpw2[i-1];
  }
  dump(dpw1);
  dump(dpw2);
  dump(dpb1);
  dump(dpb2);

  mint x = dpw1[m-1]+dpw2[m-1]+dpb1[m-1]+dpb2[m-1];
  mint y = dpw1[n-1]+dpw2[n-1]+dpb1[n-1]+dpb2[n-1];
  dump(x,y);
  cout << (x-2) + y << endl;

  return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}
