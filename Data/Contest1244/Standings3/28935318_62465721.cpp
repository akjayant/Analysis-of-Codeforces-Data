#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, c, d, k, x, y;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        x = (a-1) / c + 1;
        y = (b-1) / d + 1;
        if (x + y > k) printf("-1\n");
        else printf("%d %d\n", x, y);
    }
    return 0;
}

