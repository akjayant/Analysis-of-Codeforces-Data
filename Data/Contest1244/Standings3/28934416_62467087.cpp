// Isaunoya
#include<bits/stdc++.h>
using namespace std ;
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
  int t = read() ;
  while(t --) {
    int a = read() , b = read() , c = read() , d = read() , k = read() ;
    int ans1 = (a + c - 1) / c ;
    int ans2 = (b + d - 1) / d ;
    if(ans1 + ans2 > k) { puts("-1") ; continue ; }
    printf("%d %d\n" , ans1 , ans2) ;
  }
	return 0 ;
}