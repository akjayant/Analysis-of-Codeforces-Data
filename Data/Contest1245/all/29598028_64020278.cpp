#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5+2; 
const int M = 1e9+7 ;

long long fibo [N] ;

int main() { 
     string s ;
     cin >> s ;
     fibo[0] =fibo[1] = 1 ;
     for ( int i = 2 ; i <N ; ++i ) 
          fibo[i] = fibo[i-1]+fibo[i-2], fibo[i]%=M ;
     int cntU=0, cntN=0; 
     long long ans = 1 ;
     s.push_back ( '1' ) ;
     for ( auto i:s){
          if ( i == 'm' || i == 'w' ) {
               ans = 0 ;
               break ;
          }
          if ( i=='u' ) cntU++ ;
          else {
               ans *= fibo[cntU] ;
               ans %= M; 
               cntU = 0 ;
          }
          if ( i=='n') cntN++;
          else {
               ans *= fibo[cntN] ;
               ans %= M ;
               cntN = 0 ;    
          }
     }
     cout << ans << '\n';
}