#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define int long long
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
#define rg register
const int maxn=2e5+10;
int n,c[4][maxn],f[maxn][4][4],x,y,rt,w[maxn];
int in[maxn],cnt,pre[maxn*2],nxt[maxn*2],h[maxn];
void add(int x,int y){
    pre[++cnt]=y,nxt[cnt]=h[x],h[x]=cnt;
    pre[++cnt]=x,nxt[cnt]=h[y],h[y]=cnt;
}
void dfs(int x,int fa){
    for(rg int j=1;j<=3;j++)
	for(rg int k=1;k<=3;k++)
	    f[x][j][k]=c[j][x];
    for(rg int i=h[x];i;i=nxt[i])
	if(pre[i]!=fa){
	    dfs(pre[i],x);
	    f[x][1][2]+=f[pre[i]][2][3];
	    f[x][1][3]+=f[pre[i]][3][2];
	    f[x][2][1]+=f[pre[i]][1][3];
	    f[x][2][3]+=f[pre[i]][3][1];
	    f[x][3][1]+=f[pre[i]][1][2];
	    f[x][3][2]+=f[pre[i]][2][1];
	}
}
void solve(int x,int a,int b,int fa){
    w[x]=a;
    for(rg int i=h[x];i;i=nxt[i])
	if(pre[i]!=fa){
	    if(a==1&&b==2)solve(pre[i],b,3,x);
	    if(a==1&&b==3)solve(pre[i],b,2,x);
	    if(a==2&&b==1)solve(pre[i],b,3,x);
	    if(a==2&&b==3)solve(pre[i],b,1,x);
	    if(a==3&&b==2)solve(pre[i],b,1,x);
	    if(a==3&&b==1)solve(pre[i],b,2,x);
	}
}
signed main(){
    read(n);
    for(rg int j=1;j<=3;j++)
	for(rg int i=1;i<=n;i++)
	    read(c[j][i]);
    for(rg int i=1,u,v;i<n;i++)read(u),read(v),add(u,v),in[u]++,in[v]++;
    bool flag=0;
    for(rg int i=1;i<=n;i++)if(in[i]>2)flag=1;else if(in[i]==1)rt=i;
    if(flag)printf("-1\n");
    else {
	dfs(rt,0);int ans=2e18;
	for(rg int j=1;j<=3;j++)
	    for(rg int k=1;k<=3;k++)
		if(j!=k){
		    if(ans>f[rt][j][k])ans=f[rt][j][k],x=j,y=k;
		}
	printf("%lld\n",ans);
	solve(rt,x,y,0);
	for(rg int i=1;i<=n;i++)printf("%lld ",w[i]);
    }
}
