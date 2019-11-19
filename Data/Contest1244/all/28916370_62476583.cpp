#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    int n, p, d, w; cin >> n >> p >> w >> d;
    for (int i = 0; i < w; i ++) if ((d * i) % w == p % w) {
        int j = p - (d * i);
        if (j < 0) continue;
        j /= w;
        if (i + j > n) continue;
        return cout << j << " " << i << " " << n - j - i << "\n", 0;
    }
    cout << -1 << "\n";
}
