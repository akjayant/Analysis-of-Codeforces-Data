//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

int T, N;
string s;

int main()
{
    optimiza_io
    cin >> T;
    while( T -- ) {
        cin >> N;
        cin >> s;
        int mx = -1, mn = N;
        int ans = N;
        for( int i = 0; i < N; i ++ )
            if( s[i] == '1' ) {
                mx = max( mx , i );
                mn = min( mn , i );
            }
        if( mx != -1 ) {
            ans = max( ans , 2 * ( mx + 1 ) );
            ans = max( ans , 2 * ( N - mn ) );
        }
        cout << ans << "\n";
            
    }
    return 0;
}