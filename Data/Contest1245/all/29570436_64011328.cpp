#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
#define int long long 
typedef pair<int,int> pii;
#define X first
#define Y second
int n;
int x[N],y[N],c[N],d[N];
int fa[N],b[N*N+N];
inline int findf(int x){
	return x==fa[x]?x:fa[x]=findf(fa[x]);
}
struct edge{
	int u,v,w;
}e[N*N+N];
inline bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++) x[i]=read(),y[i]=read();
	int m=0;
	for(int i=1;i<=n;i++) {
		c[i]=read(),fa[i]=i;
		e[++m]={0,i,c[i]};
	}
	for(int i=1;i<=n;i++) d[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			e[++m]={i,j,(d[i]+d[j])*((abs(x[i]-x[j])+abs(y[i]-y[j])))};
		}
	sort(e+1,e+m+1,cmp);
	int ans=0,cnt1=0,cnt2=0;
	for(int i=1;i<=m;i++){
		int fx=findf(e[i].u),fy=findf(e[i].v);
		if(fx==fy) continue;
		b[i]=1;
		if(e[i].u==0) cnt1++;
		else cnt2++;
		ans+=e[i].w;
		fa[fx]=fy;
	}
	printf("%lld\n",ans);
	printf("%lld\n",cnt1);
	for(int i=1;i<=m;i++) if(b[i]&&e[i].u==0) printf("%lld ",e[i].v);
	printf("\n%lld\n",cnt2);
	for(int i=1;i<=m;i++) if(b[i]&&e[i].u!=0) printf("%lld %lld\n",e[i].u,e[i].v);
	return 0;
} 