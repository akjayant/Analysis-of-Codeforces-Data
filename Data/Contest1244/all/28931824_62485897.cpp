#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int tl = 0, tr = n - 1;
    while (tl < n - 1 && a[tl + 1] == a[tl])
        ++tl;
    while (tr > 0 && a[tr - 1] == a[tr])
        --tr;
    while (tl < tr) {
        int nl = tl + 1, nr = n - tr;
        if (nl > k && nr > k)
            break;
        if (nl < nr) {
            if ((a[tl + 1] - a[tl]) * nl > k) {
                cout << a[tr] - a[tl] - k / nl << endl;
                return 0;
            }
            k -= (a[tl + 1] - a[tl]) * nl;
            ++tl;
            while (tl < tr && a[tl] == a[tl + 1])
                ++tl;
        }
        else {
            if ((a[tr] - a[tr - 1]) * nr > k) {
                cout << a[tr] - a[tl] - k / nr << endl;
                return 0;
            }
            k -= (a[tr] - a[tr - 1]) * nr;
            --tr;
            while (tl < tr && a[tr] == a[tr - 1])
                --tr;
        }
    }
    cout << a[tr] - a[tl] << endl;
    return 0;
}
