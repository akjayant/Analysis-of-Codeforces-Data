#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define x first
#define y second
#define pb push_back
#define len(x) (int) x.size();
#define all(a) a.begin(), a.end()

#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a) for (int i = 0; i < a.size(); ++i) cin >> a[i];
#define print(x, text) cout << text << " = " << x << endl;
#define printv(x, text) cout << text << " = "; for (auto e : x) cout << e << ' '; cout << endl;
#define printvp(x, text) cout << text << " =\n"; for (auto e : x) cout << e.first << ' ' << e.second << endl; cout << endl;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int main() {
    fast_io;

    string s;
    cin >> s;
    s = "0" + s;

    int n = s.size();
    ll mod = 1e9 + 7;

    bool fail = false;
    vector <ll> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'n' && i > 1 && s[i - 1] == 'n') {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        else if (s[i] == 'u' && i > 1 && s[i - 1] == 'u') {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        else {
            dp[i] = dp[i - 1];
            if (s[i] == 'm' || s[i] == 'w') fail = true;
        }
    }

    cout << dp[n - 1] * (1 - (int) fail) << endl;
}
