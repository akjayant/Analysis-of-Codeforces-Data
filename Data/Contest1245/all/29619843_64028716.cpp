#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 2010
#define int long long
#define rnt register int
using namespace std;
vector <int> V1;
vector <pair<int,int> > V2;
struct edge{int f,t,l;}e[N*N*2];
int n,cnt,ans,fa[N],X[N],Y[N],K[N],C[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline bool cmp(edge a,edge b){return a.l<b.l;}
signed main(){
	scanf("%I64d",&n);fa[n+1]=n+1;
	for(rnt i=1;i<=n;i=-~i)	scanf("%I64d%I64d",&X[i],&Y[i]),fa[i]=i;
	for(rnt i=1;i<=n;i=-~i){
		scanf("%I64d",&C[i]);
		cnt=-~cnt;
		e[cnt].f=i,e[cnt].t=n+1;
		e[cnt].l=C[i];
	}
	for(rnt i=1;i<=n;i=-~i){
		scanf("%I64d",&K[i]);
		for(rnt j=1;j<i;j=-~j){
			cnt=-~cnt;
			e[cnt].f=j,e[cnt].t=i;
			e[cnt].l=(abs(X[i]-X[j])+abs(Y[i]-Y[j]))*(K[i]+K[j]);
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(rnt i=1;i<=cnt;i=-~i){
		int x=find(e[i].f),y=find(e[i].t);
		if(x!=y){
			if(e[i].f==n+1) V1.push_back(e[i].t);
			else if(e[i].t==n+1) V1.push_back(e[i].f);
			else V2.push_back(make_pair(e[i].f,e[i].t));
			fa[x]=y;
			ans+=e[i].l;
		}
	}
	printf("%I64d\n%I64d\n",ans,(int)V1.size());
	for(rnt i=0;i<(int)V1.size();i=-~i) printf("%I64d ",V1[i]);
	printf("\n%I64d\n",(int)V2.size());
	for(rnt i=0;i<(int)V2.size();i=-~i) printf("%I64d %I64d\n",V2[i].first,V2[i].second);
	return 0;
}
