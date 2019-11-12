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
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        sort(a.rbegin(), a.rend());
        int opt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= i + 1) {
                opt = max(opt, i + 1);
            }
        }
        cout << opt << "\n";
    }


    return 0;
}

inline void prc() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}