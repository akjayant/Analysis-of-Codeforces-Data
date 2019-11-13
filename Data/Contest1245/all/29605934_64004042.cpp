#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int q;
    scanf("%i", &q);
    while (q--)
    {
        int n;
        scanf("%i", &n);
        int a, b, c;
        scanf("%i%i%i", &a, &b, &c);
        static char t[111];
        int a2 = 0, b2 = 0, c2 = 0;
        scanf("%s", t);
        for (int i = 0; i < n; i++)
        {
            switch (t[i])
            {
            case 'R':
                a2++;
                break;
            case 'P':
                b2++;
                break;
            case 'S':
                c2++;
                break;
            }
        }
        int nice = 0;
        int ans[3] = { 0,0,0 };
        for (int i = 0; i <= a2; i++)
        {
            if (i > b)
                continue;
            for (int j = 0; j <= b2; j++)
            {
                if (j > c)
                    continue;
                for (int k = 0; k <= c2; k++)
                {
                    if (k > a)
                        continue;
                    if (i + j + k >= (n + 1) / 2)
                    {
                        nice = 1;
                        ans[0] = i;
                        ans[1] = j;
                        ans[2] = k;
                    }
                }
            }
        }
        if (nice)
        {
            printf("YES\n");
            a -= ans[2];
            b -= ans[0];
            c -= ans[1];
            a2 = 0;
            b2 = 0;
            c2 = 0;
            for (int i = 0; i < n; i++)
            {
                switch (t[i])
                {
                case 'R':
                    if (a2 < ans[0])
                    {
                        t[i] = 'P';
                        a2++;
                    }
                    else
                    {
                        if (a > 0)
                        {
                            t[i] = 'R';
                            a--;
                        }
                        else
                            if (b > 0)
                            {
                                t[i] = 'P';
                                b--;
                            }
                            else
                                if (c > 0)
                                {
                                    t[i] = 'S';
                                    c--;
                                }
                    }
                    break;
                case 'P':
                    if (b2 < ans[1])
                    {
                        t[i] = 'S';
                        b2++;
                    }
                    else
                    {
                        if (a > 0)
                        {
                            t[i] = 'R';
                            a--;
                        }
                        else
                            if (b > 0)
                            {
                                t[i] = 'P';
                                b--;
                            }
                            else
                                if (c > 0)
                                {
                                    t[i] = 'S';
                                    c--;
                                }
                    }
                    break;
                case 'S':
                    if (c2 < ans[2])
                    {
                        t[i] = 'R';
                        c2++;
                    }
                    else
                    {
                        if (a > 0)
                        {
                            t[i] = 'R';
                            a--;
                        }
                        else
                            if (b > 0)
                            {
                                t[i] = 'P';
                                b--;
                            }
                            else
                                if (c > 0)
                                {
                                    t[i] = 'S';
                                    c--;
                                }
                    }
                    break;
                }
            }
            printf("%s\n", t);
        }
        else
        {
            printf("NO\n");
        }
    }
}
