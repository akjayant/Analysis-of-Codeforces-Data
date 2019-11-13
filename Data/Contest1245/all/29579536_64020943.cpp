#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e2 + 11;
int n , a , b , c , ao , bo , co , res;
char str[N];
//a:Rock b:Paper c:Scissors
void solve( void ) {
  scanf("%d",&n);
  scanf("%d%d%d",&a,&b,&c);
  ao = bo = co = 0;
  scanf("%s",str+1);
  for( int i = 1 ; i <= n ; ++i )
    if( str[i] == 'R' )
      ++ao;
    else if( str[i] == 'P' )
      ++bo;
    else ++co;
  res = min( a , co ) + min( b , ao ) + min( c , bo );
  int ta = min( a , co ) , tb = min( b , ao ) , tc = min( c , bo );
  if( res < ( n + 1 ) / 2 ) { puts("NO"); return; }
  puts("YES");
  for( int i = 1 ; i <= n ; ++i ) {
    if( str[i] == 'R' ) {
      if( b ) putchar( 'P' ) , --b , --tb;
      else {
        if( a > ta ) putchar( 'R' ) , --a;
        else putchar( 'S' ) , --c;
      }
    } 
    if( str[i] == 'P' ) {
      if( c ) putchar( 'S' ) , --c , --tc;
      else {
        if( a > ta ) putchar( 'R' ) , --a;
        else putchar( 'P' ) , --b;
      }
    }
    if( str[i] == 'S' ) {
      if( a ) putchar( 'R' ) , --a , --ta;
      else {
        if( b > tb ) putchar( 'P' ) , --b;
        else putchar( 'S' ) , --c;
      }
    }
  }
  putchar('\n');
}
int main( void ) {
  int T;
  scanf("%d",&T);
  while( T-- ) solve();
  return 0;
}
