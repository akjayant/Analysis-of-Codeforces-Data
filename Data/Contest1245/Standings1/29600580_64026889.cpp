#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

long long T,a,b,ans,x,y,X,Y,t1,t2,s1,s2,S1,S2,i,gg,u1,u2;
long long f[55][2][2];
long long W1[55],W2[55];
long long mi[55];

long long js(long long L1,long long L2)
{
	if ((L1<0)||(L2<0)) return 0;
	memset(f,0,sizeof(f));
	for (i=1;i<=50;i++)
	{
		W1[i]=(L1/mi[50-i])%2;
		W2[i]=(L2/mi[50-i])%2;
	}
	f[0][1][1]=1;
	for (i=1;i<=50;i++)
	{
		if (i==48)
		{
			gg=1;
		}
		for (s1=0;s1<=1;s1++)
		{
			for (s2=0;s2<=1;s2++)
			{
				if (s1==0) u1=1; else u1=W1[i];
				if (s2==0) u2=1; else u2=W2[i];
				for (t1=0;t1<=u1;t1++)
				{
					for (t2=0;t2<=u2;t2++)
					{
						if ((t1==1)&&(t2==1)) continue;
						if ((s1)&&(t1==W1[i])) S1=1; else S1=0;
						if ((s2)&&(t2==W2[i])) S2=1; else S2=0;
						f[i][S1][S2]+=f[i-1][s1][s2];
					}
				}
			}
		}
	}
	return f[50][0][0]+f[50][0][1]+f[50][1][0]+f[50][1][1];
}

int main()
{
//	freopen("read.in","r",stdin);
	scanf("%lld",&T);
	mi[0]=1;
	for (i=1;i<=50;i++) mi[i]=mi[i-1]*2;
	while (T--)
	{
		scanf("%lld%lld",&a,&b);
		ans=js(b,b)-js(b,a-1)-js(a-1,b)+js(a-1,a-1);
		printf("%lld\n",ans);
	}
}