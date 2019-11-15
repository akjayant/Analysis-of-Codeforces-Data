#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(void)
{
    int t;
    int a, b, c;
    int i;
    int o;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d %d", &a, &b, &c);
        for(i = o = 0; (i << 1) <= b; i ++)
            o = max(o, (min(a, i) + min(b - (i << 1), c >> 1)) * 3);

        printf("%d\n", o);
    }

    return 0;
}