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
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }
        
        int ans = 1;
        for(int j = 2; j <= n ; j++ ) {
            int x = 0;
            for ( int i = 0; i < n; i++ ) {
                if( a[i] >= j ) {
                    x++;
                }
            }
            //cout << j << " " << x <<
            if( x >= j ){
                ans = j;
            }
            else {
                break;
            }
        }
        cout << ans << "\n";
        
    }
    return 0;
}