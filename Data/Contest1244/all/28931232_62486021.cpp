#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define rep(i, a, b) for(int i = a; i < b; ++i)

int debug = 1;

const int N = 3e5;
int n, k, a[N], pre[N], suf[N];

void precalc() {
    rep(i, 1, n) {
        pre[i] = pre[i - 1] + (a[i] - a[i - 1]) * i;
    }
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = suf[i + 1] + (a[i + 1] - a[i]) * (n - i - 1);
    }
}

bool check(int distance) {
    int it, cnt, curCost, cur;
    it = n - 1, cnt = 0, curCost = 0;
    for (int i = n - 1; i >= 0; --i) {
        int R = a[i] + distance;
        while (it >= 0 && a[it] > R) {
            if (it < n - 1) {
                curCost += (a[it + 1] - a[it]) * cnt;
            }
            --it;
            ++cnt;
        }
        cur = pre[i] + curCost;
        if (it < n - 1) {
            cur += abs(a[it + 1] - R) * cnt;
        }
        if (cur <= k) return 1;
    }
    it = 0, cnt = 0, curCost = 0;
    for (int i = 0; i < n; ++i) {
        int L = a[i] - distance;
        while (it < n - 1 && a[it] < L) {
            if (it > 0) {
                curCost += (a[it] - a[it - 1]) * cnt;
            }
            ++it;
            ++cnt;
        }
        cur = suf[i] + curCost;
        if (it > 0) {
            cur += abs(L - a[it - 1]) * cnt;
        }
        if (cur <= k) return 1;
    }
    return 0;
}

main() {
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    precalc();
    int l = -1, r = 1e10;
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}