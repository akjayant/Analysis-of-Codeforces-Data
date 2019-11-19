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
int n;

char sc[333333];
int sm[666666];

int stree[6666666*4];

void build(int v, int l, int r)
{
    if (l == r)
    {
        stree[v] = sm[l];
    }
    else
    {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        stree[v] = min(stree[v * 2], stree[v * 2 + 1]);
    }
}

int smin(int v, int l, int r, int tl, int tr)
{
    if (tl > tr)
        return INT_MAX;
    if (l == tl && r == tr)
        return stree[v];
    int m = (l + r) / 2;
    return min(smin(v*2, l, m, tl, min(m, tr)), smin(v*2+1, m+1, r, max(m, tl+1), tr));
}

int main()
{
    scanf("%i", &n);
    scanf("%s", sc);

    int mv = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int p = i > 0 ? sm[i - 1] : 0;
        sm[i] = p + (sc[i] == '(' ? 1 : -1);
        sm[i + n] = sm[i];
        if (sm[i] < mv)
            mv = sm[i];
    }
    if (sm[n - 1] != 0)
    {
        printf("0\n1 1");
        return 0;
    }

    int bl = 0;
    int br = 0;
    int b = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(sc[i], sc[j]);

            mv = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                int p = i > 0 ? sm[i - 1] : 0;
                sm[i] = p + (sc[i] == '(' ? 1 : -1);
                sm[i + n] = sm[i];
                if (sm[i] < mv)
                    mv = sm[i];
            }

            int mvs = 0;

            for (int i = 0; i < n; i++)
            {
                if (sm[i] == mv)
                    mvs++;
            }

            if (mvs > b)
            {
                b = mvs;
                bl = i;
                br = j;
            }
            swap(sc[i], sc[j]);
        }
    }
    printf("%i\n%i %i", b, bl+1, br+1);
}
