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
const int maxn=222222;
const LL oo=1000000ll*1000000*1000000;
int tot,A[maxn],B[maxn],C[maxn],tmp[maxn],id[3]={1,2,3},fir[maxn],nxt[maxn],to[maxn],D[maxn],col[maxn];
//-------------------------------------------------------------------hanshu↓
void dfs(int x,int y)
{
	tmp[++tot]=x;
	for(int i=fir[x];i;i=nxt[i])if(to[i]!=y) dfs(to[i],x);
}
void add_edge(int x,int y)
{
	nxt[++tot]=fir[x],to[fir[x]=tot]=y;
}
//-------------------------------------------------------------------main()↓
int main()
{
	int N=rd();
	for(int i=1;i<=N;++i) A[i]=rd();
	for(int i=1;i<=N;++i) B[i]=rd();
	for(int i=1;i<=N;++i) C[i]=rd();
	for(int i=1;i<N;++i)
	{
		int a=rd(),b=rd();
		add_edge(a,b),add_edge(b,a);
		++D[a],++D[b];
	}
	for(int i=1;i<=N;++i)if(D[i]>2)
	{
		puts("-1");
		return 0;
	}
	int sta=0;
	for(int i=1;i<=N;++i)if(D[i]==1) sta=i;
	tot=0;dfs(sta,0);
	LL Ans=oo;
	do{
		LL ans=0;
		for(int i=1;i<=N;++i)
		{
			switch(id[i%3])
			{
				case 1:ans+=A[tmp[i]];break;
				case 2:ans+=B[tmp[i]];break;
				case 3:ans+=C[tmp[i]];break;
			}
		}
		if(ans<Ans)
		{
			Ans=ans;
			for(int i=1;i<=N;++i) col[tmp[i]]=id[i%3];
		}
	}while(next_permutation(id,id+3));
	WTL(Ans),puts("");
	for(int i=1;i<=N;++i) WT(col[i]),putchar(32);
	return 0;
}