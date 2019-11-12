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
        string s, t;
        cin >> s >> t;
        int count = 0, indx1 = -1, indx2 = -1;
        for ( int j = 0; j < n; j++ ) {
            if ( s[j] != t[j] ) {
                if ( indx1 == -1 ) {
                    indx1 = j;
                } else {
                    indx2 = j;
                }
                count++;
            }
        }
        if ( count == 1 ) {
            cout << "NO" << '\n';
            continue;
        }

        if ( count > 2 ) {
            cout << "NO" << '\n';
            continue;
        }

        if ( count == 0 ) {
            cout << "YES" << '\n';
            continue;
        }

        if ( s[indx1] == s[indx2] && t[indx1] == t[indx2] ) {
            cout << "YES" << '\n';
            continue;
        } else {
            cout << "NO" << '\n';
            continue;
        }
    }

}

int32_t main( ) {
    IOS
    input( );
    solve( );
    return 0;

}
