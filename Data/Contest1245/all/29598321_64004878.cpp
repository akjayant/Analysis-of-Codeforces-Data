#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 100005;
const int MOD = 1000000007;
const int MAMOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
char s[105], t[105];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(t, 0, sizeof(t));
        int n, a, b, c;
        scanf("%d", &n);
        scanf("%d%d%d", &a, &b, &c);
        scanf("%s", s);
        int win = (n + 1) / 2;
        int d = 0, e = 0, f = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'R')
                d++;
            if (s[i] == 'P')
                e++;
            if (s[i] == 'S')
                f++;
        }
        if (min(d, b) + min(e, c) + min(f, a) >= win)
        {
            printf("YES\n");
            for (int i = 0; i < n; ++i)
            {
                if (s[i] == 'R' && b > 0)
                {
                    t[i] = 'P';
                    b--;
                }
                else if (s[i] == 'P' && c > 0)
                {
                    t[i] = 'S';
                    c--;
                }
                else if (s[i] == 'S' && a > 0)
                {
                    t[i] = 'R';
                    a--;
                }
            }
            for (int i = 0; i < n; ++i)
            {
                if (t[i] != 'S' && t[i] != 'R' && t[i] != 'P')
                {
                    if (a > 0)
                    {
                        t[i] = 'R';
                        a--;
                    }
                    else if (b > 0)
                    {
                        t[i] = 'P';
                        b--;
                    }
                    else if (c > 0)
                    {
                        t[i] = 'S';
                        c--;
                    }
                }
            }
            printf("%s\n", t);
        }
        else
            printf("NO\n");
    }
    return 0;
}