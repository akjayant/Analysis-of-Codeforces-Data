#include<bits/stdc++.h>
#define MAXN 100010
#define mp make_pair
#define fir first
#define sec second
using namespace std;
typedef long long ll;
typedef pair<int,int> par;
inline int read ()
{
	int s=0,w=1;
	char ch=getchar ();
	while (ch<'0'||ch>'9'){if (ch=='-') w=-1;ch=getchar ();}
	while ('0'<=ch&&ch<='9') s=(s<<1)+(s<<3)+(ch^48),ch=getchar ();
	return s*w;
}
struct edge{
	int v,nxt;
}e[MAXN<<1];
int n,cnt;
int c[3][MAXN],head[MAXN],deg[MAXN],nxt[MAXN];
ll dp[MAXN][4][4],Ans[MAXN];
par pre[MAXN][4][4];
void add (int u,int v)
{
	e[++cnt].v=v,e[cnt].nxt=head[u],head[u]=cnt;
}
void dfs (int u,int ff)
{
	int v=0;
	for (int i=head[u];i!=0;i=e[i].nxt)
		if (e[i].v!=ff){v=e[i].v;break;}
	if (!v)
	{
		dp[u][0][3]=c[0][u],pre[u][0][3]=mp (0,3);
		dp[u][1][3]=c[1][u],pre[u][1][3]=mp (1,3);
		dp[u][2][3]=c[2][u],pre[u][2][3]=mp (2,3);
		return;
	}
	nxt[u]=v;
	dfs (v,u);
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if (i!=j)
				for (int k=0;k<4;k++)
					if (i!=k&&j!=k)
						if (dp[v][j][k]!=-1)
						{
							if (dp[u][i][j]==-1) dp[u][i][j]=1e18;
							if (dp[u][i][j]>dp[v][j][k]+c[i][u])
							{
								dp[u][i][j]=dp[v][j][k]+c[i][u];
								pre[u][i][j]=mp (j,k);
							}
						}
}
int main()
{
	memset (dp,-1,sizeof (dp));
	n=read ();
	for (int i=1;i<=n;i++) c[0][i]=read ();
	for (int i=1;i<=n;i++) c[1][i]=read ();
	for (int i=1;i<=n;i++) c[2][i]=read ();
	for (int i=1;i<n;i++)
	{
		int u=read (),v=read ();
		add (u,v),add (v,u),deg[u]++,deg[v]++;
		if (deg[u]>2||deg[v]>2) return puts ("-1"),0;
	}
	int s=0;
	for (int i=1;i<=n;i++) if (deg[i]==1){s=i;break;}
	dfs (s,0);
	ll ans=1e18;
	int p1=0,p2=0;
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if (i!=j)
				if (ans>dp[s][i][j]) ans=dp[s][i][j],p1=i,p2=j;
	int x=s;
	while (x)
	{
		Ans[x]=p1;
//		cout<<"HA: "<<x<<" "<<p1<<endl;
		int t1=p1,t2=p2;
		p1=pre[x][t1][t2].fir,p2=pre[x][t1][t2].sec;
		x=nxt[x];
	}
	printf ("%lld\n",ans);
	for (int i=1;i<=n;i++) printf ("%d ",Ans[i]+1);
	return 0;
}
