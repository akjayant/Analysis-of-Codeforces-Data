#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;
const int MAXN = 1e5 + 7;


main() {
    cout.precision(20);
    int n;
    long long k;
    cin >> n >> k;
    int a[MAXN];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    long long d1[MAXN];
    long long d2[MAXN];
    long long cur = 0;
    d1[0] = 0;
    for (int i = 1; i < n; ++i) {
        cur += (long long)i * (a[i] - a[i - 1]);
        d1[i] = cur;
    }
    d2[n - 1] = 0;
    cur = 0;
    for (int i = n - 2; i >= 0; --i) {
        cur += (long long)(n - i - 1) * (a[i + 1] - a[i]);
        d2[i] = cur;
    }
    int answer = inf;
    for (int i = 0; i < n; ++i) {
        long long cnt_1 = d1[i];
        if (cnt_1 > k) break;
        long long remain = k - cnt_1;
        int l = 0;
        int r = n;
        while (l + 1 < r) {
            int med = (l + r) / 2;
            if (d2[med] > remain) l = med;
            else r = med;
        }
        if (r <= i) {
            cout << 0;
            return 0;
        }
        long long remain_2 = remain - d2[r];
        int diff = -remain_2 / (n - r) + a[r] - a[i];
        answer = min(answer, diff);
    }
    for (int i = n - 1; i >= 0; --i) {
        long long cnt_1 = d2[i];
        if (cnt_1 > k) break;
        long long remain = k - cnt_1;
        int l = -1;
        int r = n;
        while (l + 1 < r) {
            int med = (l + r) / 2;
            if (d1[med] > remain) r = med;
            else l = med;
        }
        if (l >= i) {
            cout << 0;
            return 0;
        }
        long long remain_2 = remain - d1[l];
        int diff = -remain_2 / (l + 1) + a[i] - a[l];
        answer = min(answer, diff);
    }
    cout << answer;
    return 0;
}