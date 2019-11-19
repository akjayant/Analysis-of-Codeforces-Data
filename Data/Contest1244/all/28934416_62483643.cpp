// Isaunoya
#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define fi first
#define se second
#define pb push_back
inline int read() {
  register int x = 0 , f = 1 ;
  register char c = getchar() ;
  for( ; ! isdigit(c) ; c = getchar()) if(c == '-') f = -1 ;
  for( ; isdigit(c) ; c = getchar()) x = (x << 1) + (x << 3) + (c & 15) ;
  return x * f ;
}
template < typename T > inline bool cmax(T & x , T y) {
	return x < y ? (x = y) , 1 : 0 ;
}
template < typename T > inline bool cmin(T & x , T y) {
	return x > y ? (x = y) , 1 : 0 ;
}
inline int QP(int x , int y , int Mod){ int ans = 1 ;
  for( ; y ; y >>= 1 , x = (x * x) % Mod)
    if(y & 1) ans = (ans * x) % Mod ;
  return ans ;
}

int n ;
const int N = 100000 + 5 ;
int a[N][4] ;
vector < int > G[N] ;
int deg[N] ;
int p[4] ;
int ans[4] ;
int tmp = 0 ;
int cnt = 1 ;
int pp[N] ;
inline void Dfs(int u , int fa) {
  tmp += a[u][p[(cnt ++ - 1) % 3 + 1]] ;
  for( int v : G[u] )
    if(v == fa) continue ;
    else Dfs(v , u) ;
}
inline void Get(int u , int fa) {
  pp[u] = ans[(cnt ++ - 1) % 3 + 1] ;
  for( int v : G[u])
    if(v == fa) continue ;
    else Get(v , u) ;
}
signed main(){
  n = read() ;
  for(register int i = 1 ; i <= n ; i ++) a[i][1] = read() ;
  for(register int i = 1 ; i <= n ; i ++) a[i][2] = read() ;
  for(register int i = 1 ; i <= n ; i ++) a[i][3] = read() ;
  for(register int i = 1 ; i <= n - 1 ; i ++) {
    int u = read() , v = read() ;
    G[u].push_back(v) ;
    G[v].push_back(u) ;
    deg[u] ++ ;
    deg[v] ++ ;
    if(deg[u] > 2) return puts("-1") , 0 ;
    if(deg[v] > 2) return puts("-1") , 0 ;
  }
  int bg = 0 ;
  for(register int i = 1 ; i <= n ; i ++)
    if(G[i].size() == 1) { bg = i ; break ; }
  for(register int i = 1 ; i <= 3 ; i ++) p[i] = i ;
  int val = LLONG_MAX ;
  do {
    tmp = 0 ; cnt = 1 ;
    Dfs(bg , 0) ;
    if(tmp < val) {
      val = tmp ;
      for(register int i = 1 ; i <= 3 ; i ++) ans[i] = p[i] ;
    }
  } while(next_permutation(p + 1 , p + 4)) ;
  printf("%lld\n" , val) ;
  cnt = 1 ;
  Get(bg , 0) ;
  for(register int i = 1 ; i <= n ; i ++)
    printf("%lld " , pp[i]) ;
  return 0 ;
}
