#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t; 
    
    for ( int test = 0; test < t; ++test ) {
        int n; 
        cin >> n; 
        int a, b, c; 
        cin >> a >> b >> c; 
        cin.ignore();
        
        string s; 
        getline( cin, s );
        char ans[ n + 1 ] = { 0 };
        int wins = 0; 
        for ( int i = 0; i < s.length(); ++i ) {
            if ( s[ i ] == 'S'  &&  a > 0 ) {
                ans[ i ] = 'R'; 
                a--; 
                wins++; 
            } else if ( s[ i ] == 'R'  &&  b > 0 ) {
                ans[ i ] = 'P'; 
                b--;
                wins++; 
            } else if ( s[ i ] == 'P'  &&  c > 0 ) {
                ans[ i ] = 'S'; 
                c--; 
                wins++; 
            }
        }
        
        for ( int i = 0; i < n; ++i ) {
            if ( ans[ i ] == 0 ) {
                if ( a > 0 ) {
                    ans[ i ] = 'R'; 
                    a--;
                } else if ( b > 0 ) {
                    ans[ i ] = 'P'; 
                    b--; 
                } else {
                    ans[ i ] = 'S'; 
                    c--; 
                }
            }
        }
        
        if ( wins >= (n + 1)/2 ) {
            cout << "YES" << endl; 
            cout << ans << endl; 
        } else {
            cout << "NO" << endl;
        }
    }
    

    return 0;
}
