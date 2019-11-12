#include <bits/stdc++.h>
using namespace std;
#define LL long long
 
 
int a[200000];
 
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    int q = 1;
    cin >> q;
    while( q-- ) {
        int n ;
        cin >> n;
        string  s, t;
        cin >> s >> t;
        int c = 0;
        int f = 1;
        for ( int i = 0; i < n; i++ ) {
            if( s[i] != t[i] ) {
                a[c] = i;
                c++;
            }
            if( c > 2 || ( c == 2 && ( s[a[0]] != s[a[1]] || t[a[0]] != t[a[1]] ) ) ){
                f = 0;
                break;
            }
        }
        if( f == 1 && c == 2) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }
    return 0;
}