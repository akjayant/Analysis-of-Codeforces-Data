// Crt. 2019-10-13  17:04:28
#include <bits/stdc++.h>
using namespace std;

char s[10000];

int n;

void work() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    int res = n;
    for (int i = 1; i <= n; ++i)
        if (s[i] == '1') res = max(res, max(2 * i, 2 * (n - i + 1)));
    printf("%d\n", res);
}

int main() {
#ifdef whyqx
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif
    int T; cin >> T;
    while (T--) work();
    return 0;
}
