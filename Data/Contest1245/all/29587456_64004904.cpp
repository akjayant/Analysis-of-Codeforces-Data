#include <bits/stdc++.h>

#define y1 theboatman
#define make_struct(args...) {args}

using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;

const int mod = 1e9 + 7;

int add(int a, int b) {
    return (1LL * a + b) % mod;
}

void solve() {
    string s;
    cin >> s;

    s = s + '#';
    vector <int> dp(s.size());
    dp[0] = 1;
    for(int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1] || (s[i] != 'w' && s[i] != 'm'))
            dp[i + 1] = add(dp[i + 1], dp[i]);

        if (s[i] == s[i + 1] && (s[i] == 'u' || s[i] == 'n')) {
            dp[i + 2] = add(dp[i + 2], dp[i]);
        }
    }

    cout << dp[s.size() - 1] << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int test;
    //cin >> test;
    test = 1;
    while(test--) {
        solve();
    }

    return 0;
}
/*
*/
