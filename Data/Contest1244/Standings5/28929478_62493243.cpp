#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
const int maxm=25;
const ll inf=1e18;
vector<int> e[maxn];
int dis[6]={3,5,1,
			4,0,2};
ll ans[maxn][maxm],cal[maxm][maxn],c[maxn];
int u,v,n;
void solve(int ok,int s);
void solve1(int u,int fa);
void solve2(int u,int fa,int val);
void add(int u,int v);
void init(int u);
void add_v(int u,int v);
int main()
{
	scanf("%d",&n);
	int ok=1,s=1;
	for(int i=0;i<3;i++)for(int j=1;j<=n;j++)scanf("%lld",&cal[i][j]);
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d%d",&u,&v);add(u,v);
	}
	solve(ok,s);
}
void solve(int ok,int s)
{
	if(n==1)
	{
		ll res=min(cal[0][1],min(cal[1][1],cal[2][1]));printf("%lld\n",res);
		for(int i=0;i<3;i++)if(cal[i][1]==res){printf("%d\n",i+1);return;}
	}
	for(int i=1;i<=n;i++)
	{
		if(e[i].size()>=3) ok=0;if(e[i].size()==1) s=i;
	}
	if(ok==0)
	{
		printf("-1\n");return;
	}	
	solve1(s,0);ll res=inf,x=0;
	for(int i=0;i<6;i++)if(res>ans[s][i]) res=ans[s][i],x=i;
	printf("%lld\n",res);solve2(s,0,x);for(int i=1;i<=n;i++) printf("%lld%c",c[i]+1,(i==n)?'\n':' ');
}
void solve2(int u,int fa,int val)
{
	c[u]=val/2;int sz=e[u].size();
	for(int i=0;i<sz;i++)
	{
		int v=e[u][i];
		if(v==fa) continue;
		solve2(v,u,dis[val]);
	}
}
void solve1(int u,int fa)
{
	init(u);
	int sz=e[u].size();
	for(int i=0;i<sz;i++)
	{
		int v=e[u][i];
		if(v==fa) continue;
		solve1(v,u);
		add_v(u,v);
	}
}
void init(int u)
{
	ans[u][0]=ans[u][1]=cal[0][u];ans[u][2]=ans[u][3]=cal[1][u];ans[u][4]=ans[u][5]=cal[2][u];
}
void add_v(int u,int v)
{
	ans[u][0]+=ans[v][3];ans[u][1]+=ans[v][5];ans[u][2]+=ans[v][1];ans[u][3]+=ans[v][4];ans[u][4]+=ans[v][0];ans[u][5]+=ans[v][2];
}
void add(int u,int v)
{
	e[u].push_back(v);e[v].push_back(u);
}