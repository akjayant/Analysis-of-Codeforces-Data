#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
 
void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    // cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
int arr[305][305];
void solve() {
    int n;
    cin >> n;
    int cur = 0;
    for (int j = 1; j <= n; j += 1) {
        if (j & 1) {
            for (int i = 1; i <= n; i += 1) {
                arr[i][j] = ++cur;
            }
        }
        else {
            for (int i = n; i >= 1; i -= 1) {
                arr[i][j] = ++cur;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}       
/*
1 6 7

2 5 8

3 4 9
*/