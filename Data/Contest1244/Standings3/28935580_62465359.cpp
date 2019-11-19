#include <bits/stdc++.h>

using namespace std;

int main()
{
    int _;
    scanf("%d", &_);
    while(_ --)
    {
        int a, b, c, d, k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        int res1 = 0;
        res1 = a / c;
        if(a % c) res1 ++;
        int res2 = 0;
        res2 = b / d;
        if(b % d) res2 ++;
        if(res1 + res2 > k) { puts("-1"); continue; }
        printf("%d %d\n", res1, res2);
    }
    return 0;
}
