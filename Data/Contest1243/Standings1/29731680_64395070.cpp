#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
char s[maxn], t[maxn];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, t1 = 0, t2 = 0, ok = 1;
        scanf("%d%s%s", &n, s + 1, t + 1);
        for (int i = 1; i <= n; i++)
            if (s[i] != t[i])
            {
                if (!t1)
                    t1 = i;
                else if (!t2)
                    t2 = i;
                else
                {
                    ok = 0;
                    break;
                }
            }
        if (s[t1] != s[t2] || t[t1] != t[t2] || !t2)
            ok = 0;
        if (ok)
            puts("Yes");
        else
            puts("No");
    }
}