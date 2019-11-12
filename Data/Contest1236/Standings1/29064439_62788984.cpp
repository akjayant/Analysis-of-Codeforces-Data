#include <bits/stdc++.h>
using namespace std;
int T , a , b , c, res1 , res2;
int main( void ) {
  scanf("%d",&T);
  while( T-- ) {
    scanf("%d%d%d",&a,&b,&c) , res1 = res2 = 0;
    int ta = a , tb = b , tc = c;
    res1 += min( b , ( c / 2 ) ) * 3;
    tb -= min( b , ( c / 2 ) );
    res1 += min( a , ( tb / 2 ) ) * 3;
    tb = b;
    res2 += min( a , ( b / 2 ) ) * 3;
    tb -= min( a , ( b / 2 ) ) * 2;
    res2 += min( tb , ( c / 2 ) ) * 3;
    printf("%d\n",max( res1 , res2 ));
  }
  return 0;
}
