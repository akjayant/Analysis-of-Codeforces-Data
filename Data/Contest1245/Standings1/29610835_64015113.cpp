#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
using namespace std;
int n;
ll X[maxn],Y[maxn],c[maxn],k[maxn];
struct edge
{
	int u,v;
	ll w;
	edge(int U=0,int V=0,ll W=0):u(U),v(V),w(W){} 
}e[maxn*maxn];
int fa[maxn];
bool operator < (edge A,edge B){return A.w<B.w;}
int find(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
vector<int> A;
vector< pair<int,int> >B;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%I64d%I64d",&X[i],&Y[i]);
	for(int i=1;i<=n;++i)scanf("%I64d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%I64d",&k[i]);
	int cnt=0;
	for(int i=0;i<=n;++i)fa[i]=i;
	for(int i=1;i<=n;++i)e[++cnt]=edge(0,i,c[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(i!=j)e[++cnt]=edge(i,j,(k[i]+k[j])*(abs(X[i]-X[j])+abs(Y[i]-Y[j])));
	sort(e+1,e+cnt+1);
	ll ans=0;
	for(int i=1;i<=cnt;++i)
	{
		int u=e[i].u,v=e[i].v;
		if(find(u)==find(v))continue;
		fa[find(v)]=find(u);
		ans+=e[i].w;
		if(!u)A.push_back(v);
		else B.push_back(make_pair(u,v)); 
	}
	printf("%I64d\n",ans);
	printf("%d\n",A.size());
	for(auto p: A)printf("%d ",p);
	puts("");
	printf("%d\n",B.size());
	for(auto p: B)printf("%d %d\n",p.first,p.second);
	
}