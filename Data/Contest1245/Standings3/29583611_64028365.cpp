#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;

int L[100], R[100];
long long dp[100][3][3][3][3];

P test( int idx, int bit, int lstate, int rstate){
    if( lstate && L[idx] && bit == 0 )
        return P(-1, -1);
    if( rstate && !R[idx] && bit == 1 )
        return P(-1, -1);
    int nl = lstate, nr = rstate;
    if( bit == 1 && !L[idx])
        nl = 0;
    if( bit == 0 && R[idx])
        nr = 0;
    return P(nl, nr);
}

long long solve( int idx, int al, int ar, int bl, int br){
    if(idx < 0 )
        return 1;
    long long& ref = dp[idx][al][ar][bl][br];
    if(ref != -1 )
        return ref;
    ref = 0;
    P a1 = test(idx, 1, al, ar);
    P b1 = test(idx, 0, bl, br);

    P a2 = test(idx, 0, al, ar);
    P b2 = test(idx, 1, bl, br);

    if( a1.first != -1 && b1.first != -1 )
        ref += solve( idx - 1, a1.first, a1.second, b1.first, b1.second );
    
    if( a2.first != -1 && b2.first != -1 )
        ref += solve( idx - 1, a2.first, a2.second, b2.first, b2.second );
    
    if( a2.first != -1 && b1.first != -1 )
        ref += solve(idx - 1, a2.first, a2.second, b1.first, b1.second);
    
    return ref;
}

int main()
{
    int t;
    for(cin >> t; t--; ){
        int l, r;
        cin >> l >> r;
        for( int i = 0; i < 40; i++ ){
            if( l & (1LL << i) )
                L[i] = 1;
            else
                L[i] = 0;
            if(r & (1LL << i))
                R[i] = 1;
            else
                R[i] = 0;
        }
        memset( dp, -1, sizeof dp);
        cout << solve( 40, 1, 1, 1, 1 ) << endl;
    }

    return 0;
}
