using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int n;
string s;
ll dp[100005];

ll solve(int pos) {
    if (pos == n) return 1LL;
    ll &ret = dp[pos];
    if (ret != -1) return ret;

    ret = (1LL * solve(pos + 1)) % MOD;

    if (pos + 2 <= n && s[pos] == 'n' && s[pos + 1] == 'n') {
        ll next = (1LL * solve(pos + 2)) % MOD;
        ret = (ret + next) % MOD;
    }

    if (pos + 2 <= n && s[pos] == 'u' && s[pos + 1] == 'u') {
        ll next = (1LL * solve(pos + 2)) % MOD;
        ret = (ret + next) % MOD;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = (int)s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << "0\n";
            return 0;
        }
    }
    memset(dp, -1, sizeof dp);
    ll ans = solve(0);
    cout << ans << "\n";
    return 0;
}
