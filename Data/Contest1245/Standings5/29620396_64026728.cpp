#include <bits/stdc++.h>

typedef long long ll;

const int N = 100000 + 5;
const int MOD = 1e9 + 7;

int n;
ll f[N];
char s[N];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
    ll res = 1;
    bool flag = false;
    for (int i = 1, cnt = 0; i <= n; i++) {
        if (s[i] == 'w' || s[i] == 'm') flag = true;
        if (cnt) {
            if (s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u')) cnt++;
            else {
                (res *= f[cnt]) %= MOD;
                cnt = 0;
            }
        }
        if (!cnt && (s[i] == 'u' || s[i] == 'n')) cnt = 1;
        if (i == n && cnt != 0) (res *= f[cnt]) %= MOD;
    }
    if (flag) puts("0");
    else {
        printf("%I64d\n", res);
    }
    return 0;
}