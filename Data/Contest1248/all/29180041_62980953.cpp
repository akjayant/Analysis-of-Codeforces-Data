#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

signed main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n, [](int a, int b) {return a > b;});
    int m = n / 2 + bool(n & 1), s = 0, t = 0;
    for (int i = 0; i < m; ++i)
        s += a[i];
    for (int i = m; i < n; ++i)
        t += a[i];
    cout << s * s + t * t;
    return 0;
}
