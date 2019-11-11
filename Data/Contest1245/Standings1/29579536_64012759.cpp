#include <cstdio>
#include <cstring>
#include <algorithm>

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

char str[N];
int f[N] , ans , n;

inline int Plus( const int & a , const int & b ) { return a + b >= mod  ? a + b - mod : a + b; }

int main( void ) {
  scanf("%s",str+1);
  n = strlen( str + 1 );
  for( int i = 1 ; i <= n ; ++i )
    if( str[i] == 'm' ) return puts("0"),0;
    else if( str[i] == 'w' ) return puts("0"),0;
  f[0] = 1 , f[1] = 1;
  for( int i = 2 ; i <= n ; ++i ) 
    f[i] = Plus( f[i - 1] , f[i - 2] );
  ans = 1;
  for( int i = 1 , r ; i <= n ; i = r + 1 ) {
    r = i;
    while( r < n && str[r + 1] == str[i] ) ++r;
    if( str[i] != 'u' && str[i] != 'n' ) continue;
    ans = 1LL * ans * f[r - i + 1] % mod;
  }
  printf("%d",ans);
  return 0;
}
