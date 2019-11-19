#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define lowbit(x) ((x)&(-x))
using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const LL INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=2010;
int n,x[MAXN],y[MAXN],fa[MAXN];
LL g[MAXN][MAXN],c[MAXN],k[MAXN],cnt,gra;
struct EDGE{
	int u,v;
	LL w;
}edge[2*MAXN*MAXN];
vector<int> ans1;
vector<pair<int,int> > ans2;

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

bool cmp(EDGE a,EDGE b){return a.w<b.w;}

int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}

int main(){
	n=read();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	for(int i=1;i<=n;i++) c[i]=read(),edge[++cnt]={0,i,c[i]};
	for(int i=1;i<=n;i++) k[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			LL w=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
			edge[++cnt]={i,j,w};
		}
	sort(edge+1,edge+cnt+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	memset(g,0x3f,sizeof(g));
	LL sum=0;
	for(int i=1;i<=cnt;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fau=findfa(u),fav=findfa(v);
		if(fau==fav) continue;
		sum+=w;
		g[u][v]=w,g[v][u]=w;
		if(u==0) ans1.push_back(v);
		else ans2.push_back({u,v});
		if(fau<fav) fa[fav]=fau;
		else fa[fau]=fav;
	}
	printf("%lld\n",sum);
	printf("%d\n",ans1.size());
	for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]);printf("\n");
	printf("%d\n",ans2.size());
	for(int i=0;i<ans2.size();i++) printf("%d %d\n",ans2[i].first,ans2[i].second);
	return 0;
}