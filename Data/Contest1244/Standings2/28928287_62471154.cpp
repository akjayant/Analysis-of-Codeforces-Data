#include <algorithm>
#include <cstdio>
int main() {
    int t;
    for (scanf("%d", &t); t--; ) {
        int n, sum = 0, res = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int m;
            scanf("%1d", &m);
            sum += m;
            if (m) {
                res = std::max(res, (i + 1) * 2);
                res = std::max(res, (n - i) * 2);
            }
        }
        res = std::max(res, sum + n);
        printf("%d\n", res);
    }
    return 0;
}
