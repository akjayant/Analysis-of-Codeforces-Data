//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

i64 N, mn, idx;
i64 cst[MAX][3];
i64 cl[MAX];
vector < i64 > ady[MAX];

void dfsans( i64 x , i64 c , i64 p , i64 t ) {
    cl[x] = c;
    for( auto v : ady[x] )
        if( v != p ) 
            dfsans( v , ( c + t + 3 ) % 3 , x , t );
}

i64 dfs( i64 x , i64 c , i64 p , i64 t ) {
    i64 ans = cst[x][c];
    for( auto v : ady[x] )
        if( v != p ) 
            ans += dfs( v , ( c + t + 3 ) % 3 , x , t );
    return ans;
}


bool line() {
    for( i64 i = 1; i <= N; i ++ ) {
        i64 x = ady[i].size();
        if( x > 2 )
            return false;
        if( x == 1 )
            idx = i;
    }
    return true;
}

int main()
{
    optimiza_io
    cin >> N;
    for( i64 c = 0; c < 3; c ++ )
        for( i64 i = 1; i <= N; i ++ )
            cin >> cst[i][c] ;
            
    for( i64 i = 1; i < N; i ++ ) {
        i64 u, v;
        cin >> u >> v;
        ady[u].push_back( v );
        ady[v].push_back( u );
    }
    
    if( ! line() ) {
        cout << "-1\n";
        exit( 0 );
    }
    
            
    i64 s1 = dfs( idx , 0 , -1 , 1 );
    i64 s2 = dfs( idx , 1 , -1 , 1 );
    i64 s3 = dfs( idx , 2 , -1 , 1 );    
    i64 s4 = dfs( idx , 0 , -1 , -1 );
    i64 s5 = dfs( idx , 1 , -1 , -1 );
    i64 s6 = dfs( idx , 2 , -1 , -1 );
    if( s1 <= s2 && s1 <= s3 && s1 <= s4 && s1 <= s5 && s1 <= s6 )
        mn = s1, dfsans( idx , 0 , -1 , 1 );
    else if( s2 <= s3 && s2 <= s4 && s2 <= s5 && s2 <= s6 )
        mn = s2, dfsans( idx , 1 , -1 , 1 );
    else if( s3 <= s4 && s3 <= s5 && s3 <= s6 )
        mn = s3, dfsans( idx , 2 , -1 , 1 );
    else if( s4 <= s5 && s4 <= s6 )
        mn = s4, dfsans( idx , 0 , -1 , -1 );
    else if( s5 <= s6 )
        mn = s5, dfsans( idx , 1 , -1 , -1 );
    else
        mn = s6, dfsans( idx , 2 , -1 , -1 );
    
    cout << mn << "\n";
    for( i64 i = 1; i <= N; i ++ )
        cout << cl[i] + 1 << " ";
    return 0;
}


/*

3 
10 1 10
10 10 1
1 10 10
1 2
2 3

*/