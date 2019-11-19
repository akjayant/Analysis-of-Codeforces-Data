#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
typedef long long ll;
const int maxn=2005;
struct point{
	int x,y;
	point(int x=0,int y=0):x(x),y(y){}
}p[maxn];
struct edge{
	int u,v;ll w;
	bool operator <(const edge &d)const{
		return w<d.w;
	}
}e[maxn*maxn],Ans[maxn*maxn];
int n,c[maxn],cnt;
ll k[maxn];
int prt[maxn];
int getf(int x){return prt[x]==x?x:prt[x]=getf(prt[x]);}
struct Edge{
	int to,next;
}E[maxn*maxn];
int scc,vis[maxn];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		int x=read(),y=read();
		p[i]=point(x,y);
	}
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)k[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			ll w=abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
			w=w*(k[i]+k[j]);
			e[++cnt]=(edge){i,j,w};
		}
	for(int i=1;i<=n;i++)e[++cnt]=(edge){n+1,i,c[i]};
	sort(e+1,e+1+cnt);
	int tot=0;ll ans=0;
	for(int i=1;i<=n+1;i++)prt[i]=i;
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v;
		int f1=getf(u),f2=getf(v);
		if(f1!=f2){
			prt[f1]=f2;
			if(u==n+1){
				scc++;
				vis[scc]=v;
			}else Ans[++tot]=(edge){u,v,0};
			ans+=e[i].w;
		}
	}
	cout<<ans<<'\n';
	cout<<scc<<'\n';
	for(int i=1;i<=scc;i++)cout<<vis[i]<<' ';cout<<'\n';
	cout<<tot<<'\n';
	for(int i=1;i<=tot;i++)cout<<Ans[i].u<<' '<<Ans[i].v<<'\n';
	return 0;
}
