#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int t;
    int a, b, c, d, k;
    int i, j;
    bool f;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        for(i = 0, f = false; i <= k && !f; i ++)
            for(j = 0; i + j <= k && !f; j ++)
                if(a <= i * c && b <= j * d)
                {
                    printf("%d %d\n", i, j);
                    f = true;
                }
        if(!f)
            puts("-1");
    }

    return 0;
}