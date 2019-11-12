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
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            pos.pb(i);
        }
    }
    if (sz(pos) != 2) {
        cout << "No\n";
        return;
    }
    if (s[pos[0]] == s[pos[1]]) {
        swap(s[pos[0]], t[pos[1]]);
    }
    if (s == t) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

main() {
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
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
