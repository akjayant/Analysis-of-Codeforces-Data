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
const int maxn=111111;
const int INF=2000000000;
int N,M,K;
pii A[maxn],B[maxn],C[maxn],D[maxn];
//-------------------------------------------------------------------hanshu↓
pii Get(int a,int b,int TO,int l1,int r1,int l2,int r2)
{
	if(TO==1)
	{
		pii op=(*lower_bound(A+1,A+1+K,mp(a,b)));
		if(op.first!=a||op.second>r2) return mp(0,0);
		return op;
	}
	if(TO==2)
	{
		pii op=(*lower_bound(B+1,B+1+K,mp(b,a)));
		if(op.first!=b||op.second>r1) return mp(0,0);
		return mp(op.second,op.first);
	}
	if(TO==3)
	{
		pii op=(*lower_bound(C+1,C+1+K,mp(a,-b)));
		op.second*=-1;
//		printf("----%d %d\n",op.first,op.second);
		if(op.first!=a||op.second<l2) return mp(0,0);
		return op;
	}
	if(TO==4)
	{
		pii op=(*lower_bound(D+1,D+1+K,mp(b,-a)));
		op.second*=-1;
		if(op.first!=b||op.second<l1) return mp(0,0);
		return mp(op.second,op.first);
	}
	return mp(0,0);
}
bool all_colored(int l1,int r1,int l2,int r2)
{
	for(int i=l1;i<=r1;++i)for(int j=l2;j<=r2;++j)if(Get(i,j,1,l1,r1,l2,r2)!=mp(i,j)) return false;
	return true;
}
bool dfs(int a,int b,int TO,int l1,int r1,int l2,int r2)
{
//	printf("%d %d %d %d %d %d %d\n",a,b,TO,l1,r1,l2,r2);
	if(a<l1||a>r1||b<l2||b>r2) return true;
	if((*lower_bound(A+1,A+1+K,mp(a,b)))==mp(a,b)) return all_colored(l1,r1,l2,r2);
	pii Nw=Get(a,b,TO,l1,r1,l2,r2);
//	printf("%d %d\n",Nw.first,Nw.second);
	if(!Nw.first)
	{
		if(TO==1) return dfs(l1+1,r2,2,l1+1,r1,l2,r2);
		if(TO==2) return dfs(r1,r2-1,3,l1,r1,l2,r2-1);
		if(TO==3) return dfs(r1-1,l2,4,l1,r1-1,l2,r2);
		if(TO==4) return dfs(l1,l2+1,1,l1,r1,l2+1,r2);
	}
	else
	{
		if(TO==1) return all_colored(l1,r1,Nw.second,r2)&&dfs(l1+1,Nw.second-1,2,l1+1,r1,l2,Nw.second-1);
		if(TO==2) return all_colored(Nw.first,r1,l2,r2)&&dfs(Nw.first-1,r2-1,3,l1,Nw.first-1,l2,r2-1);
		if(TO==3) return all_colored(l1,r1,l2,Nw.second)&&dfs(r1-1,Nw.second+1,4,l1,r1-1,Nw.second+1,r2);
		if(TO==4) return all_colored(l1,Nw.first,l2,r2)&&dfs(Nw.first+1,l2+1,1,Nw.first+1,r1,l2+1,r2);
	}
	return false;
}
//-------------------------------------------------------------------main()↓
int main()
{
	N=rd(),M=rd(),K=rd();
	for(int i=1;i<=K;++i)
	{
		int a,b;scanf("%d%d",&a,&b);
		A[i]=mp(a,b),B[i]=mp(b,a);
		C[i]=mp(a,-b),D[i]=mp(b,-a);
	}++K;
	A[K]=B[K]=C[K]=D[K]=mp(INF,INF);
	sort(A+1,A+1+K);
	sort(B+1,B+1+K);
	sort(C+1,C+1+K);
	sort(D+1,D+1+K);
	puts(dfs(1,1,1,1,N,1,M)?"Yes":"No");
}