#include <iostream>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

signed main()
{
    int n, m;
    cin >> n >> m;
    int u = max(n, m) + 1, f[u] = {1, 1};
    for (int i = 2; i < u; ++i)
        f[i] = (f[i-1] + f[i-2]) % mod;
    cout << 2 * (f[n] + f[m] - 1 + mod) % mod;
    return 0;
}
