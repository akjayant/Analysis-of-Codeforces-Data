#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e5 + 10, MOD = 1e9 + 7;
int a[N];

int32_t main()
{
    int n, x = 0, y = 0; cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n / 2; i ++) x += a[i];
    for (int j = n / 2; j < n; j ++) y += a[j];
    cout << x * x + y * y << "\n";
}
