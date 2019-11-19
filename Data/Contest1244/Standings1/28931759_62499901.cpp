#include <cstdio>
#include <algorithm>

using namespace std;
using LL=long long;

int n, a[100005];
LL k, sum[100005];

bool check(int x) {
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && a[j] <= a[i] + x)
            j++;
        --j;
        if (((LL) (i - 1) * a[i] - sum[i - 1]) + (sum[n] - sum[j] - (LL) (n - j) * (x + a[i])) <= k)
            return true;
    }
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && a[j] <= a[i] - x)
            j++;
        if (((LL) (j - 1) * (a[i]-x) - sum[j - 1]) + (sum[n] - sum[i] - (LL) (n - i) * a[i]) <= k)
            return true;
    }
    return false;
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    int L = 0, R = 1E9;
    while (L < R) {
        int M = L + R >> 1;
        if (check(M))
            R = M;
        else
            L = M + 1;
    }
    printf("%d", L);
    return 0;
}