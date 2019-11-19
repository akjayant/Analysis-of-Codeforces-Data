#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20010,M=3e6+10;
int n,x[N],y[N],c[N],k[N],s,cnt,f[N],res;
int head[N<<1],w[M],to[M],nex[M],tot;
vector<int> g1;
vector< pair<int,int> > g;
struct node{
	int u,v,w;
}t[M];
struct Node{
	int op,x;
}q[N];
struct seg{
	int l,r,s;
}ti[N<<2];
void build(int p,int l,int r){
	ti[p].l=l; ti[p].r=r;
	if(l==r)	return ; int mid=l+r>>1;
	build(p<<1,l,mid);	build(p<<1|1,mid+1,r);
}
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
void MST(){
	for(int i=1;i<=n;i++)	f[i]=i;
	sort(t+1,t+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		int fa=find(t[i].u); int fb=find(t[i].v);
		if(fa!=fb){
			f[fa]=fb;	res+=t[i].w;
			if(t[i].u==s||t[i].v==s) g1.push_back(t[i].u+t[i].v);
			else	g.push_back({t[i].u,t[i].v});
		}
	}
}
const int maxn=1e4;
int bit[maxn];
#define lowbit(x) x&(-x)
bool check(char x,char y,char z)
{
    return x=='w'&&y=='b'&&z=='w';
}
int sum(int i)
{
    int res=0;
    while(i){
        res+=bit[i];
        i-=lowbit(i);
    }
    return res;
}
void update(int i,int x)
{
    while(i<=n){
        bit[i]+=x;
        i+=lowbit(i);
    }
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)	
	cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)	
	cin>>c[i];
	for(int i=1;i<=n;i++)	
	cin>>k[i];
	for(int i=1;i<=n;i++)	
	t[++cnt]={s,i,c[i]};
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)	
		t[++cnt]={i,j,(k[i]+k[j])*dis(i,j)};
	MST();
	cout<<res<<'\n';
	cout<<g1.size()<<'\n';
	for(int i=0;i<g1.size();i++)	
	cout<<g1[i]<<' ';puts("");
	cout<<g.size()<<'\n';
	for(int i=0;i<g.size();i++)	
	cout<<g[i].first<<' '<<g[i].second<<'\n';
	return 0;
}
