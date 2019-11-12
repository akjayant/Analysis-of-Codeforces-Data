/** Simplicity is the final achievement **/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+55;
const long long MD = 1e9+7;

long long T, n, m;

long long arr[N];

int32_t main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    /** ONLY FOOLS RUSH IN **/

    cin >> T;

    while (T--) {
        string s, t;
        cin >> n >> s >> t;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (s[i] == s[j] && s[j] != t[j]) {
                        ans.push_back({j+1, i+1});
                        swap(s[j], t[i]);
                        break;
                    }
                }
            }
            if (s[i] != t[i]) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (t[i] == t[j] && s[j] != t[j]) {
                        ans.push_back({i+1, j+1});
                        swap(s[i], t[j]);
                        break;
                    }
                }
            }
            if (s[i] != t[i]) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (s[j] != t[j] && s[i] == t[j]) {
                        ans.push_back({j+1, j+1});
                        swap(s[j], t[j]);
                        ans.push_back({j+1, i+1});
                        swap(s[j], t[i]);
                        break;
                    }
                    if (s[j] != t[j] && t[i] == s[j]) {
                        ans.push_back({j+1, j+1});
                        swap(s[j], t[j]);
                        ans.push_back({i+1, j+1});
                        swap(s[i], t[j]);
                        break;
                    }
                }
            }
        }
        if (s == t) {
            cout << "Yes\n" << ans.size() << endl;
            for (auto x : ans) cout << x.first << " " << x.second << "\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
