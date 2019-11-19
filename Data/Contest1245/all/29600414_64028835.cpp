#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
struct jgt_p{int x,y,bj;ll now,frm,k;}pot[2005];
int n;ll INF=1e9+7,ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{scanf("%d%d",&pot[i].x,&pot[i].y);}
	for(int i=1;i<=n;i++)scanf("%lld",&pot[i].now);
	for(int i=1;i<=n;i++)scanf("%lld",&pot[i].k);
	pot[n+1].now=1e9+7;
	int num=n;
	for(int i=1;i<=n;i++)
	{
		int nowl=n+1;
		for(int i=1;i<=n;i++)
		{
			if(pot[i].bj)continue;
			if(pot[i].now<pot[nowl].now){nowl=i;}
		}
		ans+=pot[nowl].now;
		pot[nowl].bj=1;
		for(int i=1;i<=n;i++)
		{
			if(pot[i].bj)continue;
			ll tmp=abs(pot[i].x-pot[nowl].x)+abs(pot[i].y-pot[nowl].y);
			tmp*=(pot[i].k+pot[nowl].k);
			if(tmp<pot[i].now)
			{
				pot[i].now=tmp;
				if(!pot[i].frm)num--;
				pot[i].frm=nowl;
			}
		}
	}
	printf("%lld\n%d\n",ans,num);
	for(int i=1;i<=n;i++)if(!pot[i].frm)printf("%d ",i);
	printf("\n%d\n",n-num);
	for(int i=1;i<=n;i++)
	{
		if(!pot[i].frm)continue;
		printf("%d %d\n",i,pot[i].frm);
		
	}
	
	return 0;
}