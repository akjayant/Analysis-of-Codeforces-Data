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
#define show(x) cout << "[debug " << __LINE__ << "] " << #x << " = " << x << endl
#define shows() cout << "=========================" << endl
#define debug cout << "[debug_scope " << __LINE__ << "]" << endl;
#else
#define show(x) ((void)0)
#define shows() ((void)0)
#define debug if (false)
#endif

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> diff;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            diff.pb(i);
        }
    }

    vector<pair<int, int>> indices[128];
    for (int d : diff) {
        indices[s[d]].pb({0, d});
        indices[t[d]].pb({1, d});
    }

    /*for (int i = 0; i < 128; i++) {
        if (indices[i].size() % 2 != 0) {
            cout << "No\n";
            return;
        }
    }*/

    vector<pii> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) continue;
        bool ok = false;
        for (int j = i+1; j < n; j++) {
            if (s[j] == s[i]) {
                ans.pb({j, i});
                swap(s[j], t[i]);
                ok = true;
                break;
            }
        }
        if (ok) continue;
        for (int j = i+1; j < n; j++) {
            if (t[j] == s[i]) {
                swap(s[j], t[j]);
                swap(s[j], t[i]);
                ans.pb({j, j});
                ans.pb({j, i});
                ok = true;
                break;
            }
        }
        if (ok) continue;
        if (!ok) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    assert(ans.size() <= 2*n);
    cout << ans.size() << "\n";
    for (auto [a, b] : ans) {
        cout << a + 1 << " " << b + 1 << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
