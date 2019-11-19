#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>

using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
    if (b != 0)
        return gcd(b, a % b);
    return a;
}

int main()
{
    int64_t n, p, d, w;
    scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
    int64_t g = gcd(d, w);
    w /= g;
    d /= g;
    if (p % g)
    {
        printf("-1");
        return 0;
    }
    p /= g;
    int64_t top = (p+w-1)/w;
    int64_t bot = top - d;
    if (bot < 0)
        bot = 0;
    if (top > n)
        top = n;
    for (int64_t i = bot; i <= top; i++)
    {
        int64_t yy = p - i * w;
        if (yy % d)
            continue;
        int64_t y = yy / d;
        if (i >= 0 && y >= 0 && i + y <= n)
        {
            int64_t z = n - i - y;
            printf("%lld %lld %lld", i, y, z);
            return 0;
        }
    }
    printf("-1");
}