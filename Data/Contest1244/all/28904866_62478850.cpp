#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n;
ll k, mn = LLONG_MAX, a[maxn], b[maxn], suf[maxn], pre[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        ll t = a[i] * i - pre[i];
        if (t <= k) {
            int l = a[i], r = a[n], ans;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int tmp = lower_bound(a + 1, a + n + 1, mid) - a;
                ll num = suf[tmp] - a[tmp] * (n - tmp + 1) + 1LL * (n - tmp + 1) * (a[tmp] - mid);
                if (num + t <= k) r = (ans = mid) - 1;
                else l = mid + 1;
            }
            mn = min(mn, ans - a[i]);
        }
        t = suf[i] - 1LL * a[i] * (n - i + 1);
        if (t <= k) {
            int l = a[1], r = a[i], ans;
            while (l <= r) {
                int mid = (l + r) >> 1;
                int tmp = upper_bound(a + 1, a + n + 1, mid) - a - 1;
                ll num = a[tmp] * tmp - pre[tmp] + 1LL * tmp * (mid - a[tmp]);
                if (num + t <= k) l = (ans = mid) + 1;
                else r = mid - 1;
            }
            mn = min(mn, a[i] - ans);
        }
    }
    cout << mn << endl;
    return 0;
}