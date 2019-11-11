#include <bits/stdc++.h>
#define f first
#define s second
#define push push_back
#define pop pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 1e5 + 228, MAXK = 1e6 + 1, INF = 1e9, M = 1e9 + 7;

// mt19937 rnd(0);

ll pw(int cnt) {
    ll ans = 1;
    for (int i = 0; i < cnt; ++i) {
        ans = (ans * 2) % M;
    }
    return ans;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    if (s[0] == 'm' || s[0] == 'w') {
        return cout << 0, 0;
    }
    vector <ll> dp(s.size() + 1);
    dp[0] = dp[1] = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == 'm' || s[i] == 'w') {
            return cout << 0, 0;
        }
        dp[i + 1] = dp[i];
        if (s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u')) {
            dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
        }
    }
    cout << dp[s.size()];
	return 0;
}
