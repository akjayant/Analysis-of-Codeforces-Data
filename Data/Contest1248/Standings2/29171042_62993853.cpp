#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const int mod=1e9+7;
ll a[maxn];
void init()
{
    a[1]=1,a[2]=2;
    for(int i=3;i<=maxn;i++)
        a[i]=(a[i-1]+a[i-2])%mod;

}
int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%lld\n",((a[m]+a[n]-1+mod)%mod*2)%mod);

}
