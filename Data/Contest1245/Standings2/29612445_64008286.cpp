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

    string s;
    cin >> s;

    for(char c : s) {
        if(c == 'm' || c == 'w') {
            cout << 0 << "\n";
            exit(0);
        }
    }

    int n = s.size() + 42;
    vector<int> dp(n, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < n; ++i)
        dp[i] = (dp[i-2] + dp[i-1]) % mod;

    vector<pair<char, int>> a;
    for(int i = 0; i < s.size(); ++i) {
        if(i == 0 || s[i] != a[a.size()-1].first) {
            a.push_back({s[i], 1});
        }
        else {
            a[a.size()-1].second++;
        }
    }

    int res = 1;
    for(auto p : a) {
        if(p.first != 'n' && p.first != 'u') continue;
        res = (res * dp[p.second]) % mod;
    }

    cout << res << "\n";

    ///---------///
    return 0;
}

/**

///---------///

///---------///

///---------///

///---------///

*/
