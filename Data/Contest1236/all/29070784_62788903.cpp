#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, m;

int binPow (int x, int y) {
    int ans = 1;
    while (y > 0) {
        if (y & 1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }

    return ans;
}

int main(){
    scanf("%d %d", &n, &m);
    //(2^m - 1)^n
    int ans = (binPow(2, m) - 1) % mod;
    if (ans < 0) ans += mod;
    ans = binPow(ans, n);
    if (ans < 0) ans += mod;
    printf("%d", ans);
    return 0;
}
