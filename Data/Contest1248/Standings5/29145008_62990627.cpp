#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n, i, j, a[1000000], p, s = 0, c = 0;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (i = 0; i < n / 2; i++) s += a[i];
    for (i = n / 2; i < n; i++) c += a[i];
    p = pow(s, 2) + pow(c, 2);
    cout << p << '\n';
    return 0;
}
