#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define ld long double
#define ll long long
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define endl '\n'

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
const ll MOD = 1e9 + 7;
const int rx[4] = {-1, 0, 1, 0};
const int ry[4] = {0, 1, 0, -1};
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int hx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
const int hy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const ld eps = 1e-7;
const double pi = acos(-1.0);
const int INF = 2e9;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    string t;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'n' && i && s[i - 1] == s[i]) t += s[i];
        else if (s[i] == 'n' && t.size() > 0 && t.back() == s[i]) {
            t += "u";
            t += s[i];
        } else if (s[i] == 'n') t += s[i];
        else if (s[i] == 'u' && i && s[i - 1] == s[i]) t += s[i];
        else if (s[i] == 'u' && t.size() > 0 && t.back() == s[i]) {
            t += "n";
            t += s[i];
        } else if (s[i] == 'u') t += s[i];
        else if (s[i] == 'm') {
            cout << "0" << endl;
            return 0;
        } else if (s[i] == 'w') {
            cout << "0" << endl;
            return 0;
        }
    }
    int n = t.size();
    if (n < 2) {
        cout << "1" << endl;
        return 0;
    }
    ll dp[n];
    dp[0] = 1;
    if (t[1] == t[0]) dp[1] = 2;
    else dp[1] = 1;
    for (int i = 2; i < n; i++) {
        if (t[i] == t[i - 1]) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= MOD;
        } else {
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}

