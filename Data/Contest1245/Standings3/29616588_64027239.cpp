#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;

namespace dsu{
	int fa[maxn];
	void init(int k) {for(int i=0;i<=k;i++) fa[i]=i;}
	int fin(int k) {return fa[k]==k?k:(fa[k]=fin(fa[k]));}
	bool unite(int a,int b){
		int x=fin(a),y=fin(b);
		if(x==y) return false;
		fa[x]=y;
		return true;
	}
	bool same(int a,int b) {return fin(a)==fin(b);}
}
using namespace dsu;

long long c[maxn],k[maxn];
int x[maxn],y[maxn],n,tot;
struct edge{
	int x,y;
	long long w;
	friend bool operator<(const edge&a,const edge&b) {
		return a.w<b.w;
	}
}e[maxn*maxn*2];
void add_edge(int x,int y,long long w) {
	e[++tot]=edge{x,y,w};
}
int dis(int i,int j) {
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int que[maxn],cntq=0,ansx[maxn],ansy[maxn],cntx=0;
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&k[i]);
	init(n);
	for(int i=1;i<=n;i++) add_edge(i,i,c[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) add_edge(i,j,1LL*(k[i]+k[j])*dis(i,j));
	sort(e+1,e+tot+1);

	long long ans=0;
	for(int i=1;i<=tot;i++) {
		if(e[i].x==e[i].y) {
			if(unite(0,e[i].x)){
				ans+=e[i].w;
				que[++cntq]=e[i].x;
			}
		}else {
			if(unite(e[i].x,e[i].y)){
				ans+=e[i].w;
				ansx[++cntx]=e[i].x;
				ansy[cntx]=e[i].y;
			}
		}
	}
	printf("%lld\n",ans);
	printf("%d\n",cntq);
	for(int i=1;i<=cntq;i++) {
		printf("%d%c",que[i],i==cntq?'\n':' ');
	}
	printf("%d\n",cntx);
	for(int i=1;i<=cntx;i++) printf("%d %d\n",ansx[i],ansy[i]);

}