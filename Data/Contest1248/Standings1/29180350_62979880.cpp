//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define sqr(a) (a * a)
#define ll long long
#define ull unsigned long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ch1 = 0, ch2 = 0, n1 = 0, n2 = 0;
    for (int i= 0; i < n; ++i) {
        int t;
        cin >> t;
        (t % 2 ? n1 : ch1)++;
    }
    int m;
    cin >> m;
    for (int i= 0; i < m; ++i) {
        int t;
        cin >> t;
        (t % 2 ? n2 : ch2)++;
    }
    cout << (ll)ch1 * ch2 + (ll)n1 * n2 << '\n';;
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