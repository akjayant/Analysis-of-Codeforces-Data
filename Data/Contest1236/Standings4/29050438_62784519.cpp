//  Copyright © 2019 Diego Garcia Rodriguez del Campo. All rights reserved.
#include<bits/stdc++.h>
#define MAX 200005
#define optimiza_io cin.tie(0); ios_base::sync_with_stdio(0);
using namespace std;
typedef long long i64;

int T, a, b, c, ans;

int main()
{
    optimiza_io
    cin >> T;
    while( T -- ) {
        cin >> a >> b >> c;
        ans = 0;
        while( b > 0 && c > 1 ) {
            b--;
            c -= 2;
            ans += 3;
            
        }
        while( a > 0 && b > 1 ) {
            a--;
            b -= 2;
            ans += 3;
            
        }
        cout << ans << "\n";
    }
    return 0;
}