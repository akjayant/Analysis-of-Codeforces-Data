#include <bits/stdc++.h>

typedef long long ll;
typedef double ld;
typedef unsigned short ush;
typedef short shrt;
using namespace std;

//#define int long long

const static int MAX_N = 5e5 + 7, INF = 1e9 + 7;
const static ld PI = acos(-1), eps = 1e-9;

inline void prc();
signed main() {
    prc();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s1, s2; cin >> s1 >> s2;
        vector<pair<int, int>> ans;
        int can_do = 1;
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) continue;
            if (i == n - 1) {
                can_do = 0;
                break;
            }
            int fine = 0;
            for (int j = i + 1; !fine && j < n; j++) {
                if (s2[j] == s2[i]) {
                    swap(s1[i], s2[j]);
                    ans.emplace_back(i, j);
                    fine = 1;
                }
            }
            for (int j = i + 1; !fine && j < n; j++) {
                if (s1[j] == s2[i]) {
                    swap(s1[j], s2[i + 1]);
                    swap(s1[i], s2[i + 1]);
                    ans.emplace_back(j, i + 1);
                    ans.emplace_back(i, i + 1);
                    fine = 1;
                }
            }
            if (!fine) {
                can_do = 0;
                break;
            }
        }
        if (can_do) {
            cout << "Yes\n";
            cout << ans.size() << "\n";
            for (auto p : ans) {
                cout << p.first + 1 << " "<< p.second + 1 << "\n";
            }
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