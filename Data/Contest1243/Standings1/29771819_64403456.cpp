#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 100005
int n,m,fa[N*5],id[N]; bool vis[N*5],ve[N*5];
int rt,u,s[N*5],lc[N*5],rc[N*5];
vector <int> g[N];

int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void uni(int x,int y){
	int r1=find(x),r2=find(y);
	if(r1!=r2) fa[r1]=r2;
}
#define mid (l+r)/2
int build(int l,int r){
	int nw=++u;
	fa[nw]=nw;
	if(l==r){id[l]=nw; return nw;}
	lc[nw]=build(l,mid);
	rc[nw]=build(mid+1,r);
	return nw;
}
void link(int o,int l,int r,int x1,int x2,int k){
	if(x1<=l&&r<=x2){vis[o]=1; uni(o,k); return ;}
	if(x1<=mid) link(lc[o],l,mid,x1,x2,k);
	if(x2>mid) link(rc[o],mid+1,r,x1,x2,k);
}
void tree_uni(int o,int l,int r){
	if(vis[o]) for(int i=l;i<=r;++i) uni(o,id[i]);
	if(l==r) return ;
	tree_uni(lc[o],l,mid); tree_uni(rc[o],mid+1,r);
}
void Link(int I,int l,int r){
	link(rt,1,n,l,r,id[I]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,U,V;i<=m;++i){
		scanf("%d%d",&U,&V);
		g[U].push_back(V);
		g[V].push_back(U);
	}
	rt=build(1,n);
	for(int i=1;i<=n;++i){
		g[i].push_back(i);
		sort(g[i].begin(),g[i].end());
		int len=g[i].size();
		for(int j=0;j<len-1;++j){
			int l=g[i][j],r=g[i][j+1];
			if(l+1<r) Link(i,l+1,r-1);
		}
		if(1<g[i][0]) Link(i,1,g[i][0]-1);
		if(g[i][len-1]<n) Link(i,g[i][len-1]+1,n);
	}
	tree_uni(rt,1,n);
	int tot=0;
	for(int i=1;i<=n;++i){
		int Fa=find(id[i]);
		if(!ve[Fa]) ve[Fa]=1,++tot;
	}
	printf("%d",tot-1);
	return 0;
}
