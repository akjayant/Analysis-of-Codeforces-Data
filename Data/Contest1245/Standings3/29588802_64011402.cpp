#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define sync ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
#define fr(x, n) for (int x = 0; x < n; x++)
#define int long long
#define pb push_back
#define y1 fadasdsadassa
#define random mt19937 rng(time(nullptr));

using namespace std;

const double eps = 1e-9;
const double EPS = 1e-17; 
const int M = 1e5 + 1;
const int INF = 1e17 + 7;
const int MOD = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e5 + 1;

int n, m;
vector <int> v;

int ppow(int x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return ppow(x, n / 2) * ppow(x, n / 2) % MOD;
    }
    return ppow(x, n - 1) * x % MOD; 
}

int dp[N];

signed main () { sync;
    string s;
    cin >> s;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= s.size(); i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    for (auto it : s) 
        if (it == 'w' || it == 'm') return cout << 0, 0;
    n = (int)s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'u') {
            v.push_back(1);
        }
        else if (s[i] == 'n') {
            v.push_back(2);
        }
        else {
            v.push_back(0);
        }
    }
    int ans = 1;
    int cnt = 1;
    v.push_back(-1);
    for (int i = 1; i <= n; i++) {
        if (v[i] != v[i - 1]) {
            if (v[i - 1] > 0) {
                ans *= dp[cnt];
                ans %= MOD;
            }
            cnt = 0;
        }
        cnt++;
    }
    cout << ans << '\n';
}
