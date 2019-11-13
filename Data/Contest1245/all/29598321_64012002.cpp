#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 100005;
const int MOD = 1000000007;
const int MAMOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
char s[MAXN];
ll fib[MAXN];

int main()
{
    fib[2] = 2;
    fib[3] = 3;
    for (int i = 4; i < MAXN - 4; ++i)
        fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;
    bool flag = 1;
    scanf("%s", s);
    for (int i = 0; s[i]; ++i)
    {
        if (s[i] == 'm' || s[i] == 'w')
            flag = 0;
    }
    if (!flag)
    {
        printf("0\n");
        return 0;
    }
    ll ret = 1;
    int cntu = 0, cntn = 0;
    for (int i = 0; s[i]; ++i)
    {
        if (s[i] == 'u')
            cntu++;
        if (s[i] != 'u')
        {
            if (cntu > 1)
            {
                ret *= fib[cntu];
                ret %= MOD;
            }
            cntu = 0;
        }
        if (s[i] == 'n')
            cntn++;
        if (s[i] != 'n')
        {
            if (cntn > 1)
            {
                ret *= fib[cntn];
                ret %= MOD;
            }
            cntn = 0;
        }
    }
    if (cntu > 1)
    {
        ret *= fib[cntu];
        ret %= MOD;
        cntu = 0;
    }
    if (cntn > 1)
    {
        ret *= fib[cntn];
        ret %= MOD;
        cntn = 0;
    }
    printf("%lld\n", ret % MOD);
    return 0;
}