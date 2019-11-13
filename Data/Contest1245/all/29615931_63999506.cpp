#include <bits/stdc++.h>
using namespace std;

int gcd ( int a, int b ) {
    if ( a > b ) {
        swap( a, b ); 
    }
    
    while ( a > 0 ) {
        b = b % a; 
        swap( a, b ); 
    }
    
    return b; 
}

int main() {
    int t; 
    cin >> t; 
    
    for ( int test = 0; test < t; ++test ) {
        int a, b; 
        cin >> a >> b;
        
        if ( gcd( a, b ) == 1 ) {
            cout << "Finite" << endl; 
        } else {
            cout << "Infinite" << endl; 
        }    
    }
    

    return 0;
}
