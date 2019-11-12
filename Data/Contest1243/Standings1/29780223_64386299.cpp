#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    for (int _ = 0; _ < k; ++_) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> cnt(26);
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
            ++cnt[t[i] - 'a'];
        }
        bool found = false;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 == 1) {
                found = true;
            }
        }
        if (found) {
            cout << "No\n";
            continue;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < s.size(); ++i) {
            char cur = s[i];
            if (t[i] != cur) {
                bool f = false;
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == cur) {
                        swap(s[j], t[i]);
                        ans.push_back(make_pair(j, i));
                        f = true;
                        break;
                    }
                }
                for (int j = i + 1; j < n && !f; ++j) {
                    if (t[j] == cur) {
                        swap(s[n - 1], t[j]);
                        swap(s[n - 1], t[i]);
                        ans.push_back(make_pair(n - 1, j));
                        ans.push_back(make_pair(n - 1, i));
                        f = true;
                        break;
                    }
                }
            }
        }
        cout << "Yes\n";
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
        }
    }
    return 0;
}