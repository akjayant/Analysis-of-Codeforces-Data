#include<bits/stdc++.h>
const int Mx=1e5+10;
int P[Mx],Q[Mx],n,m,sum11,sum22,sum21,sum12;
int main(){
    int T;scanf("%d",&T);
    while(T--){
        sum11=sum12=sum21=sum22=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&P[i]),P[i]=-P[i];
        scanf("%d",&m);
        for(int i=1;i<=m;i++)scanf("%d",&Q[i]);
        for(int i=1;i<=n;i++)if(P[i]%2==0)sum11++;else sum12++;
        for(int i=1;i<=m;i++)if(Q[i]%2==0)sum21++;else sum22++;
        printf("%lld\n",1ll*sum11*sum21+1ll*sum22*sum12);
    }
}