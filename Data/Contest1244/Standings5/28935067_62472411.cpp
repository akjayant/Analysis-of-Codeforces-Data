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
char ss[1111];
//-------------------------------------------------------------------hanshu↓
//-------------------------------------------------------------------main()↓
int main()
{
	int T=rd();
	while(T--)
	{
		int N=rd();
		scanf("%s",ss+1);
		int op=0;
		for(int i=1;i<=N;++i)if(ss[i]==49) op=i;
		if(!op)
		{
			WT(N),puts("");
			continue;
		}
		int ans=op<<1;
		op=0;
		for(int i=N;i;--i)if(ss[i]==49) op=i;
		ans=max(ans,(N-op+1)<<1);
		WT(ans),puts("");
	}
	return 0;
}