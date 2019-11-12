#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

#define dbg(a) cout << "-> " << __LINE__ << ": " << #a << " = " << a << endl

int main() {
    int T;
    scanf("%d", &T);
    for (int tt = 0; tt < T; tt++) {
        int n;
        scanf("%d", &n);
        string s, t;
        cin >> s >> t;
        vector<int> cnt(26, 0);
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        for (char c : t) {
            ++cnt[c - 'a'];
        }
        int f = 0;
        for (int v : cnt) {
            if (v & 1) {
                f = 1;
            }
        }
        if (f == 1) {
            puts("No");
            continue;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == t[i]) {
                        ans.push_back({j, j});
                        ans.push_back({i, j});
                        swap(s[j], t[j]);
                        swap(s[i], t[j]);
                        break;
                    }
                    else if (t[j] == t[i]) {
                        ans.push_back({i, j});
                        swap(s[i], t[j]);
                        break;
                    }
                }
            }
        }
        puts("Yes");
        printf("%d\n", (int) ans.size());
        for (auto v : ans) {
            printf("%d %d\n", v.first + 1, v.second + 1);
        }
    }
    return 0;
}
