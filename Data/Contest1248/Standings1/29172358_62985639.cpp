#include<bits/stdc++.h>

const int Mx=1e5+100;
int sum[Mx],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&sum[i]);
    std::sort(sum+1,sum+1+n);
    long long sum1=0,sum2=0;
    for(int i=1;i<=n/2;i++)sum1+=sum[i];
    for(int i=n/2+1;i<=n;i++)sum2+=sum[i];
    printf("%lld",sum1*sum1+sum2*sum2);
}