#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1010;
int a[MAXN];

int main() {
//     freopen("negcycle.in", "r", stdin);
//     freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector<pair<int, int>> res;
        string ans = "Yes";
        for (int i = 0; i < s1.size(); ++i) {
            bool ok = 0;
            if (s1[i] == s2[i]) {
                continue;
            }
            for (int j = i; j < s2.size(); ++j) {
                if (s1[i] == s2[j]) {
                    res.push_back({j, j});
                    res.push_back({j, i});
                    swap(s1[j], s2[j]);
                    swap(s1[j], s2[i]);
                    ok = 1;
                    break;
                }
            }
            if (!ok) {
                for (int j = i + 1; j < s1.size(); ++j) {
                    if (s1[i] == s1[j]) {
                        res.push_back({j, i});
                        swap(s1[j], s2[i]);
                        ok = 1;
                        break;
                    }
                }
            }
            if (!ok) {
                ans = "No";
            }
        }
        cout << ans << endl;
        if (ans == "Yes") {
            cout << res.size() << endl;
            for (auto r : res) {
                cout << r.first + 1 << " " << r.second + 1 << endl;
            }
        }
    }
}