// CF C
// DeP
#include <cstdio>
#include <cstring>

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

int n;
char S[MAXN];
int f[MAXN], g[MAXN];

int main() {
    scanf("%s", S);
    n = (int) strlen(S);
    f[0] = f[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; ++i) f[i] = (f[i-1] + f[i-2]) % MOD;
    for (int i = 0; i < n; ++i) {
        if (S[i] == 'w' || S[i] == 'm') return printf("0\n"), 0;
        if (S[i] == 'u' || S[i] == 'n') {
            int j = i;
            while (j+1 < n && S[j+1] == S[i]) ++j;
            if (j-i+1 > 1) ans = 1LL * ans * f[j-i+1] % MOD;
            i = j;
        }
    }
    printf("%d\n", ans);
    return 0;
}
