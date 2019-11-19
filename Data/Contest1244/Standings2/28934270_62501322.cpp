#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define N 2000005
using namespace std;
int n;
ll ans[N],sum=0;
ll k;
int main(){
scanf("%d%lld",&n,&k);
for(int i=1;i<=n;i++)ans[i]=i;
sum=1ll*n*(n+1)/2;
if(sum>k)return puts("-1"),0;
for(int i=1;i<=n/2;i++){
if(sum+(ans[n-i+1]-ans[i])<=k){sum+=(ans[n-i+1]-ans[i]);swap(ans[i],ans[n-i+1]);}
else {ll d=sum+(ans[n-i+1]-ans[i])-k;sum=k;swap(ans[i],ans[n-i+1-d]);break;}
}
printf("%lld\n",sum);
for(int i=1;i<=n;i++)printf("%d ",i);puts("");
for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}