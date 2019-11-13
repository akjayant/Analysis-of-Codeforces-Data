// 17:31

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

#define ON

#ifdef ON
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif


template<typename T = int>
T input() {
    T res;
    cin >> res;
    return res;
}

template<typename It>
void input_seq(It begin, It end, istream &in = cin) {
    generate(begin, end, input<typename remove_reference<decltype(*begin)>::type>);
}

template<class It>
void output(It begin, It end, ostream &out = cerr) {
    while (begin != end) {
        out << *(begin++) << ' ';
    }
    out << endl;
}

#define int ll
constexpr int MOD = 1e9 + 7;


signed main() {
#ifdef ON
//    freopen("../in.txt", "r", stdin);
//    freopen("../out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto str = input<string>();
    int n = sz(str);
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        if (i && str[i] == str[i - 1] && str[i] == 'u') {
            dp[i + 1] += dp[i - 1];
        }
        if (i && str[i] == str[i - 1] && str[i] == 'n') {
            dp[i + 1] += dp[i - 1];
        }
        if (str[i] == 'w' || str[i] == 'm') {
            dp[i + 1] = 0;
        }
        dp[i + 1] %= MOD;
    }
    cout << dp[n] << endl;
}
