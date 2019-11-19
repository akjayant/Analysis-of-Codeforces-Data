#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], b[N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[i];
    }
    int l = 0, r = 1000000000;
    while (l < r) {
        int mid = (l + r) / 2;
        long long mn = 1000000000000000000ll;
        for (int i = 1; i <= n; i++) {
            if (a[i] == a[i - 1]) continue;
            int idx = upper_bound(a + 1, a + 1 + n, a[i] + mid) - a;
            long long t = a[i] * (i - 1) - b[i - 1];
            if (idx != n + 1) {
                t += b[n] - b[idx - 1] - (a[i] + mid) * (n - idx + 1);
            }
            //if (r <= 100) cout << t << endl;
            mn = min(mn, t);
        }
        for (int i = n; i >= 1; i--) {
            if (a[i] == a[i + 1]) continue;
            int idx = lower_bound(a + 1, a + 1 + n, a[i] - mid) - a - 1;
            long long t = b[n] - b[i] - a[i] * (n - i);
            if (idx != 0) {
                t += (a[i] - mid) * idx - b[idx];
            }
            //if (r <= 100) cout << t << endl;
            mn = min(mn, t);
        }
        if (mn <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
        //cout << "L R " << l << ' ' << r << endl;
    }
    cout << l;
}