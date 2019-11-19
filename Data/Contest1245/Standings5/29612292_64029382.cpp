#include<bits/stdc++.h>
using namespace std;const int N=2e3+7,M=N*N;typedef long long ll;typedef pair<int,int>pa;
struct data{
	int u,v;ll w;
	friend bool operator<(data a,data b){return a.w<b.w;}
}s[M];int n,m,i,j,tot,fa[N],c[N],k[N],x[N],y[N];vector<int>d;vector<pa>q;ll ans;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(){
	for(scanf("%d",&n),i=1;i<=n;++i)scanf("%d%d",x+i,y+i),fa[i]=i;
	for(i=1;i<=n;++i)scanf("%d",c+i);
	for(i=1;i<=n;++i)scanf("%d",k+i);
	for(i=1;i<=n;++i)for(j=i+1;j<=n;++j)s[++tot]=data{i,j,1LL*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))};
	for(i=1;i<=n;++i)s[++tot]=data{0,i,1LL*c[i]};
	sort(s+1,s+tot+1);
	for(i=1;i<=tot;++i)if(find(s[i].u)!=find(s[i].v)){
		ans+=s[i].w;
		if(s[i].u==0)d.push_back(s[i].v);else q.push_back(pa(s[i].u,s[i].v));
		fa[find(s[i].u)]=find(s[i].v);
	}printf("%I64d\n",ans);
	printf("%d\n",(int)d.size());
	for(auto&x:d)printf("%d ",x);puts("");
	printf("%d\n",(int)q.size());
	for(auto&x:q)printf("%d %d\n",x.first,x.second);puts("");
}