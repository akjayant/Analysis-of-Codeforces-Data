#include <bits/stdc++.h>
using namespace std;

long long mod=1e9+7;

long long fast(long long x,long long v)
{
    long long an=1;
    while(v){
        if(v&1)an=(an*x)%mod;
        x=(x*x)%mod;
        v>>=1;
    }
    return an;
}

long long n,m;

int main()
{
    scanf("%lld%lld",&n,&m);
    long long ans=(fast(2,m)-1)%mod;
    ans=(ans+mod)%mod;
    printf("%lld\n",fast(ans,n));

    return 0;
}
