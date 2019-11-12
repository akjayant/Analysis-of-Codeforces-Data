#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define int long long

const int INF = 1e18;

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string a = "", b = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            a += s[i];
            b += t[i];
        }
    }
    if (a == "" || a.size() == 2 && a[0] == a[1] && b[0] == b[1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    };
}

int32_t main() {
#ifdef local
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q;
    cin >> q;
    while (q --) solve();
    return 0;
}