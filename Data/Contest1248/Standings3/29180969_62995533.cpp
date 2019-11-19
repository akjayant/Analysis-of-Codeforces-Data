#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=100010;
ll f[maxn];
void init()
{
    f[1]=2;
    f[2]=4;
    for(int i=3;i<=maxn;i++)
    {   
        f[i]=f[i-1]+f[i-2];
        f[i]%=mod;
    }
}
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%I64d\n",((f[n]+f[m]-2)%mod+mod)%mod);
    return 0;
}