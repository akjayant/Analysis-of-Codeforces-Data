#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

int main()
{

    int t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        scanf("%i", &n);

        int odd1 = 0;
        int even1 = 0;
        int odd2 = 0;
        int even2 = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%i", &x);
            if (x & 1)
                odd1++;
            else
                even1++;
        }
        int m;
        scanf("%i", &m);
        for (int i = 0; i < m; i++)
        {
            int x;
            scanf("%i", &x);
            if (x & 1)
                odd2++;
            else
                even2++;
        }
        printf("%lld\n", int64_t(odd2) * int64_t(odd1) + int64_t(even2) * int64_t(even1));
    }
}

