#include <iostream>
#include <cstdio>

using namespace std;


const int N = 105;

char s[N], ans[N];

void solve()
{
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    scanf("%s", s);
    int win = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'R')
        {
            if (b > 0)
            {
                ++win;
                --b;
                ans[i] = 'P';
            }
            else
                ans[i] = '.';
        }
        if (s[i] == 'P')
        {
            if (c > 0)
            {
                ++win;
                --c;
                ans[i] = 'S';
            }
            else
                ans[i] = '.';
        }
        if (s[i] == 'S')
        {
            if (a > 0)
            {
                ++win;
                --a;
                ans[i] = 'R';
            }
            else
                ans[i] = '.';
        }
    }

    if (win * 2 < n)
    {
        printf("NO\n");
        return;
    }

    printf("YES\n");
    for (int i = 0; i < n; ++i)
    {
        if (ans[i] == '.')
        {
            if (a > 0)
                ans[i] = 'R', --a;
            else if (b > 0)
                ans[i] = 'P', --b;
            else if (c > 0)
                ans[i] = 'S', --c;
        }

        printf("%c", ans[i]);
    }
    printf("\n");


}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif


    int t;
    scanf("%d", &t);
    while(t--)
        solve();

}
