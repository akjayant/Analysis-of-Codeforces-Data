#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <bitset>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>

using namespace std;
using namespace __gnu_pbds;



void solve();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    solve();
    return 0;
}

#define int long long

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int t, n, a[1001], ans;

void solve() {
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        cin >> n;
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        reverse(a, a + n);
        for (int i = 0; i < n; i++) {
            if (a[i] >= i + 1) ans = i + 1;
        }
        cout << ans << '\n';
    }
}
