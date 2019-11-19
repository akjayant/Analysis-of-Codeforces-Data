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
int n ;
const int N = 1000 + 5 ;
int a[N] ;
inline int digit() {
  register char c = getchar() ;
  while(isspace(c)) c = getchar() ;
  return c - '0' ;
}
signed main() {
  int t = read() ;
  while(t --) {
    n = read() ; int ans = n ;
    for(register int i = 1 ; i <= n ;  i++) a[i - 1] = digit() ;
    for(register int i = 0 ; i <= n - 1 ; i ++)
      if(a[i]) { cmax(ans , (n - i) * 2) ; break ; }
    for(register int i = n - 1 ; i >= 0 ; i --)
      if(a[i]) { cmax(ans , (i + 1) * 2) ;  break ; }
    printf("%d\n" , ans) ;
  }
	return 0 ;
}
