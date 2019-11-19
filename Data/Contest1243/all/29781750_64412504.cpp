#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
 
using ll = long long;
using P = std::pair<ll, ll>;
 
#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug " << i << std::endl
 
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, std::pair<T1, T2> pa) {
  return os << pa.first << " " << pa.second;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (int i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}
 
template<typename T1,typename T2>
inline bool chmax(T1& a,T2 b){return a<b && (a=b,true);}
 
template<typename T1,typename T2>
inline bool chmin(T1& a,T2 b){return a>b && (a=b,true);}
 
ll pow_mod(ll a, ll b, ll mod=-1) {
  if ((a == 0)||(mod!=-1&&a%mod==0)) {
    return 0;
  }
 
  ll x = 1;
 
  while (b > 0) {
    if (b & 1) {
      x = (mod!=-1)?(x * a) % mod:x*a;
    }
    a = (mod!=-1)?(a * a) % mod:a*a;
    b >>= 1;
  }
  return x;
}
 
// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

// UnionFind
template<class T>
class UnionFind {
  private:
  std::vector<T> uni;
  T num;

  public:
  UnionFind(T s) : uni(s, -1), num(s) {}

  //頂点aが所属するグループ
  T root(T a) {
    if (uni[a] < 0) {
      return a;
    }
    return uni[a] = root(uni[a]);
  }

  // a,bをつなげる
  bool connect(T a, T b) {
    a = root(a);
    b = root(b);
    if (a == b) {
      return false;
    }

    if (uni[a] > uni[b]) {
      std::swap(a, b);
    }

    uni[a] += uni[b];
    uni[b] = a;
    return true;
  }

  // a,bが同グループか確認
  bool isConnect(T a, T b) { return root(a) == root(b); }

  // aが属するグループの要素数
  T size(T a) { return -uni[root(a)]; }

  //グループ数を返す
  T groups() {
    std::set<T> b;
    for (T i = 0; i < num; i++) {
      b.insert(root(i));
    }
    return b.size();
  }
};
 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll n,m;
  std::cin>>n>>m;

  std::set<P> graph;

  rep(i,0,m){
    ll a,b;
    std::cin>>a>>b;
    a--;b--;
    if(a>b)std::swap(a,b);
    graph.insert({a,b});
  }

  ll ans=0;

  std::set<ll> unused;

  rep(i,0,n)unused.insert(i);

  while(!unused.empty()){
    ll root=*unused.begin();
    std::vector<ll> temp;
    temp.push_back(root);

    bool flag=true;
    while(flag){
      flag=false;
      bool flag2=false;
      for(ll e:temp){
        for(ll next:unused){
          if(graph.find({std::min(e,next),std::max(e,next)})==graph.end()){
            flag=true;
            flag2=true;
            temp.push_back(next);
            unused.erase(next);
            break;
          }
        }
        if(flag2)break;
      }
    }

    ans++;
  }

  std::cout<<ans-1;

 
  return 0;
}