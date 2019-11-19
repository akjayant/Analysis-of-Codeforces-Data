#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=2003;

int x[maxn],y[maxn],c[maxn],k[maxn],m,fa[maxn],n;

int fnd(int x){
	return fa[x]==x?x:fa[x]=fnd(fa[x]);
}

struct EDGE{
	int u,v;ll w;
}e[maxn*maxn];
bool cmp(EDGE x,EDGE y){
	return x.w<y.w;
}
vector<int> P;
vector<pair<int,int> > E; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%d",&k[i]);
	for(int i=1;i<=n;++i){
		e[++m].u=0;e[m].v=i;e[m].w=c[i];
		for(int j=1;j<=n;++j)
			e[++m].u=i,e[m].v=j,e[m].w=ll(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
	}
	sort(e+1,e+m+1,cmp);
	for(int i=0;i<=n;++i)fa[i]=i;
	ll res=0;int t=0;
	for(int i=1;i<=m;++i){
		if(fnd(e[i].u)!=fnd(e[i].v)){
			++t;res+=e[i].w;
			if(e[i].u==0)P.push_back(e[i].v);
			else E.push_back(make_pair(e[i].u,e[i].v));
			fa[fnd(e[i].u)]=fnd(e[i].v);
			if(t==n)break;
		}
	}
	printf("%I64d\n",res);
	printf("%d\n",(int)P.size());
	for(int i=0;i<P.size();++i)
		printf("%d ",P[i]);
	puts("");
	printf("%d\n",(int)E.size());
	for(int i=0;i<E.size();++i)
		printf("%d %d\n",E[i].first,E[i].second);
	return 0;
}
 