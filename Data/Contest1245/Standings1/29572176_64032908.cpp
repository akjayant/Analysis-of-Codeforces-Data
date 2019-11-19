#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
/*#ifndef __LOCAL__ 
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif*/ 
 
using namespace std;
using namespace __gnu_pbds;
 
#define int int64_t
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ost;
 
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<set<int>> vsi;
 
#define endl "\n"
#define all(x) x.begin(),x.end()
#define pb push_back
#define F first
#define S second
#define fore(i,a,b) for(int i=(a);i<=(b);++i)
#define rep(i,n) for(int i=0;i<n;++i)
#define sz(x) int(x.size())
#define debug(x) cout<<#x<<" "<<x<<endl
#define IOS  ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0)
 
 
const int N1=100*1000;
const int N2=1000*1000;
const int mod=1e9+7;
 
int min3(int a,int b,int c){return min(a,min(b,c));}
int max3(int a,int b,int c){return max(a,max(b,c));}
int min4(int a,int b,int c,int d){return min(min(a,b),min(c,d));}
int max4(int a,int b,int c,int d){return max(max(a,b),max(c,d));}
 
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T>
istream& operator >> (istream& is,vector<T>& vec){
  for(T &x:vec)is>>x;
  //for(int i=0;i<vec.size();++i)is>>x[i];
  return is;
}
 
template<typename T>
ostream& operator << (ostream& os,vector<T>& vec){
  for(int i=0;i<vec.size();++i){
    os<<vec[i]<<(i+1==vec.size()?"":" ");
  }
  return os;
}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ll FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
 
struct chash {
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x); }
};
//unordered_map <int, int, chash> m; way to use this 
//the way you're supposed to do is it by initializing FIXED_RANDOM with something like chrono::steady_clock::now().time_since_epoch().count()(current time in microseconds or something like that) and instead of hash_f(x) do hash_f(FIXED_RANDOM^x) 
 
int getRand(int l, int r)
{
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
ll mpow(ll a, ll b){
  ll ret=1;
  while(b>0){
    if(b&1LL)(ret*=a)%=mod;
    (a*=a)%=mod;
    b>>=1LL;
  }
  return ret;
}
int par[2062];
int x[2062],y[2062];
int c[2062],k[2062];
int get(int i){
  while(par[i]!=i){
    par[i]=par[par[i]];
    i=par[i];
  }
  return i;
}
void merge(int a,int b){
  int par_a=get(a);
  int par_b=get(b);
  if(par_a!=par_b){
    par[par_b]=par_a;
  }
}
int a[4*N2+6000],b[4*N2+6000];
void solve(){
  int n;cin>>n;
  for(int i=1;i<=n;++i){
    cin>>x[i]>>y[i];
  }
  for(int i=1;i<=n;++i)cin>>c[i];
  for(int i=1;i<=n;++i)cin>>k[i];
  //add a vertex n+1 to all 1 to n and add it's cost and build a mst 
  vector<pii> v;
  int cnt=1;
  for(int i=1;i<=n+1;++i)par[i]=i;
  for(int i=1;i<=n;++i){
    for(int j=i+1;j<=n;++j){
      //add edge 
      int dist=abs(x[i]-x[j])+abs(y[i]-y[j]);
      a[cnt]=i;
      b[cnt]=j;
      v.pb({dist*(k[i]+k[j]),cnt});
      cnt++;
    }
  }
  for(int i=1;i<=n;++i){
    a[cnt]=i;
    b[cnt]=n+1;
    v.pb({c[i],cnt});
    cnt++;
  }
  //now do kruskal
  sort(all(v));
  int mst=0;
  vi po;
  vector<pair<int,int> >edges;
  for(auto it:v){
    int id=it.second;
    int wt=it.first;
    int u=a[id];
    int v=b[id];
    if(get(u)!=get(v)){
      merge(u,v);
      mst+=wt;
      if(v==(n+1)){po.pb(u);}
      else edges.pb({u,v});
    }
  } 
  cout<<mst<<endl;//minimum amount of yen needed 
  cout<<po.size()<<endl;
  for(int x:po)cout<<x<<" ";
  if((int)po.size()>0)cout<<endl;
  cout<<edges.size()<<endl;
  for(auto it:edges){
    cout<<it.F<<" "<<it.S<<endl; 
  }
  if((int)edges.size()>0)cout<<endl;
}
int32_t  main(){
  IOS;
  cout<<(fixed)<<setprecision(6);
  solve();
  return 0;
}
