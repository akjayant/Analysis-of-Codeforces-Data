#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long LL;
typedef unsigned int uint;
typedef pair<int,int> pii;
//-------------------------------------------------------------------LYYY↓
namespace LYYY{
	int rd()
	{
		int s=0;char c=getchar();int f=1;
		while(c<48||c>57)
		{
			if(c==45) f=-1;
			c=getchar();
		}
		while(c>=48&&c<=57) s=(s<<3)+(s<<1)+(c^48),c=getchar();
		return s*f;
	}
	LL rdl()
	{
		LL s=0;char c=getchar();int f=1;
		while(c<48||c>57)
		{
			if(c==45) f=-1;
			c=getchar();
		}
		while(c>=48&&c<=57) s=(s<<3)+(s<<1)+(c^48),c=getchar();
		return s*f;
	}
	void wt(int x)
	{
		if(x>=10) wt(x/10);
		putchar(x%10+48);
	}
	void WT(int x)
	{
		if(x<0) x=-x,putchar(45);
		wt(x);
	}
	void wtl(LL x)
	{
		if(x>=10) wtl(x/10);
		putchar(x%10+48);
	}
	void WTL(LL x)
	{
		if(x<0) x=-x,putchar(45);
		wtl(x);
	}
}using namespace LYYY;
//-------------------------------------------------------------------bianliang↓
int A[3330][333];
//-------------------------------------------------------------------hanshu↓
//-------------------------------------------------------------------main()↓
int main()
{
	int N=rd(),M=N/2,tot=0;
	for(int i=1;i<=M;++i)for(int j=1;j<=N;++j) A[j][i]=++tot;
	for(int i=M+1;i<=N;++i)for(int j=N;j;--j) A[j][i]=++tot;
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j) WT(A[i][j]),putchar(32);
		puts("");
	}
//	int ans=0;
//	for(int i=2;i<=M;++i) ans+=i-1;
//	for(int i=M+1;i<=N;++i) ans+=i;
//	printf("%d %d",N*N,ans);
	return 0;
}