#include <bits/stdc++.h>

using namespace std;

typedef long long lol;

lol f[41][2][2][2][2];
int T , l , r;

lol dp( int dep , int a , int b , int lima , int limb , int upa , int upb ) {
  if( dep < 0 ) return 1;
  if( ~f[dep][a][b][upa][upb] ) return f[dep][a][b][upa][upb];
  int alim , blim;
  lol & res = f[dep][a][b][upa][upb];
  res = 0;
  alim = upa ? ( lima >> dep ) & 1 : 1;
  blim = upb ? ( limb >> dep ) & 1 : 1;
  for( int na = 0 ; na <= alim ; ++na ) 
    for( int nb = 0 ; nb <= blim ; ++nb ) 
      if( na + nb < 2 ) 
        res += dp( dep - 1 , na , nb , lima , limb , upa && ( na == alim ) , upb && ( nb == blim ) );
  return res;
}

lol solve( const int & lima , const int & limb ) { memset( f , -1 , sizeof f );return dp( 31 , 0 , 0 , lima , limb , 1 , 1 ); }

int main( void ) {
  memset( f , -1 , sizeof f );
  scanf("%d",&T);
  while( T-- ) {
    scanf("%d%d",&l,&r);
    if( l == 0 ) {
      printf("%I64d\n",solve( r , r ) );
    } else {
      lol ans = solve( r , r ) - solve( l - 1 , r ) * 2 + solve( l - 1 , l - 1 );
      printf("%I64d\n",ans);
    }
  }
  return 0;
}
