// CF C
// DeP
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

int n, m;
int f[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    int N = max(n, m);
    f[0] = f[1] = 1;
    for (int i = 2; i <= N; ++i) f[i] = (f[i-1] + f[i-2]) % MOD;
    int ans = (((f[n]-1)*2 % MOD + (f[m]-1)*2 % MOD) % MOD + 2) % MOD;
    printf("%d\n", ans);
    return 0;
}
