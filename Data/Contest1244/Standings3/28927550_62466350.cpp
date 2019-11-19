// Crt. 2019-10-13  17:04:28
#include <bits/stdc++.h>
using namespace std;

void work() {
    int a, b, c, d, k;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
    int res1 = (a - 1) / c + 1;
    int res2 = (b - 1) / d + 1;
    if (res1 + res2 > k) puts("-1");
    else printf("%d %d\n", k - res2, res2);
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
