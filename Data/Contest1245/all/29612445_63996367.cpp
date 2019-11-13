#include <bits/stdc++.h>
#define int long long
typedef long double ld;
using namespace std;
//#pragma GCC optimize("O3")

const int inf = 1e18;
const int mod = 1e9+7;
const ld eps = 1e-9;
const ld pi = atan2(0, -1);

///---Some Code---///

int32_t main() {
//    freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    cout << fixed << setprecision(5);
//    srand(time(0));
    ///---------///

    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;

        int c = __gcd(a, b);

        if(c == 1)
            cout << "Finite";
        else
            cout << "Infinite";
        cout << "\n";
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
