#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mod 1000000007LL
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
LL pow(LL a, LL b)
{
    if(!b)return 1LL;
    LL ret=pow(a, b/2);
    if(b%2)return ret*ret%mod*a%mod;
    return ret*ret%mod;
}
int main()
{
    LL a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", pow(pow(2LL, b)-(LL)1, a));
}
