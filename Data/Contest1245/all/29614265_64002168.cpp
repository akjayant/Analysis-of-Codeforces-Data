#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

void lol_anton() {
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int ans = 0;
        vector<char> claim(n);
        for (int i = 0; i < n; i++) {
            char v;
            cin >> v;
            if (v == 'R') {
                if (b) b--, ans++, claim[i] = 'P';
            }
            if (v == 'P') {
                if (c) c--, ans++, claim[i] = 'S';
            }
            if (v == 'S') {
                if (a) a--, ans++, claim[i] = 'R';
            }
        }
        for (int i = 0; i < n; i++) {
            if (!claim[i]) {
                if (a) claim[i] = 'R', a--;
                else if (b) claim[i] = 'P', b--;
                else if (c) claim[i] = 'S', c--;
            }
        }
        if (ans < (n + 1) / 2) cout << "NO";
        else {
            cout << "YES\n";
            for (auto x : claim) cout << x;
        }
        cout << '\n';
    }
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lol_anton();
}