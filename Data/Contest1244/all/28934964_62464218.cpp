#include <bits/stdc++.h>
#define int long long
typedef long double ld;
using namespace std;
//#pragma GCC optimize("O3")

const int inf = 1e18;
const int mod = 1e9+7;
const ld eps = 1e-8;
const ld pi = atan2(0, -1);

///---Some Code---///


int32_t main() {
//    freopen("sum.in", "r", stdin); freopen("sum.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << fixed << setprecision(15);
//    srand(time(0));
    ///---------///

    int t;
    cin >> t;

    while(t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int x = (a+c-1)/c;
        int y = (b+d-1)/d;

        if(x + y <= k)
            cout << x << " " << y << "\n";
        else
            cout << -1 << "\n";
    }

    ///---------///
    return 0;
}

/**

///---------///

///---------///

///---------///

///---------///

*/
