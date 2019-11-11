#include <bits/stdc++.h>
using namespace std ;
int main() { 
     int t;
     cin >> t;
     while(t--) {
          int n, a, b, c; 
          cin >> n >> a >> b >> c ;
          string s ;
          cin >> s;
          int a1 = 0, b1 = 0, c1 = 0;
          for ( auto i:s ) { 
               if ( i =='R') a1++ ;
               else if ( i == 'P') b1++ ;
               else c1++ ;
          }
          int optA = min ( a, c1 ), optB =min (b, a1), optC=min(c, b1) ;
          if ( optA+optB+optC >= ceil(n/2.0) ) {
               cout << "YES\n";
               for ( auto i:s ) { 
                    if ( i == 'R' ) { 
                         if ( b ) cout << "P", b--, optB--;
                         else if ( c > optC ) cout << "S", c-- ;
                         else cout << "R",a--;
                    }
                    if ( i == 'P' ) { 
                         if ( c ) cout << "S", c--, optC--;
                         else if ( b > optB ) cout << "P", b-- ;
                         else cout << "R",a--;
                    }if ( i == 'S' ) { 
                         if ( a ) cout << "R", a--, optA--;
                         else if ( b > optB ) cout << "P", b-- ;
                         else cout << "S",c--;
                    }
               }cout << "\n";
          }
          else cout << "NO\n";
     }
}