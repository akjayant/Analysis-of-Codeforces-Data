#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e6;


const int MOD = 1e9 + 7;

int Add(int x, int y) {
    return ((0ll + x + y) % MOD + MOD) % MOD;
}

int f[N];
int main() {
    // freopen("in.txt", "r",stdin);
    ios::sync_with_stdio(false);

    f[0] = f[1] = 2;
    for(int i = 2;i <= 100000;i ++) f[i] = Add(f[i-1], f[i-2]);

    int n, m;
    cin >> n >> m;
    int res = f[m];
    for(int i = 2;i <= n;i ++) {
        res = Add(res, Add(f[i], -f[i-1]));
    }
    cout << res << endl;
    return 0;
}