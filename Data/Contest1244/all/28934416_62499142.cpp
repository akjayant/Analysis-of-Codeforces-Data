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
int n , k ;
const int N = 100000 + 5 ;
int a[N] ;

signed main() {
  n = read() ; k = read() ;
  for(register int i = 1 ; i <= n ; i ++) a[i] = read() ;
  sort(a + 1 , a + n + 1) ; int lef = 1 , rig = n ;
  while(a[lef] == a[lef + 1]) lef ++ ;
  while(a[rig] == a[rig - 1]) rig -- ;
  while(lef < rig) {
    if(lef >= n - rig + 1) { int tot = (n - rig + 1) * (a[rig] - a[rig - 1]) ;
      if(k < tot) return ! printf("%lld\n" , a[rig] - k / (n - rig + 1) - a[lef]) ;
      rig -- ;
      k -= tot ;
      while(a[rig] == a[rig - 1]) rig -- ;
    }
    else { int tot = lef * (a[lef + 1] - a[lef]) ;
      if(k < tot) return ! printf("%lld\n" , a[rig] - k / lef - a[lef]) ;
      lef ++ ;
      k -= tot ;
      while(a[lef] == a[lef + 1]) lef ++ ;
    }
  }
  puts("0") ;
	return 0 ;
}
