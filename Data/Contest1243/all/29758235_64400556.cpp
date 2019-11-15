#include<bits/stdc++.h>

//#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(v) (int) v.size()

using namespace std;

int n;
string s, t;

void solve() {
    cin >> n >> s >> t;
    vector<pair<int, int>> answ;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) continue;
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                swap(s[j], t[i]);
                answ.pb({j + 1, i + 1});
                break;
            }
            if (t[i] == t[j]) {
                swap(s[i], t[j]);
                answ.pb({i + 1, j + 1});
                break;
            }
            if (s[i] == t[j]) {
                swap(s[j], t[j]);
                swap(s[j], t[i]);
                answ.pb({j + 1, j + 1});
                answ.pb({j + 1, i + 1});
                break;
            }
            if (t[i] == s[j]) {
                swap(s[j], t[j]);
                swap(s[i], t[j]);
                answ.pb({j + 1, j + 1});
                answ.pb({i + 1, j + 1});
                break;
            }
        }
        if (s[i] != t[i]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n" << sz(answ) << "\n";
    for (pair<int, int> &p : answ) {
        cout << p.X << " " << p.Y << "\n";
    }
}

main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
