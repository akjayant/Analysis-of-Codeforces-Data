#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int k;
    cin >> k;
    for (int e = 0; e < k; e++) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> cnt(30);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']++;
        }
        bool f = true;
        for (int i : cnt) {
            if (i % 2 != 0) {
                f = false;
                break;
            }
        }
        if (!f) {
            cout << "No" << "\n";
            continue;
        }
        int kol = 0;
        vector<pii> res;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) {
                continue;
            }
            bool flag = false;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == s[i]) {
                    kol++;
                    res.push_back({j, i});
                    s[j] = t[i];
                    t[i] = s[i];
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                for (int j = i + 1; j < n; j++) {
                    if (t[j] == s[i]) {
                        kol += 2;
                        res.push_back({j, j});
                        t[j] = s[j];
                        s[j] = t[i];
                        res.push_back({j, i});
                        flag = true;
                        break;
                    }
                }
            }
        }
        cout << "Yes" << "\n";
        cout << kol << "\n";
        for (pii i : res) {
            cout << i.first + 1 << " " << i.second + 1 << "\n";
        }
    }


    return 0;
}

