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

        int m = 0;
        vector < pair < int, int > > ans;
        for ( int j = 0; j < n; j++ ) {
            if ( s[j] != t[j] ) {

                bool flag = false;

                for ( int q = j + 1; q < n; q++ ) {
                    if ( s[q] == s[j] ) {
                        ans.push_back( {q, j} );
                        char temp = t[j];
                        t[j] = s[j];
                        s[q] = temp;
                        m++;
                        flag = true;
                        break;
                    }
                }

                if ( flag ) continue;

                for ( int q = j + 1; q < n; q++ ) {
                    if ( t[q] == s[j] ) {
                        ans.push_back( {q, q} );
                        ans.push_back( {q, j} );
                        t[q] = s[q];
                        s[q] = t[j];
                        t[j] = s[j];
                        m += 2;
                        flag = true;
                        break;
                    }
                }

                if ( flag ) continue;


                m = 3 * n;
                break;

            }
        }

        if ( m <= 2 * n ) {
            cout << "Yes" << '\n';
            cout << m << '\n';
            for ( pair < int, int > x: ans ) {
                cout << x.first + 1 << " " << x.second + 1 << '\n';
            }
        } else {
            cout << "No" << '\n';
        }
    }


}

int32_t main( ) {
    IOS
    input( );
    solve( );
    return 0;

}
