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
signed main() {
  int n = read() ;
  int ans = 1 ;
  vector < int > v [400] ;
  while(ans <= n * n) {
    for(int i = 1 ; i <= n ; i ++) { v[i].push_back(ans ++) ; }
    if(ans > n * n) break ;
    for(int i = n ; i >= 1 ; i --) { v[i].push_back(ans ++ ) ; }
  }
  for( int i = 1 ; i <= n ; i ++ , puts(""))
    for(auto x : v[i]) printf("%lld " , x) ;
	return 0 ;
}
