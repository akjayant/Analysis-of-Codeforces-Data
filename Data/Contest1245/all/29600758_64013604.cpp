#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=2e3+10,M=N*N+5*N;
typedef pair<int,int> P;
typedef long long ll;
int n,c[N],k[N],par[2*N],cnt,num,x,y;
ll sum;
struct node{int x,y;}e[N];
int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
struct edge{int u,v;ll w;}f[M];
bool operator<(edge a,edge b){return a.w<b.w;}
ll cal(node a,node b){return abs(a.x-b.x)+abs(a.y-b.y);}
vector<int>ans;
vector<P>res;
void add(int u,int v,ll w){f[++cnt]=edge{u,v,w};}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&e[i].x,&e[i].y);
	for(int i=0;i<=n;++i)par[i]=i;
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%d",&k[i]);
	for(int i=1;i<=n;++i)add(0,i,c[i]);
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)add(i,j,1ll*(k[i]+k[j])*cal(e[i],e[j]));
	sort(f+1,f+cnt+1);
	for(int i=1;i<=cnt;++i)
	{
		x=find(f[i].u),y=find(f[i].v);
		if(x==y)continue;
		if(!f[i].u)ans.pb(f[i].v);
		else if(!f[i].v)ans.pb(f[i].u);
		else res.pb(P(f[i].u,f[i].v));
		num++,sum+=f[i].w;
		if(x<y)par[y]=x;else par[x]=y;
		if(num==n)break;	
	}
	printf("%I64d\n",sum);
	printf("%d\n",ans.size());
	for(auto v:ans)printf("%d ",v);puts("");
	printf("%d\n",res.size());
	for(auto v:res)printf("%d %d\n",v.fi,v.se);
	return 0;
}