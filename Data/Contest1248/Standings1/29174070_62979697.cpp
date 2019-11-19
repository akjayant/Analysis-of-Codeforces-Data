#include <cstdio>

inline void Work();

int main()
{
    int TestCase;
    scanf("%d", &TestCase);
    for (; TestCase; --TestCase) Work();
    return 0;
}

const int Maxn = 100010;
int n, m, Cnt1, Cnt2, Cnt3, Cnt4;

inline void Work()
{
    Cnt1 = Cnt2 = Cnt3 = Cnt4 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        if (x & 1)
            ++Cnt1;
        else
            ++Cnt2;
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        int x;
        scanf("%d", &x);
        if (x & 1)
            ++Cnt3;
        else
            ++Cnt4;
    }
    printf("%lld\n", 1LL * Cnt1 * Cnt3 + 1LL * Cnt2 * Cnt4);
    return;
}