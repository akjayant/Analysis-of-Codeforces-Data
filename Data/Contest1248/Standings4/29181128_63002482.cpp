#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define mod 1000000007
 
LL a[300100];
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    a[1] = 1;
    a[2] = 2;
    for(int i = 3; i < 100010 ; i++ ) {
        a[i] = (a[i - 1] + a[i - 2])%mod;
    }
    int q = 1;
   // cin >> q;
    while( q-- ) {
        LL n, m ;
        cin >> n >> m;
        LL ans = ( -1ll + mod ) % mod;
        ans = ( ( (a[n] + a[m]) % mod ) + ans ) % mod;
        ans = ( ans * 2ll ) % mod;
        cout << ans;
    }
    return 0;
}