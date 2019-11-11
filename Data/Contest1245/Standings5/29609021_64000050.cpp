/*
................
....@@@@@@@.....
...@.......@....
..@...@.....@...
.@....@@.....@..
@.....@.@.....@.
@@@@@@@@@@@@@@@@
.@....@...@...@.
..@...@....@..@.
...@..@.....@@..
....@@@@@@@@....
................
*/

//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
#define X first
#define Y second
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ll long long
//#define int long long

int gcd(int a, int b) {
    if (!b)
        return a;
    return gcd(b, a % b);
}

signed solve() {
    
    int n, R, P, S;
    cin >> n >> R >> P >> S;

    string s;
    cin >> s;

    string ans(s.size(), '#');
    int cnt = 0;

    forn (i, n) {
        if (s[i] == 'R' && P) {
            --P;
            ans[i] = 'P';
            ++cnt;
        }
        else if (s[i] == 'S' && R) {
            --R;
            ans[i] = 'R';
            ++cnt;
        }
        else if (s[i] == 'P' && S) {
            --S;
            ans[i] = 'S';
            ++cnt;
        }
    }

    forn (i, n) {
        if (ans[i] != '#')
            continue;
        if (R) {
            ans[i] = 'R';
            --R;
        }
        else if (S) {
            ans[i] = 'S';
            --S;
        }
        else {
            ans[i] = 'P';
            --P;
        }
    }

    if (cnt < (n + 1) / 2) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    cout << ans << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}