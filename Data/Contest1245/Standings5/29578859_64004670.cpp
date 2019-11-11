#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rnd;
#define F first
#define S second
#define pb push_back

const ll mod = 1e9 + 7;
ll f[100010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    s = '*' + s;
    for (int i=1; i<=n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << "0\n";
            return 0;
        }
    }
    vector<ll> a;
    for (int i=1; i<=n; i++) {
        if (s[i] == 'n') cnt++;
        else {
            if (cnt) a.pb(cnt);
            cnt = 0;
        }
    }
    if (cnt) a.pb(cnt);
    cnt = 0;
    for (int i=1; i<=n; i++) {
        if (s[i] == 'u') cnt++;
        else {
            if (cnt) a.pb(cnt);
            cnt = 0;
        }
    }
    if (cnt) a.pb(cnt);
    cnt = 0;

    f[0] = 1;
    f[1] = 1;
    for (int i=2; i<=n; i++) {
        f[i] = (f[i-1] + f[i-2]) % mod;
    }

    ll ans = 1;
    for (int i=0; i<a.size(); i++) {
        ans = (ans * f[a[i]]) % mod;
    }
    cout << ans << "\n";

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL
    return 0;
}
