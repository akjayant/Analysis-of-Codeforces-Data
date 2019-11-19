#include<bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x), i##END = (y); i <= i##END; ++i)
#define DOR(i, x, y) for(int i = (x), i##END = (y); i >= i##END; --i)
template<typename T, typename _T> inline bool chk_min(T &x, const _T y) {return y < x ? x = y, 1 : 0;}
template<typename T, typename _T> inline bool chk_max(T &x, const _T y) {return x < y ? x = y, 1 : 0;}
typedef long long ll;
const int N=100005;
template<const int N,const int M,typename T>struct LinkedList
{
	int head[N],nxt[M],tot;T to[M];
	LinkedList(){clear();}
	T &operator [](const int x){return to[x];}
	void clear(){memset(head,-1,sizeof(head)),tot=0;}
	void add(int u,T v){to[tot]=v,nxt[tot]=head[u],head[u]=tot++;}
	#define EOR(i,G,u) for(int i=G.head[u];~i;i=G.nxt[i])
};
LinkedList<N,N<<1,int>G;
ll dp[N][3][3];
int A[3][N];
int deg[N];
int rehsh[N],tot;
int Ans[N];
int n;

int backa[N][3][3];

void dfs(int u,int f)
{
	rehsh[++tot]=u;
	EOR(i,G,u)
	{
		int v=G[i];
		if(v==f)continue;
		dfs(v,u);
	}
}

void recur(int u,int i,int j)
{
	if(u==2)
	{
		Ans[rehsh[1]]=i,Ans[rehsh[2]]=j;
		return;
	}
	Ans[rehsh[u]]=j;
	recur(u-1,backa[u][i][j],i);
}

int main()
{
	scanf("%d",&n);
	FOR(k,0,2)FOR(i,1,n)scanf("%d",&A[k][i]);
	FOR(i,1,n-1)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G.add(u,v),G.add(v,u);
		deg[u]++,deg[v]++;
	}
	FOR(i,1,n)if(deg[i]>=3)
	{
		puts("-1");
		return 0;
	}
	FOR(i,1,n)if(deg[i]==1)
	{
		dfs(i,0);
		break;
	}
	FOR(k,0,n)FOR(i,0,2)FOR(j,0,2)if(i!=j)dp[k][i][j]=1e18;
	FOR(i,0,2)FOR(j,0,2)if(i!=j)dp[2][i][j]=A[i][rehsh[1]]+A[j][rehsh[2]];
	FOR(i,2,n-1)
	{
		FOR(j,0,2)FOR(k,0,2)FOR(l,0,2)
		{
			if(j==l||j==k||k==l)continue;
			if(chk_min(dp[i+1][k][l],dp[i][j][k]+A[l][rehsh[i+1]]))
			{
				backa[i+1][k][l]=j;
			}
		}
	}
	ll ans=1e18,I,J;
	FOR(i,0,2)FOR(j,0,2)if(i!=j)
	{
		if(chk_min(ans,dp[n][i][j]))
			I=i,J=j;
	}
	if(ans>1e17)puts("-1");
	else
	{
		printf("%lld\n",ans);
		recur(n,I,J);
		FOR(i,1,n)printf("%d%c",Ans[i]+1,(i==n?'\n':' '));
	}
	return 0;
}
