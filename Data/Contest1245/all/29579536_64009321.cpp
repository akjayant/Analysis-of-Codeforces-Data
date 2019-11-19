#include <bits/stdc++.h>

using namespace std;

typedef long long lol;
typedef pair<int,int> pii;

const int N = 2e3 + 11;

struct Edge {
  int u , v;
  lol val;
  bool operator < ( const Edge & rhs ) const { 
    return val < rhs.val;
  }
}edge[N * N];

int n , f[N] , tot , mark[N] , m;
lol val[N] , res , C[N] , K[N];
pii dat[N] , ans[N];

int find( const int & x ) { return x == f[x] ? x : f[x] = find( f[x] ); }

lol cost( const int & a , const int & b ) { return ( K[a] + K[b] ) * ( abs( dat[a].first - dat[b].first ) + abs( dat[a].second - dat[b].second ) ); }

int main( void ) {
  scanf("%d",&n);
  for( int i = 1 ; i <= n ; ++i ) {
    scanf("%d%d",&dat[i].first,&dat[i].second);
    f[i] = i;
  }
  for( int i = 1 ; i <= n ; ++i ) 
    scanf("%I64d",C + i) , res += C[i];
  for( int i = 1 ; i <= n ; ++i )
    scanf("%I64d", K + i );
  for( int i = 1 ; i <= n ; ++i )
    for( int j = 1 ; j <= n ; ++j )
      edge[++m] = (Edge) { i , j , cost( i , j ) };
  for( int i = 1 ; i <= n ; ++i ) val[i] = C[i];
  sort( edge + 1 , edge + 1 + m );
  for( int i = 1 ; i <= m ; ++i ) {
    int fu = find( edge[i].u ) , fv = find( edge[i].v );
    if( fu == fv ) continue;
    if( max( val[fu] , val[fv] ) <= edge[i].val ) continue;
    res -= max( val[fu] , val[fv] );
    if( val[fu] > val[fv] ) {
      f[fu] = fv;
    } else f[fv] = fu;
    res += edge[i].val;
    ans[++tot] = pii( edge[i].u , edge[i].v );
  }
  printf("%I64d\n",res);
  printf("%d\n",n - tot);
  for( int i = 1 ; i <= n ; ++i )
    if( !mark[find( i )] )
      mark[find( i )] = 1 , printf("%d ",find( i ) );
  putchar('\n');
  printf("%d\n",tot);
  for( int i = 1 ; i <= tot ; ++i ) printf("%d %d\n",ans[i].first,ans[i].second);
  return 0;
}
