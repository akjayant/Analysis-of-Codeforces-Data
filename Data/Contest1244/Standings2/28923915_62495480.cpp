//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 500005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

int N, K;
int a[MAX], alt[MAX], nw[MAX];
bool ch[MAX];


bool cyclic() {
    for( int i = 0; i < N; i ++ )
        if( a[i] == a[(i - 1 + N) % N] or a[i] == a[(i + 1) % N] )
            return 0;
    return 1;
}

int main()
{
    optimiza_io
    cin >> N >> K;
    for( int i = 0; i < N; i ++ ) {
        char x;
        cin >> x;
        if( x == 'W' )
            a[i] = 1;
    }
    
    if( cyclic( ) ) {
        for( int i = 0; i < N; i ++ ) {
            int val = a[i];
            if( K & 1 ) 
                val = ! val;
            cout << ( val ? 'W' : 'B' );
        }
        exit( 0 );
    }
    
    for( int i = N; i < 2*N; i ++ )
        a[i] = a[i - N];
    
    alt[2*N - 1] = 1;
    for( int i = 2*N - 2; i >= 0; i -- ) {
        if( a[i] == a[i + 1] )
            alt[i] = 1;
        else
            alt[i] = alt[i + 1] + 1; 
    }
    
    for( int i = 0; i < N; i ++ )
        if( a[i] == a[( i - 1 + N ) % N] ) {
            int nxt = i + alt[i] - 1;
            if( nxt == i )
                continue;
            int l = i + 1;
            int r = nxt - 1;
            if( ( r - l + 1 ) & 1 ) { 
                int ops = min( K , ( r - l + 2 ) / 2 );
                bool cent = ops & 1;
                while( l <= r && ops ) {
                    ops--;
                    nw[l] = a[i];
                    nw[r] = a[i];
                    ch[l++] = 1;
                    ch[r--] = 1;
                }
                while( l <= r && cent ) {
                    nw[l] = ! a[l];
                    nw[r] = ! a[r];
                    ch[l++] = 1;
                    ch[r--] = 1;
                }
            }
            else {                
                int ops = min( K , ( r - l + 2 ) / 2 );
                bool cent = ops & 1;
                while( l <= r && ops ) {
                    ops--;
                    nw[l] = a[i];
                    nw[r] = a[nxt];
                    ch[l++] = 1;
                    ch[r--] = 1;
                }
                while( l <= r && cent ) {
                    nw[l] = ! a[l];
                    nw[r] = ! a[r];
                    ch[l++] = 1;
                    ch[r--] = 1;
                }
                
            }
        }
        
    
    for( int i = 0; i < N; i ++ ) {
        if( ch[i] or ch[i + N] )
            a[i] = ch[i] ? nw[i] : nw[i + N];
        int val = a[i];
        cout << ( val ? 'W' : 'B' );
    }
    return 0;
}

/*

10 3
WWBWBWBWBB

*/