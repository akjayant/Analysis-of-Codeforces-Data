#include <cstdio>
#include <algorithm>

const int Maxn = 100010;
int n, A[Maxn];
long long Sum1, Sum2;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; ++i)
        Sum1 += A[i];
    std::sort(A + 1, A + n + 1);
    for (int i = 1; i <= n / 2; ++i)
        Sum2 += A[i];
    printf("%lld\n", Sum2 * Sum2 + (Sum1 - Sum2) * (Sum1 - Sum2));
    return 0;
}