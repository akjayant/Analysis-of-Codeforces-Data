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
        int n;
        cin >> n;

        string s;
        cin >> s;

        int first = -1, last = -1;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') {
                if(first == -1) first = i;
                last = i;
            }
        }

        int res = n;
        if(first != -1) {
//            cout << first << " " << last << "\n";
            res = max(res, max((n-first)*2, (last+1)*2));
        }

//        cerr << "RES:";
        cout << res << "\n";
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
