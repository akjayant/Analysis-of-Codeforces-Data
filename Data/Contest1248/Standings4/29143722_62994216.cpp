#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int f[maxn];

int main()
{
    int n, m;
    cin >> n >> m;

    f[1] = 2, f[2] = 4;
    for (int i = 3; i < maxn; i++)
        f[i] = (f[i - 1] + f[i - 2]) % mod;

    cout << (f[n] + f[m] - 2) % mod;

    return 0;
}