#include "stdio.h"
#include "string.h"
#include "iostream"

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        std::string fuck;
        std::cin >> fuck;
        int win = 0;
        char ch[101];

        for (int i = 0; i < fuck.size(); ++i)
        {
            if (fuck[i] == 'R' && b > 0)
            {
                --b;
                win++;
                ch[i] = 'P';
            }
            else if (fuck[i] == 'P' && c > 0)
            {
                --c;
                ++win;
                ch[i] = 'S';
            }
            else if (fuck[i] == 'S' && a > 0)
            {
                --a;
                ++win;
                ch[i] = 'R';
            }
            else
            {
                ch[i] = '?';
            }
        }
        if (win * 2 < n)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            for (int i = 0; i < n; ++i)
            {
                if (ch[i] == '?')
                {
                    if (a > 0)
                    {
                        --a;
                        printf("R");
                    }
                    else if (b > 0)
                    {
                        --b;
                        printf("P");
                    }
                    else
                    {
                        --c;
                        printf("S");
                    }
                }
                else printf("%c", ch[i]);
            }
            printf("\n");
        }
    }
}
