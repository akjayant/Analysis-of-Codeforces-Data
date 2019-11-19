# include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;

long long k, pf[N], sf[N];
int n, a[N];

bool check(int x) {
    int pt = 1;
    long long mn = 1e18;
    for (int i = 1; i <= n; i++) {
        while (pt + 1 <= n && a[i] + x >= a[pt + 1])
            pt ++;
        long long ret = (i - 1) *1ll* a[i] - pf[i - 1];
        ret += sf[pt + 1] - (n - pt) *1ll* (a[i] + x);
        mn = min(mn, ret);
    }
    pt = n;
    for (int i = n; i >= 1; i--) {
        while (pt - 1 >= 1 && a[i] - x <= a[pt - 1])
            pt --;
        long long ret = sf[i + 1] - (n - i) *1ll* a[i];
        ret += (a[i] - x) *1ll* (pt-1) - pf[pt - 1];
        mn = min(mn, ret);
    }
    return mn <= k;
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
        pf[i] = pf[i - 1] + a[i];

    for (int i = n; i >= 1; i--)
        sf[i] = sf[i + 1] + a[i];

    int l = 0, r = 1e9;

    while (l <= r) {
        int md = (l + r) >> 1;
        if (check(md))
            r = md - 1;
        else
            l = md + 1;
    }

    cout << r + 1 << endl;
}
