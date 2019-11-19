#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,m,fib[100010];
int main()
{
    scanf("%lld%lld",&n,&m);
    fib[0]=fib[1]=1;
    for(int i=2;i<=max(n,m);i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
    printf("%lld",(2*fib[m]+2*fib[n]-2+mod)%mod);
    return 0;
}