#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL goL[2342342];
LL n,k,KK;
LL a[2342342],b[2342342];

LL findL(LL x)
{
  x=min(x,n);
  if(!b[x]) return x;
  else return goL[x]=findL(goL[x]);
}

int main()
{
  LL i,t;
  scanf("%lld%lld",&n,&k),KK=k;
  if(k<n*(n+1)/2) {printf("-1\n");return 0;}
  k-=n*(n+1)/2;
  for(i=1;i<=n;i++) goL[i]=i-1;
  for(i=1;i<=n;i++)
    {
	  t=findL(i+k);
	  b[t]=1,a[i]=t;
	  if(i<a[i]) k-=(a[i]-i);
	}
  printf("%lld\n",KK-k);
  for(i=1;i<n;i++) printf("%lld ",i);
  printf("%lld\n",i);
  for(i=1;i<n;i++) printf("%lld ",a[i]);
  printf("%lld\n",a[i]);
} 