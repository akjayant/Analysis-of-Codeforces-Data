#include <cstdio>
#include <cstring>
const int MAXN = 3e2 + 1;
int ans[MAXN][MAXN] , n , tot;
int main( void ) {
  scanf("%d",&n);
  for( int i = 1 ; i <= n ; ++i ) {
    if( i & 1 ) 
      for( int j = 1 ; j <= n ; ++j ) ans[i][j] = ++tot;
    else 
      for( int j = n ; j ; --j ) ans[i][j] = ++tot;
  }
  for( int i = 1 ; i <= n ; ++i )
    for( int j = 1 ; j <= n ; ++j )
      printf("%d%c",ans[j][i]," \n"[j==n]);
  return 0;
}
