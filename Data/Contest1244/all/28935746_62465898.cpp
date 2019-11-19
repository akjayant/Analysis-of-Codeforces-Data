#include <bits/stdc++.h>

#define llong long long

using namespace std;

int main(void)
{
    llong t = 0, n = 0, m = 0, x = 0, y = 0, k = 0, v = 0, u = 0;
    cin >> t;
    for (llong r = 0; r < t; r++)
    {
        cin >> n >> m >> x >> y >> k;
        v = ((n + x - 1) / x);
        u = ((m + y - 1) / y);
        if (v + u > k)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << v << ' ' << u << '\n';
    }
    return 0;
}
