#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define int long long

const int INF = 1e18;

using namespace std;

vector<pair<int, int>> ans;

void gen(int l, string &a, string &b) {
    if (l == (int)a.size()) {
        return;
    }
    if (a[l] == b[l]) {
        gen(l + 1, a, b);
        return;
    }
    for (int i = l + 1; i < a.size(); i++) {
        if (a[i] == b[l]) {
            swap(a[i], b[i]);
            //cout << a[i] << ' ' << b[i];
            ans.push_back({i + 1, i + 1});
            swap(a[l], b[i]);
            ans.push_back({l + 1, i + 1});
            break;
        }
        if (i == a.size() - 1) {
            for (int j = l + 1; j < a.size(); j++) {
                if (b[j] == b[l]) {
                    swap(b[j], a[l]);
                    ans.push_back({l + 1, j + 1});
                    gen(l + 1, a, b);
                    return;
                }
            }
        }
    }
    gen(l + 1, a, b);
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ans.clear();
    gen(0, s, t);
    //cout << s << ' ' << t << ans.size();
    if (s == t) {
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (auto to : ans) {
            cout << to.first << ' ' << to.second << '\n';
        }
    } else {
        cout << "NO\n";
    }
}

int32_t main() {
#ifdef local
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    while (q --) solve();
    return 0;
}