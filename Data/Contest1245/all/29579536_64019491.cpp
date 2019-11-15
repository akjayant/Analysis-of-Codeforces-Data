#include <cstdio>
#include <cstring>
#include <algorithm>

int T , a , b;

int gcd( int a , int b ) { return b ? gcd( b , a % b ) : a; }

int main( void ) {
  scanf("%d",&T);
  while( T-- ) {
    scanf("%d%d",&a,&b);
    if( gcd( a , b ) == 1 ) puts("Finite");
    else puts("Infinite");
  }
  return 0;
}
