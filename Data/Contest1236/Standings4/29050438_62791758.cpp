//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

int N, idx;
bool f;
vector < int > ans[MAX];

int main()
{
    optimiza_io
    cin >> N;
    for( int i = 1; i <= N; i ++ ) {
        if( ! f ) {
            for( int j = 1; j <= N; j ++ ) 
                ans[j].push_back( ++idx );
        }
        else {
            for( int j = N; j >= 1; j -- ) 
                ans[j].push_back( ++idx );
        }
        f = ! f;
    }
    
    for( int i = 1; i <= N; i ++ ) {
        for( auto v : ans[i] )
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}