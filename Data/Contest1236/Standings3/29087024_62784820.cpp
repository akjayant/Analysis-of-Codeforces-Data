#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int a, b, c;    scanf("%d%d%d", &a, &b, &c);
        int ans = 0;
        int cnt1 = min(b, c / 2);
        ans = 3 * cnt1;
        b -= cnt1;
        ans += min(a, b / 2) * 3;
        printf("%d\n", ans);
    }
    getchar(); getchar();
    return 0;
}