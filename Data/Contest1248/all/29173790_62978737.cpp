#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define LL long long 
#define LD long double
int t,n,m;
LL p1[100005],p2[100005],ans,tong1,tong2;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);ans=tong1=tong2=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&p1[i]);
			if(p1[i]&1)tong1++;
			else tong2++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%I64d",&p2[i]);
			if(p2[i]&1)ans+=tong1;
			else ans+=tong2;
		}
		printf("%I64d\n",ans);
	}
}