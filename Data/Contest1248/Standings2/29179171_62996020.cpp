#include <bits/stdc++.h>

#define FOR(i, a, b) for(long i = (long)a;i < (long)b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(long i = (long)b-1;i >= (long)a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#ifdef ENABLE_DEBUG
#define dump(x) cerr<<#x"="<<x<<endl;
#define dumparr(x,n) cerr<<#x"["<<n<<"]="<<x[n]<<endl;
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)
#else
#define dump(x)
#define dumparr(x,n)
#define DEBUG_PRINT(...) 
#endif

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
void print_pair(pll a){
  cerr<<"("<<a.first<<", "<<a.second<<") ";
}
template<class S,class T>
std::ostream& operator<<(std::ostream& os,pair<S,T> a){
  os << "(" << a.first << "," << a.second << ")";
  return os;
}
template<class T>
std::ostream& operator<<(std::ostream& os,vector<T> a){
  os << "[ ";
  REP(a.size()){
    os<< a[i] << " ";
  }
  os<< " ]";
  return os;
}
const long long max_cache=1000000;
long long cache_fact[max_cache],cache_inv_fact[max_cache];
long long combination_cached(long long n,long long r,long long m){
  if(r<0||r>n)return 0;
  if(r==0||r==n)return 1;
  static bool cached=false;
  if(cached==false){
    cached=true;
    cache_inv_fact[1]=1;
    for (long long i = 2; i < max_cache; i++) {
      cache_inv_fact[i]=(m-m/i)*cache_inv_fact[m%i]%m;
    }
    for (long long i = 2; i < max_cache; i++){
      cache_inv_fact[i]=cache_inv_fact[i]*cache_inv_fact[i-1]%m;
    }
    cache_fact[0]=1;
    for (long long i = 1; i < max_cache; i++) {
      cache_fact[i]=cache_fact[i-1]*i%m;
    }
  }
  r=min(r,n-r);
  return cache_fact[n]*cache_inv_fact[r]%m*cache_inv_fact[n-r]%m;
}
const ll MOD=1000000007LL;
int main(){
  ll n,m;
  cin>>n>>m;
  ll ans=0;
  REP(m/2+1){
    ans+=combination_cached(m-i,i,MOD);
    ans%=MOD;
  }
  FOR(i,1,n/2+1){
    ans+=combination_cached(n-i,i,MOD);
    ans%=MOD;
  }
  cout<<ans*2%MOD<<endl;
  return 0;
}

