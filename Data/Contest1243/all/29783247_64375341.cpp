#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin >> t;
    while( t-- ) {
        cin >> n;
        long long v[n];
        for( int i = 0; i < n; i++ ) {
            cin >> v[i];
        }
        sort( v, v+n );
        reverse(v, v+n );
        long long ans = 1;
        for( long long i = 0; i < n; i++ ) {
            ans = max(ans, min(v[i], i+1) );
        }
        cout << ans << '\n';
    }
    return 0;
}