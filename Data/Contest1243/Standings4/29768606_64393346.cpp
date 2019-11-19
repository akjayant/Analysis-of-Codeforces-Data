#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int maxn = 1e5 + 7;
long long mod = 1e9 + 7;


mt19937 ran( time( 0 ));


inline int random( ) {
    return abs(( int ) ran( ));
}

long long n;

void input( ) {
    cin >> n;
}


inline long long gcd( long long a, long long b ) {
    if ( b > a ) swap( a, b );
    return b ? gcd( b, a % b ) : a;
}

void solve( ) {
    long long ans = n;
    for ( long long i = 2; i * i <= n; i++ ) {
        if ( n % i == 0 ) {
            ans = gcd( ans, i );
            ans = gcd( ans, n / i );
        }
    }
    cout << ans;

}

int32_t main( ) {
    IOS
    input( );
    solve( );
    return 0;

}
