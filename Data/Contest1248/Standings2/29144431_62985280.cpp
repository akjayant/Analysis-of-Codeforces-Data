#include <cstdio>
#include <algorithm>
using std::sort;

const int kN = 100005;
long long a[kN];
int n;

int main() {
    long long sum = 0, half_sum = 0;;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    int half = (n >> 1);
    for(int i = 1; i <= half; i++) {
        half_sum += a[i];
    }
    printf("%lld", half_sum * half_sum + (sum - half_sum) * (sum - half_sum));
    return 0;
}