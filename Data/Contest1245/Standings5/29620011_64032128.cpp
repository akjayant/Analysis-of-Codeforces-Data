#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
struct Edge
{
	int pre,u;
	ll d;
	bool b;
	Edge(int pre,int u,ll d,bool b):pre(pre),u(u),d(d),b(b){}
	bool operator < (const Edge E)const
	{
		return d>E.d;
	}
};
struct Node
{
	int x,y;
}n[2010];
struct Edges
{
	int u,v;
	Edges(int u,int v):u(u),v(v){}
};
int N,c[2010],k[2010],Min=1e9+7,mk;
ll f[2010][2010],ans=0;
vector<int> ans1;
vector<Edges> ans2;
void solve()
{
	priority_queue<Edge> q;
	int cnt=0;
	bool vis[2010];memset(vis,false,sizeof vis);
	q.push(Edge(0,mk,c[mk],1));
	while(!q.empty())
	{
		Edge e=q.top();q.pop();
		int u=e.u;
		if(vis[u]) continue;
		else vis[u]=true;
		if(e.b) ans1.push_back(u);
		else ans2.push_back(Edges(e.pre,e.u));
		ans+=e.d;cnt++;
		for(int i=1;i<=N;i++)
		{
			if(!vis[i])
			{
				if(f[u][i]<c[i]) q.push(Edge(u,i,f[u][i],0));
				else q.push(Edge(u,i,c[i],1));
			}
		}
		if(cnt==N) break;
	}
	int len1=ans1.size(),len2=ans2.size();
	printf("%lld\n",ans);
	printf("%d\n",len1);
	for(int i=0;i<len1;i++)
		printf("%d ",ans1[i]);
	printf("\n");
	printf("%d\n",len2);
	for(int i=0;i<len2;i++)
		printf("%d %d\n",ans2[i].u,ans2[i].v);
}
int dist(Node x,Node y)
{
	return abs(x.x-y.x)+abs(x.y-y.y);
}
int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d%d",&n[i].x,&n[i].y);
	for(int i=1;i<=N;i++){scanf("%d",&c[i]);if(c[i]<Min){Min=c[i];mk=i;} }
	for(int i=1;i<=N;i++) scanf("%d",&k[i]);
	for(int i=1;i<=N;i++)
		for(int j=i+1;j<=N;j++)
			f[i][j]=f[j][i]=dist(n[i],n[j])*(ll)(k[i]+k[j]);

	solve();
}