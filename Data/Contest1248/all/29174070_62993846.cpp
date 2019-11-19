#include <bits/stdc++.h>
using namespace std;

const int Maxn = 510;
int Len;
char Ch[Maxn];
int Ans, l, r, F[Maxn];

int main()
{
    Ans = 0; l = r = 1;
    scanf("%d", &Len);
    scanf("%s", Ch + 1);
    for (int i = 1; i <= Len; ++i)
        for (int j = i + 1; j <= Len; ++j)
        {
            int Count = 0;
            swap(Ch[i], Ch[j]);
            for (int k = 1; k <= Len; ++k)
                if (Ch[k] == ')')
                    F[k] = F[k - 1] - 1;
                else
                    F[k] = F[k - 1] + 1;
            swap(Ch[i], Ch[j]);
            if (F[Len] != 0) continue;
            int Min = 0;
            for (int k = 1; k <= Len; ++k)
                Min = min(Min, F[k]);
            for (int k = 1; k <= Len; ++k)
                if (Min == F[k])
                    ++Count;
            if (Count > Ans)
            {
                Ans = Count;
                l = i;
                r = j;
            }
        }
    printf("%d\n%d %d\n", Ans, l, r);
    return 0;
}