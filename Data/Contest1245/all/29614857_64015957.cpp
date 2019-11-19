#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20010,M=3e6+10;
int n,x[N],y[N],c[N],k[N],s,cnt,f[N],res;
int head[N<<1],w[M],to[M],nex[M],tot;
vector<int> v;
vector<pair<int,int> > g;
struct node{
	int u,v,w;
}t[M];
int cmp(node a,node b){return a.w<b.w;}
int dis(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
inline void add(int a,int b,int c){
	to[++tot]=b; nex[tot]=head[a]; w[tot]=c; head[a]=tot;
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
void mst(){
	for(int i=1;i<=n;i++)	f[i]=i;
	sort(t+1,t+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int fa=find(t[i].u); int fb=find(t[i].v);
		if(fa!=fb){
			f[fa]=fb;	res+=t[i].w;
			if(t[i].u==s||t[i].v==s) v.push_back(t[i].u+t[i].v);
			else	g.push_back({t[i].u,t[i].v});
		}
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)	scanf("%d %d",&x[i],&y[i]);
	for(int i=1;i<=n;i++)	scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)	scanf("%d",&k[i]);
	for(int i=1;i<=n;i++)	t[++cnt]={s,i,c[i]};
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)	t[++cnt]={i,j,(k[i]+k[j])*dis(i,j)};
	mst();
	cout<<res<<endl;
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)	cout<<v[i]<<' ';puts("");
	cout<<g.size()<<endl;
	for(int i=0;i<g.size();i++)	cout<<g[i].first<<' '<<g[i].second<<endl;
	return 0;
}

