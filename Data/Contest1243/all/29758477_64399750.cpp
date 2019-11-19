#include <bits/stdc++.h>
using namespace std;
#define LL long long
 
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    int q = 1;
   // cin >> q;
    while( q-- ) {
        LL n ;
        cin >> n;
        int c = 0;
        LL an = 1;
        for ( LL i = 2; i <= 1000001; i++ ) {
            if( n % i == 0 ) {
                an = i ;
                c = 1;
                while( n % i == 0 ) {
                    n = n / i;
                }
                break;
            }
        }
        if ( n == 1ll ) {
            cout << an ;
        }
        else if( c == 0 ) {
            cout << n ;
        }
        else {
            cout << 1;
        }
    }
    return 0;
}