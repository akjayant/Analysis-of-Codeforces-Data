#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define LL long long
const int maxn=1e6+5;
bool jud[maxn];
int pri[maxn],cnt=0;
void init()
{
	for(int i=2;i<maxn;i++)
	{
		if(!jud[i])pri[++cnt]=i;
		for(int j=1;j<=cnt&&pri[j]*i<maxn;j++)
		{
			jud[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int main()
{
	LL n;
	init(),scanf("%lld",&n);
	for(int i=1;i<=cnt&&pri[i]<n;i++)
	{
		if(n%pri[i]==0)
		{
			LL cp=n;
			while(cp%pri[i]==0)cp/=pri[i];
			if(cp==1){printf("%d\n",pri[i]);return 0;}
			else {printf("1\n");return 0;}
		}
	}
	printf("%lld\n",n);
	return 0;
}
