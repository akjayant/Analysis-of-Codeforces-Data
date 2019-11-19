#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300033;
int n;
char s[MAXN];
char t[MAXN];
int MX = -1, rL, rR;
int match[MAXN];

pair<char, int> St[MAXN];
int ttop = 0;

inline int check(int L, int R)
{
    for (int i = 1; i <= n; i++)
        t[i] = s[i];
    swap(t[L], t[R]);
    t[0] = ')';
    t[n + 1] = '(';
    int lR = 0, rL = n + 1;
    ttop = 0;

    int cnt = 1;
    for (int i = 0; i <= n + 1; i++)
    {
        if (t[i] == ')')
        {
            if (ttop > 0 && St[ttop].first == '(')
            {
                --ttop;
                continue;
            }
            else
            {
                St[++ttop] = make_pair(')', i);
            }
        }
        else
        {
            St[++ttop] = make_pair('(', i);
        }
    }
    if (ttop == 2)
        cnt--;
    while (ttop)
    {
        if (St[ttop].first == '(')
        {
            rL = min(rL, St[ttop].second);
        }
        if (St[ttop].first == ')')
        {
            lR = max(lR, St[ttop].second);
        }
        ttop--;
    }

    for (int i = lR + 1; i < rL; i++)
    {
        // St[++ttop] = make_pair(t[i], i);
        if (t[i] == '(')
        {
            St[++ttop] = make_pair(t[i], i);
        }
        else
        {
            if (St[ttop].first == '(' && ttop > 0)
            {
                match[i] = St[ttop].second;
                match[St[ttop].second] = i;
                ttop--;
            }
            else
            {
                St[++ttop] = make_pair(t[i], i);
            }
        }
    }
    for (int i = lR + 1; i < rL; i++)
    {
        ++cnt;
        i = match[i];
    }
    return cnt;
}

int main()
{
    scanf("%d", &n);
    scanf("%s", s + 1);
    int Lb = 0, Rb = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
            Lb++;
        else
            Rb++;
    }
    if (Lb != Rb)
    {
        printf("0\n1 1");
        return 0;
    }
    int buf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            buf = check(i, j);
            if (buf > MX)
            {
                MX = buf;
                rL = i;
                rR = j;
            }
        }
    }
    printf("%d\n%d %d", MX, rL, rR);
    // system("pause");
    return 0;
}
