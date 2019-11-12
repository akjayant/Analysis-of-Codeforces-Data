#include <cstdio>
#include <cstring>
const int mod = 1e9 + 7;
int n , m;
int fpow( int b , int k ) {
  static int res;
  res = 1;
  while( k ) {
    if( k & 1 ) res = 1LL * res * b % mod;
    b = 1LL * b * b % mod;
    k >>= 1;
  }
  return res;
}
int main( void ) {
  scanf("%d%d",&n,&m);
  printf("%d",fpow( ( fpow( 2 , m ) - 1 + mod ) % mod , n ) );
  return 0;
}
