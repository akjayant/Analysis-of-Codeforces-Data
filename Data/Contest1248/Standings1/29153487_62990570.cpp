#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

int64_t fb[1111111];
int64_t const mod = 1000000007;

int main()
{
    int n, m;
    scanf("%i%i", &n, &m);
    fb[1] = 2;
    fb[2] = 4;
    for (int i = 3; i < 111111; i++)
    {
        fb[i] = (fb[i - 1] + fb[i - 2]) % mod;
    }
    printf("%lld", (fb[n]+fb[m]+(mod-2))%mod);
}