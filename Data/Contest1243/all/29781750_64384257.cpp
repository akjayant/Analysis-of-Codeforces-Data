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


 
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  ll k;
  std::cin>>k;

  rep(_,0,k){
    ll n;
    std::cin>>n;

    std::string s,t;
    std::cin>>s>>t;

    std::vector<ll> cnt(26,0);

    rep(i,0,n){
      cnt[s[i]-'a']++;
      cnt[t[i]-'a']++;
    }

    bool flag=true;

    rep(i,0,26){
      if(cnt[i]%2!=0)flag=false;
    }

    if(flag){
      std::cout<<"Yes\n";

      std::vector<P> ans;

      rep(i,0,n){
        if(s[i]==t[i]){
          ans.push_back({i,i});
        }else{
          bool flag=false;
          rep(j,i+1,n){
            if(s[j]==s[i]){
              ans.push_back({j,i});
              std::swap(s[j],t[i]);
              flag=true;
              break;
            }
          }

          if(!flag){
            rep(j,i+1,n){
              if(s[i]==t[j]){
                ans.push_back({i+1,j});
                ans.push_back({i+1,i});
                std::swap(s[i+1],t[j]);
                std::swap(s[i+1],t[i]);
                break;
              }
            }
          }
        }
      }

      std::cout<<ans.size()<<"\n";
      for(P e:ans){
        std::cout<<e.first+1<<" "<<e.second+1<<"\n";
      }
    }else{
      std::cout<<"No\n";
    }
  }
 
  return 0;
}