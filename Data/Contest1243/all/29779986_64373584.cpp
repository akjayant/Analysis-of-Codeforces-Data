#include <bits/stdc++.h>
#define int unsigned int
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
//    cout << fixed << setprecision(15);
//    srand(time(0));
    ///---------///

    int k;
    cin >> k;

    while(k--) {
        int n;
        cin >> n;

        vector<int> a(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        int res = 1;
        for(int cur = 1; cur <= n; ++cur) {
            int cnt = 0;
            for(int i : a)
                if(i >= cur) cnt++;
            if(cnt < cur) continue;
            res = cur;
        }

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
