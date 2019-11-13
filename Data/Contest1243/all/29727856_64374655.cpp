#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef LOCAL
    FILE *f = freopen("input", "r", stdin);\
    freopen("output", "w", stdout);
#endif

    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);
        reverse(a, a + n);

        int i = 0;
        while (i < n && (i + 1) <= a[i]) i++;
        cout << i << "\n";
    }

    return 0;
}