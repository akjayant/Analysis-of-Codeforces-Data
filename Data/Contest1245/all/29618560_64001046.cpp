#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t; cin >> t;
    while (t--) {
        int n, a, b, c; cin >> n >> a >> b >> c;
        string s; cin >> s;
        string res;
        int beat = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            char ch = s[i];
            beat++;
            if (ch == 'R' && b != 0)
                res.push_back('P'), b--;
            else if (ch == 'P' && c != 0)
                res.push_back('S'), c--;
            else if (ch == 'S' && a != 0)
                res.push_back('R'), a--;
            else
                res.push_back('?'), beat--;
        }
        for (int i = 0; i < (int)res.size(); ++i) {
            if (res[i] != '?')
                continue;
            if (a)
                res[i] = 'R', a--;
            else if (b)
                res[i] = 'P', b--;
            else
                res[i] = 'S';
        }

        if (beat >= n/2 + n%2)
            cout << "YES\n" << res << '\n';
        else
            cout << "NO\n";
    }
}

int main() {
    #ifdef LOCAL
        freopen("date.in", "r", stdin);
    #endif
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}