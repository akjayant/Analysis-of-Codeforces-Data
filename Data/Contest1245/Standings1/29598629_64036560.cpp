
#include <bits/stdc++.h>

#define ln                '\n'
#define anum(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int lgsz = 32;
int ts;
num l, r, dp[lgsz + 5][2][2]; 

num inline calc(num n, num m) {
    if (n < 0 || m < 0)  return 0;
    memset(dp, 0, sizeof(dp));
    dp[33][0][0] = 1;
    for (int i = lgsz; i >= 0; --i) {
        loop (x, 2) {
            loop (y, 2) {
                num cx = x | ((n >> i) & 1), cy = y | ((m >> i) & 1), val = dp[i + 1][x][y];
                dp[i][cx][cy] += val;
                dp[i][x][cy] += val * cx;
                dp[i][cx][y] += val * cy;
            }
        }
    }
    return dp[0][0][0] + dp[0][0][1] + dp[0][1][0] + dp[0][1][1];
}

num inline solve() {
    cin >> l >> r;
    return calc(r, r) + calc(l - 1, l - 1) - calc(l - 1, r) * 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> ts;
    cont (cs, ts) {
        cout << solve() << ln;
    }
}