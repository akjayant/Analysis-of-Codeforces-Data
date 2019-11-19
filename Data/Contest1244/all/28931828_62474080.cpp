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

bool vis[112345];

int main()
{
    ios::sync_with_stdio(false);

    int t;

    LL n,p,w,d;

    scanf("%lld%lld%lld%lld", &n, &p, &w, &d);

    LL x,y,z;

    x = p/w;
    if (x > n)
    {
        puts("-1");
        return 0;
    }

    LL c = p%w;

    y = c/d;
    c %= d;
    memset(vis, 0, sizeof(vis));
    while (c != 0 && x && (vis[c] == 0))
    {
        vis[c] = 1;
        y += (c+w)/d;
        c = (c+w)%d;
        x--;
    }


    if (c || (x+y>n)) puts("-1");
    else printf("%lld %lld %lld\n", x, y, n-x-y);

    return 0;
}
