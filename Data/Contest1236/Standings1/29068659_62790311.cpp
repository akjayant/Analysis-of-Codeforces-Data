#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

#define P 1000000007

int n, m;
long long ans, tem;

long long qpow(long long a, long long b)
{
    long long an = 1;
    while (b)
    {
        if (b & 1)
            an = (an*a) % P;
        a = (a*a) % P;
        b >>= 1;
    }
    return an % P;
}

int main()
{
    scanf("%d%d", &n, &m);
    tem = qpow(2, m);
    tem = (tem-1ll+P) % P;
    tem = qpow(tem, n);
    printf("%I64d\n", tem);
    return 0;
}