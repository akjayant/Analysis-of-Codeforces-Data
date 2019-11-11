
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

#define X first
#define Y second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)
#define D(x) get<3>(x)

mt19937 gen(228);

#ifdef DEBUG
#define dbg(x) cout << "[dbg " << __LINE__ << "] " << x << endl
#else
#define dbg(x) ((void)0)
#endif

constexpr ll MOD = 1'000'000'007;

constexpr int N = 100005;

ll dp [N];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    if (s.find('m') != string::npos || s.find('w') != string::npos) {
        cout << "0\n";
        return 0;
    }

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'u' && s[i-1] == 'u') {
            dp[i+1] = (dp[i] + dp[i-1]) % MOD;
        } else if (s[i] == 'n' && s[i-1] == 'n') {
            dp[i+1] = (dp[i] + dp[i-1]) % MOD;
        } else {
            dp[i+1] = dp[i];
        }
    }

    cout << dp[s.size()] << "\n";

    return 0;
}
