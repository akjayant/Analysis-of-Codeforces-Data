#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;

vector<pii> ans;
string s, t;

void change(int i, int j) {
    ans.pb({i, j});
    int old = s[i];
    s[i] = t[j];
    t[j] = old;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cin >> s >> t;
        ans.clear();
        bool ok = 1;
        for (int i=0; i<n; i++) {
            if (s[i] == t[i]) continue;
            for (int j=i+1; j<n; j++) {
                if (s[j] == s[i]) {
                    change(j, i);
                    break;
                }
                if (t[j] == s[i]) {
                    change(j, j);
                    change(j, i);
                    break;
                }
            }
            if (s[i] == t[i]) continue;
            for (int j=i+1; j<n; j++) {
                if (s[j] == t[i]) {
                    change(j, j);
                    change(i, j);
                    break;
                }
                if (t[j] == t[i]) {
                    change(i, j);
                    break;
                }
            }
            if (s[i] == t[i]) continue;
            ok = 0;
            break;
        }
        if (!ok) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        cout << ans.size() << '\n';
        for (pii a : ans) cout << a.F + 1 << " " << a.S + 1 << "\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL
    return 0;
}
