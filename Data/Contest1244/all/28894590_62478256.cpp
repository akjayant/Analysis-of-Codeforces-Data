#include<bits/stdc++.h>
inline int read(){
	int x=0,w=1;
	char ch=0;
	while (ch<'0' || ch>'9'){
		ch=getchar();
		if (ch=='-') w=-1;	
	}
	while (ch<='9' && ch>='0'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*w;
}
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct edge{
	int next,to;
}a[N<<1];
int head[N],cnt;
inline void add(int u,int v){
	a[++cnt].to=v;
	a[cnt].next=head[u];
	head[u]=cnt;
}
int n,rt;
int deg[N],w[N][3];
int p[N];
ll ans,dp[N][3][3];
int pre[N][3][3],col[N];
const ll inf=(ll)1e18;
void dfs(int x,int fa,int dep){
	p[dep]=x;
	for (int i=head[x];i;i=a[i].next)
		if (a[i].to!=fa) dfs(a[i].to,x,dep+1);
}
void print(int pos,int x,int y){
	if (pos==2) return (void)(col[p[1]]=x+1,col[p[2]]=y+1);
	col[p[pos]]=y+1;
	print(pos-1,pre[pos][x][y],x);
}
int main(){
	//freopen("a.in","r",stdin);
	n=read();
	for (int i=1;i<=n;++i) w[i][0]=read();
	for (int i=1;i<=n;++i) w[i][1]=read();
	for (int i=1;i<=n;++i) w[i][2]=read();
	for (int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
		++deg[u],++deg[v];
	}
	for (int i=1;i<=n;++i)
		if (deg[i]>=3) return puts("-1"),0;
		else if (deg[i]==1) rt=i;
	dfs(rt,0,1);
	for (int i=0;i<3;++i)
		for (int j=0;j<3;++j)
			if (i!=j) dp[2][i][j]=w[p[1]][i]+w[p[2]][j];
	for (int x=3;x<=n;++x){
		for (int i=0;i<3;++i)
			for (int j=0;j<3;++j)
				dp[x][i][j]=inf;
		for (int i=0;i<3;++i)
			for (int j=0;j<3;++j)
				for (int k=0;k<3;++k)
					if (i!=j && j!=k && i!=k){
						if (dp[x][j][k]>dp[x-1][i][j]+w[p[x]][k]){
							dp[x][j][k]=dp[x-1][i][j]+w[p[x]][k];
							pre[x][j][k]=i;
						}
					}
	}
	ans=inf;
	for (int i=0;i<3;++i)
		for (int j=0;j<3;++j)
			ans=min(ans,dp[n][i][j]);
	printf("%lld\n",ans);	
	for (int i=0;i<3;++i)
		for (int j=0;j<3;++j)
			if (ans==dp[n][i][j]){
				print(n,i,j);
				for (int t=1;t<=n;++t)
					printf("%d ",col[t]);
				puts("");
				return 0;
			}
				
	return 0;
}
