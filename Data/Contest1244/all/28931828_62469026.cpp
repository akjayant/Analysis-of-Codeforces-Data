#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <random>
#include <math.h>
#include <queue>
#include <stack>
#include <algorithm>
#define LL long long

using namespace std;

const int mod = 1e9+7;
const int maxn = 11234567;

char str[1123];

int main()
{
    ios::sync_with_stdio(false);

    int t, n;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        scanf("%s", str);

        int len = 0;
        int tmp = 0;
        for (int i = 0; i < n; ++i)
        {
            if (str[i] == '1') tmp = i+1;
        }

        if (tmp) len = max(len, tmp);

        for (int i = 0; i < n; ++i)
        {
            if (str[i] == '1')
            {
                len = max(len, n-i);
                break;
            }
        }

        if (len == 0) printf("%d\n", n);
        else printf("%d\n", len*2);
    }

    return 0;
}
