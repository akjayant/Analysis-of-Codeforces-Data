#include <iostream>
#include <cstdio>
#define ll long long
#define maxn 101000
using namespace std;
const ll mod=1e9+7;
ll f[maxn];
int n,m;

int main()
{
    scanf("%d %d",&n,&m);
    f[0]=1,f[1]=1;
    for(register int i=2;i<maxn;i++) f[i]=(f[i-1]+f[i-2])%mod;
    printf("%lld",((f[n]-1)*2+(f[m]-1)*2+2)%mod);
    return 0;
}