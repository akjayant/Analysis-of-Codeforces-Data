//Tanuj Khattar
// This question was already there so used this code
#include<bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI >     VVI;
typedef long long int     LL;
 
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
 
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 



const int N = 2e5 + 10;
set<int> unvis;
set<int> g[N];
int sz;
void dfs(int x){
  sz++;
  assert(unvis.count(x));
  unvis.erase(x);
  bool ok = true;
  while(ok){
    ok = false;
    for(auto y : unvis){
      if(g[x].count(y))continue;
      dfs(y);
      ok = true;
      break;
    }
  }
}
int main()
{
  int n, m;
  si(n);si(m);
  REP(i, m){
    int x, y;
    si(x);si(y);
    g[x].insert(y);
    g[y].insert(x);
  }
  for(int i = 1; i <= n; ++i){
    unvis.insert(i);
  }
  VI ans;
  for(int i = 1; i <= n; ++i){
    if(unvis.count(i)){
      sz = 0;
      dfs(i);
      ans.PB(sz);
    }
  }
  dout(SZ(ans)-1);
  return 0;
}