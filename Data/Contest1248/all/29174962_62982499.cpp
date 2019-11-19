#include <cstdio>
#include <algorithm>

int n, a[100010];long long sum = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), sum += a[i];
    std::sort(a + 1, a + n + 1);

    long long Ans1 = 0, s1 = 0;
    for (int i = 1; i <= n / 2; i++) {
        s1 += a[i];
    }
    Ans1 = s1 * s1 + (sum - s1) * (sum - s1);

    if (n % 2) {
        s1 = 0;
        for (int i = 1; i <= n / 2 + 1; i++) {
            s1 += a[i];
        }
        Ans1 = std::max(Ans1, s1 * s1 + (sum - s1) * (sum - s1));
    }

    printf("%lld\n", Ans1);
    return 0;
}
