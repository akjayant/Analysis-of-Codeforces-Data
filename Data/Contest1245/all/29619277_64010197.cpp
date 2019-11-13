#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 207;
char ops[maxn];
int main()
{
    int t, a, b, c, n;
    cin >> t;
    while(t--)
    {
        scanf("%d", &n);
        scanf("%d%d%d", &a, &b, &c);
        scanf(" %s", ops);
        int oa = 0, ob = 0, oc = 0;
        int len = strlen(ops);
        for(int i = 0; i < len; i++)
        {
            if(ops[i] == 'R') oa++;
            if(ops[i] == 'P') ob++;
            if(ops[i] == 'S') oc++;
        }
        int wina = min(a, oc), winb = min(b, oa), winc = min(c, ob);
        int win = wina + winb + winc;
        int ra = a - wina, rb = b - winb, rc = c - winc;
        if(win < (n+1)/2)
            puts("NO");
        else
        {
            puts("YES");
            for(int i = 0; i < len; i++)
            {
                if(ops[i] == 'R')
                {
                    if(winb)
                    {
                        printf("P");
                        winb--;
                    }
                    else
                    {
                        if(ra > 0)
                            printf("R"), ra--;
                        else if(rc > 0)
                            printf("S"), rc--;
                    }
                }
                if(ops[i] == 'P')
                {
                    if(winc)
                    {
                        printf("S");
                        winc--;
                    }
                    else
                    {
                        if(rb > 0)
                            printf("P"), rb--;
                        else if(ra > 0)
                            printf("R"), ra--;
                    }
                }
                if(ops[i] == 'S')
                {
                    if(wina)
                    {
                        printf("R");
                        wina--;
                    }
                    else
                    {
                        if(rc > 0)
                            printf("S"), rc--;
                        else if(rb > 0)
                            printf("P"), rb--;
                    }
                }
            }
        }
        puts("");
    }
    return 0;
}
