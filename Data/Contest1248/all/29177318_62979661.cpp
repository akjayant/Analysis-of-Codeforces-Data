#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        int cnta1 = 0, cnta0 = 0;
        scanf("%d", &n);
        int a;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            if (a % 2)
                cnta1++;
            else
                cnta0++;
        }
        int m;
        int cntb1 = 0, cntb0 = 0;
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &a);
            if (a % 2)
                cntb1++;
            else
                cntb0++;
        }
        printf("%I64d\n", (long long)cnta1 * cntb1 + (long long)cnta0 * cntb0);
    }
    return 0;
}