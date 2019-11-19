//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

int T, x, y, a, b, c, d, k;

int main()
{
    optimiza_io
    cin >> T;
    while( T -- ) {
        cin >> a >> b >> c >> d >> k;
        int x = ceil( ( double ) a / ( double ) c );
        int y = ceil( ( double ) b / ( double ) d );
        if( x + y > k )
            cout << "-1\n";
        else
            cout << x << " " << y << "\n";
    }
    return 0;
}