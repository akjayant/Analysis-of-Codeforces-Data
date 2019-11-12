#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int inf = 1e9 + 7;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int y = 0; y < t; ++y) {
        int n;
        cin >> n;
        string s;
        string t;
        cin >> s;
        cin >> t;
        int cnt[26];
        for (int i = 0; i < 26; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']++;
        }
        bool ok = true;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 != 0) {
                ok = false;
                cout << "No" << endl;
                break;
            }
        }
        if (!ok) continue;
        vector<pair<int, int>> answer;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) continue;
            bool done = false;
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == s[i]) {
                    answer.push_back({j + 1, i + 1});
                    swap(s[j], t[i]);
                    done = true;
                    break;
                }
            }
            if (!done) {
                for (int j = i + 1; j < n; ++j) {
                    if (s[i] == t[j]) {
                        answer.push_back({i + 2, j + 1});
                        swap(s[i + 1], t[j]);
                        answer.push_back({i + 2, i + 1});
                        swap(s[i + 1], t[i]);
                        done = true;
                        break;
                    }
                }
            }
        }
        cout << "Yes" << endl;
        cout << answer.size() << endl;
        for (int i = 0; i < answer.size(); ++i) {
            cout << answer[i].first << ' ' << answer[i].second << endl;
        }
    }
    return 0;
}