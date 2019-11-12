#include <bits/stdc++.h>
#define N ((int)1e6+10)
#define MD ((int)1e9+7)

using namespace std;

long long fpow(long long x, long long y) {
    if (y == 0)
        return 1;
    long long ans = fpow(x, y / 2);
    ans = (ans * ans) % MD;
    if (y & 1) {
        ans *= x;
        ans %= MD;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    long long  ans = (fpow(2, m) - 1 + MD) % MD;
    ans = fpow(ans, n);
    cout << ans << endl;
    return 0;
}
