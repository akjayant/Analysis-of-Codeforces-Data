#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

typedef long long int64;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int64 dp1[MAXN], dp2[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    dp1[1] = dp2[1] = 1;
    dp1[2] = dp2[2] = 2;
    for (int i = 3; i <= max(n, m); i++) {
        dp1[i] = dp2[i - 1] + dp2[i - 2];
        dp2[i] = dp1[i - 1] + dp1[i - 2];

        dp1[i] %= MOD;
        dp2[i] %= MOD;
    }
    int64 ans = (int64)dp1[n] + dp2[n] + dp1[m] * 2 - 2;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}