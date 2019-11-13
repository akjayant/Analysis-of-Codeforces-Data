#include <bits/stdc++.h>

typedef long long ll;
typedef double ld;
typedef unsigned short ush;
typedef short shrt;
using namespace std;

const static int MAX_N = 5e5 + 7, INF = 1e9 + 7;
const static ld PI = acos(-1), eps = 1e-9;

inline void prc();
signed main() {
    prc();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        int first = -1, second = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (first == -1) first = i;
                else second = i;
            }
        }
        bool is_ok = 1;
        if (first == -1) {
            is_ok = 0;
            vector<int> cnt(26);
            for (int i = 0; i < n; i++) {
                cnt[s1[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > 1) {
                    is_ok = 1;
                    break;
                }
            }
        }

        if (first != -1 && second != -1) {
            swap(s1[first], s2[second]);
        }
        if (is_ok && s1 == s2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }


    return 0;
}

inline void prc() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}