#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,ans,e,tot,x[2222],y[2222],root[2222],c[2222],k[2222],res[2222],u[4444444],v[4444444];
struct lmz{int u,v,w;}q[4444444];
int ROOT(int a){return root[a]==a?a:root[a]=ROOT(root[a]);}
bool cmp(lmz a,lmz b){return a.w<b.w;}
signed main(){
	scanf("%I64d",&n),root[n+1]=n+1;
	for(int i=1;i<=n;i++)scanf("%I64d%I64d",&x[i],&y[i]),root[i]=i;
	for(int i=1;i<=n;i++)scanf("%I64d",&c[i]);
	for(int i=1;i<=n;i++)scanf("%I64d",&k[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j){
		int w=1ll*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]);
		q[++cnt].u=i,q[cnt].v=j,q[cnt].w=w;
	}
	for(int i=1;i<=n;i++)q[++cnt].u=n+1,q[cnt].v=i,q[cnt].w=c[i];
	sort(q+1,q+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int ru=ROOT(q[i].u),rv=ROOT(q[i].v);
		if(ru!=rv){
			root[rv]=ru,ans+=q[i].w;
			if(q[i].u==n+1)res[++tot]=q[i].v;
			else u[++e]=q[i].u,v[e]=q[i].v;
		}
	}
	printf("%I64d\n%I64d\n",ans,tot),sort(res+1,res+tot+1);
	for(int i=1;i<=tot;i++)printf("%I64d ",res[i]);
	printf("\n%I64d\n",e);
	for(int i=1;i<=e;i++)printf("%I64d %I64d\n",u[i],v[i]);
}