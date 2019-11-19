#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MA=1e6+5;
const int P=1e9+7;

ll d[MA][2];
ll n,m,rte=0,ans=0;
ll tp[MA];

int main()
{
    scanf("%d%d",&n,&m);
    d[1][1]=0;
    d[1][0]=2;
    tp[1]=1;
    tp[2]=2;
    for(int i=2;i<=m;++i){
        d[i][0]=(d[i-1][1]+d[i-1][0])%P;
        d[i][1]=d[i-1][0]%P;
    }
    for(int i=3;i<=n;++i){
        tp[i]=(tp[i-1] + tp[i-2])%P;
    }
    rte=(d[m][1]+d[m][0])%P;
    ans=((tp[n]*2)%P+(rte-2)%P)%P;
    printf("%lld\n",ans);
    return 0;
}
