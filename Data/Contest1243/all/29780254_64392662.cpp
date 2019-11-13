#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

vector<pii> ans;

void solve() {
    ans.clear();

    int n; cin >> n;

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            bool found = false;
            for (int j = i+1; j < n; j++) {
                if (s[j] == s[i]) {
                    ans.push_back(mp(j, i));
                    swap(s[j], t[i]);
                    found = true;
                    break;
                }
            }
            if (found) continue;
            for (int j = i+1; j < n; j++) {
                if (t[j] == s[i]) {
                    ans.push_back(mp(n-1, j));
                    ans.push_back(mp(n-1, i));
                    swap(s[n-1], t[j]);
                    swap(s[n-1], t[i]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n" << ans.size() << "\n";
    for (pii tmp : ans) {
        cout << tmp.fi+1 << " " << tmp.se+1 << "\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int qt; cin >> qt;
    for (int q = 0; q < qt; q++) {
        solve();
    }
}
