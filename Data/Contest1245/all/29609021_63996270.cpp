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
    int a, b;
    cin >> a >> b;
    cout << (gcd(a, b) == 1 ? "Finite\n" : "Infinite\n");
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