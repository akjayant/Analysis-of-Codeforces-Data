#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
 
#if DEBUG
    #include "debug.h"
#else
    #define debug(args...)
#endif    

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;


#define M 1000000 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define fill(a,x) memset(a,x,sizeof(a))
#define F first
#define S second
#define FOR(i,a,b) for(int i = a; i<=b; ++i)
#define NFOR(i,a,b) for(int i = a; i>=b; --i)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = INT_MAX;
const int mod = 1e9+7;

const int N = 2e5 + 10;
inline int add(int x,int y){
  x += y;
  if(x >= mod) x -= mod;
  return x;
}
inline int mul(int x,int y){
  x = (1LL * x * y) % mod;
  return x;
}
clock_t time_p=clock();

vector<int>ans[301];

int32_t main(){
  fast;

  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);

  int n;
  cin >> n;
  // vector<int>A(n * n + 1);
  int pos = 0;
  FOR(i,1,n) {
    int off = 0;
    int ff = 0;
    pos++;
    FOR(j,1,n) {
      if(ff)ans[i].pb(pos + off);
      else ans[i].pb(n + 1 - pos + off);
      ff^=1;
      off += n;
      // ans[i].pb(pos + off);
    }
  }

  FOR(i,1,n) {
    for(auto x : ans[i])cout << x << " ";
    cout << "\n";
  }



  time_p=clock()-time_p;
  cerr<<"\nTime Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";

  return 0;
}