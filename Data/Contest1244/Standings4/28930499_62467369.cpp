#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

char x[11111];

int main()
{
    int  t;
    scanf("%i", &t);
    while (t--)
    {
        int n;
        scanf("%i", &n);
        scanf("%s", x);
        int l = n;
        int r = -1;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == '1')
            {
                l = i;
                break;
            }
        }
        if (l == n)
        {
            printf("%i\n", n);
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if (x[n-i-1] == '1')
            {
                r = n-i-1;
                break;
            }
        }
        int best = n+1;
        if ((r+1)*2 > best)
            best = (r+1)*2;
        if ((n-l)*2 > best)
            best = (n-l)*2;
        printf("%i\n", best);
    }
}
