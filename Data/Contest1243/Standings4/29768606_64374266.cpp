#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int maxn = 1e5 + 7;
long long mod = 1e9 + 7;


mt19937 ran( time( 0 ));


inline int random( ) {
    return abs(( int ) ran( ));
}

int k;

void input( ) {
    cin >> k;
}

void solve( ) {
    for ( int i = 0; i < k; i++ ) {
        int n;
        cin >> n;
        vector < int > desk;
        int temp;
        for ( int j = 0; j < n; j++ ) {
            cin >> temp;
            desk.push_back( temp );
        }
        sort( desk.begin( ), desk.end( ));
        int ans = 0;
        for ( int j = 0; j < n; j++ ) {
            ans = max( ans, min( n - j, desk[j] ));
        }
        cout << ans << '\n';
    }

}

int32_t main( ) {
    IOS
    input( );
    solve( );
    return 0;

}
