#include<bits/stdc++.h>
int t,a,b,c,d,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int sa=(a-1)/c+1;
        int sb=(b-1)/d+1;
        if(sa+sb>k){puts("-1");continue;}
        printf("%d %d\n",sa,sb);
    }
}