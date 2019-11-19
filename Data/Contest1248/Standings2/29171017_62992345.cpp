#include<bits/stdc++.h>
using namespace std;
typedef long long L;
const int mod=1e9+7;
L f[100100];
int main()
{
    f[1]=1;f[2]=2;
    for(int i=3;i<=1e5;i++){
        f[i]=(f[i-1]+f[i-2])%mod;
    }

    L n,m;
    scanf("%lld %lld",&n,&m);


    printf("%lld\n",(((f[m]+f[n]-1)*2%mod)+mod)%mod);
    return 0;
}
