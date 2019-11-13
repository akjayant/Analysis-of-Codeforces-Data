#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

char s[1111111];

int64_t md = 1000000007;

int64_t ss[1111111] = { 1, 2, 3 };

int main()
{
    int n;
    scanf("%s", s);
    n = strlen(s);
    int64_t ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'w' || s[i] == 'm')
        {
            printf("0");
            return 0;
        }
    }
    for (int i = 3; i < n; i++)
    {
        ss[i] = (ss[i-1]+ss[i-2])%md;
    }
    int ppv = 0;
    int pc = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ppv)
        {
            pc++;
        }
        else
        {
            if (ppv == 'u' || ppv == 'n')
            {
                ans *= ss[pc-1];
                ans %= md;
            }
            ppv = s[i];
            pc = 1;
        }
    }
    if (ppv == 'u' || ppv == 'n')
    {
        ans *= ss[pc-1];
        ans %= md;
    }
    printf("%lld", ans);
}
