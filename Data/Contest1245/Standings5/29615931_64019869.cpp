#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
    string s; 
    getline( cin, s );
    
    long long fib[ s.length() + 1 ];
    fib[ 0 ] = 1; 
    fib[ 1 ] = 1; 
    for ( int k = 2; k <= s.length(); ++k ) {
        fib[ k ] = (fib[ k - 1 ] + fib[ k - 2 ])%MOD; 
    }
    
    int i = 0; 
    bool impossible = false; 
    long long ans = 1; 
    while ( i < s.length() ) {
        if ( s[ i ] == 'm'  ||  s[ i ] == 'w' ) {
            impossible = true; 
            break; 
        }    
        
        int j = i; 
        if ( s[ j ] == 'u' ||  s[ j ] == 'n' ) {
            while ( j < s.length() - 1  &&  s[ j ] == s[ j + 1 ] ) {
                j++; 
            }
        } 
        ans = (ans*fib[ j - i + 1 ])%MOD;
        i = j + 1; 
    }
    
    if ( impossible ) {
        cout << 0 << endl;
    } else {
        cout << ans << endl; 
    }
    
    return 0;
}