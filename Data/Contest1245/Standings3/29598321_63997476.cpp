#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 100005;
const int MOD = 1000000007;
const int MAMOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(gcd(a,b)!=1)
            printf("Infinite\n");
        else
            printf("Finite\n");
    }
    return 0;
}