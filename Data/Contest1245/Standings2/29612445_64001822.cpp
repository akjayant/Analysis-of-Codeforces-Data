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

    int t;
    cin >> t;

    while(t--) {
        int n, r, p, s;
        cin >> n >> r >> p >> s;

        string t;
        cin >> t;

        int win = 0;
        string res;
        for(int i = 0; i < t.size(); ++i) {
            if(t[i] == 'R') {
                if(p > 0) {
                    win++; p--;
                    res += "P";
                }

                else {
                    res += "A";
                }
            }

            if(t[i] == 'P') {
                if(s > 0) {
                    win++; s--;
                    res += "S";
                }

                else {
                    res += "A";
                }
            }

            if(t[i] == 'S') {
                if(r > 0) {
                    win++; r--;
                    res += "R";
                }

                else {
                    res += "A";
                }
            }
        }

        for(int i = 0; i < res.size(); ++i) {
            if(res[i] != 'A') continue;
            if(r > 0) {
                res[i] = 'R';
                r--;
                continue;
            }

            if(p > 0) {
                res[i] = 'P';
                p--;
                continue;
            }

            if(s > 0) {
                res[i] = 'S';
                s--;
                continue;
            }
        }

        if(win >= (n+1)/2) {
            cout << "YES\n";
            cout << res << "\n";
        }

        else {
            cout << "NO\n";
        }
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
