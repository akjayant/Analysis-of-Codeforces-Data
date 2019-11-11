#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
typedef long long int ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<ll> arr;

    string s;
    cin >> s;
    int n = 0, u = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'n') {
            ++n;
            if (u > 0) {
                arr.push_back(u);
                u = 0;
            }
        } else if (s[i] == 'u') {
            ++u;
            if (n > 0) {
                arr.push_back(n);
                n = 0;
            }
        } else if (s[i] == 'm'){
            cout << 0;
            return 0;
        } else if (s[i] == 'w') {
            cout << 0;
            return 0;
        } else {
            if (u > 0) {
                arr.push_back(u);
                u = 0;
            }
            if (n > 0) {
                arr.push_back(n);
                n = 0;
            }
        }
    }
    if (u > 0) {
        arr.push_back(u);
        u = 0;
    }
    if (n > 0) {
        arr.push_back(n);
        n = 0;
    }
    vector<ll> dp;
    dp.push_back(1);
    dp.push_back(1);
    for (int i = 2; i <= s.length(); ++i) {
        dp.push_back((dp[i - 2] + dp[i - 1]) % MOD);
    }
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = dp[arr[i]];
    }
    ll res = 1;
    for (int i = 0; i < arr.size(); ++i) {
        res = (res * arr[i]) % MOD;
    }
    cout << res;
    return 0;
}
