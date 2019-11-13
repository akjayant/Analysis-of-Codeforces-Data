#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


char s[111];
char ans[111];

int main()
{
    int t;
    scanf("%d", &t);
    int a, b, c, n;
    while (t--)
    {
        scanf("%d", &n);
        scanf("%d%d%d", &a, &b, &c);
        scanf("%s", s);
        int cnta = 0, cntb = 0, cntc = 0;
        for (int i = 0; s[i]; ++i)
            if (s[i] == 'R') ++cnta;
            else if (s[i] == 'P') ++cntb;
            else ++cntc;
        int needA = min(a, cntc);
        int needB = min(b, cnta);
        int needC = min(c, cntb);
        if (((needA + needB + needC) * 2) >= n)
        {
            puts("YES");
            ans[n] = 0;
            for (int i = 0; s[i]; ++i)
            {
                ans[i] = 0;
                if (s[i] == 'R')
                {
                    if (needB)
                    {
                        --needB;
                        --b;
                        ans[i] = 'P';
                    }
                }
                else if (s[i] == 'P')
                {
                    if (needC)
                    {
                        --needC;
                        --c;
                        ans[i] = 'S';
                    }
                }
                else
                {
                    if (needA)
                    {
                        --needA;
                        --a;
                        ans[i] = 'R';
                    }
                }
            }
            for (int i = 0; s[i]; ++i)
                if (ans[i] == 0)
                {
                    if (a)
                    {
                        ans[i] = 'R';
                        --a;
                    }
                    else if (b)
                    {
                        ans[i] = 'P';
                        --b;
                    }
                    else
                    {
                        ans[i] = 'S';
                        --c;
                    }
                }
            printf("%s\n", ans);
        }
        else puts("NO");
    }
    return 0;

}
