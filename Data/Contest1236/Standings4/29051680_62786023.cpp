#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;

int main() {

    int T; scanf("%d", &T);
    while (T--) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        int ans = 0;
        ans += min(b * 2, c / 2 * 2);
        c -= ans, b -= ans / 2;
        ans += ans / 2;

        int tmp = min(a * 2, b / 2 * 2);
        ans += tmp / 2 * 3;
        printf("%d\n", ans);
    }

    return 0;
}