#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define MOD 1000000007
using namespace std;

int Power(int x, int y)
{
    int o;

    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % MOD;
        x = (long long)x * x % MOD;
    }

    return o;
}

int main(void)
{
    int n, m;

    cin >> n >> m;
    cout << Power((Power(2, m) + MOD - 1) % MOD, n) << endl;

    return 0;
}
