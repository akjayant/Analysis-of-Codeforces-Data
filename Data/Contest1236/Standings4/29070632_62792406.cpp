#include <bits/stdc++.h>
#define maxn 200000
#define LL long long int
using namespace std;

const LL mod=1000000007LL;
LL qp(LL x,LL n)
{
    LL ans=1LL;
    while(n)
    {
        if(n%2==1LL)ans=ans*x%mod;
        x=x*x%mod;
        n/=2LL;
    }
    return ans;
}
int main()
{
        LL n,m;
        scanf("%lld%lld",&n,&m);

        printf("%lld\n",qp(qp(2LL,m)-1LL,n));
    return 0;
}
