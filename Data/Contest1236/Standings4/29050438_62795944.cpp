//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define MOD 1000000007
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

i64 ans, N, M;

i64 fastpow( i64 b , i64 e )
{
    b %= MOD;
    i64 ans = 1;
    while( e > 0 )
    {
        if( e & 1 )
            ans = ( ans * b ) % MOD;
        
        b = ( b * b ) % MOD;
        e >>= 1;
    }
    return ans;
}

int main()
{
    optimiza_io
    cin >> N >> M;
    i64 b = fastpow( 2 , M );
    b = ( b - 1 + MOD ) % MOD;
    ans = fastpow( b , N );
    cout << ans;
    return 0;
}