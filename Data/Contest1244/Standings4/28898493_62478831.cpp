#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<stack>
#include<vector>
#include<set>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int M=600010;
const int N=1010;
inline int read(void){
	int f=1,x=0;char s=getchar();
	while (!isdigit(s)){if (s=='-')f=-1;s=getchar();}
	while (isdigit(s)){x=(x<<1)+(x<<3)+(s^48),s=getchar();}
	return x*f;
}
struct edge{
	int to,next;
}e[M];
int head[M],cnt,ans;
inline void add_edge(int u,int v){
	e[++cnt].next=head[u],head[u]=cnt;
	e[cnt].to=v;
}
int vis[M];
int t,n;
inline void dfs(int u,int dep){
	vis[u]=1;
	for (int i=head[u];i;i=e[i].next){
		if (!vis[e[i].to]) dfs(e[i].to,dep+1);
	}
	vis[u]=0;
	ans=max(ans,dep);
}
signed main(void){
	t=read();
	while (t--){
		n=read();
		ans=0;
		memset(head,0,sizeof(head)),cnt=0;
		for (int i=1;i<=n;i++){
			char c;cin>>c;
			if (c=='1') add_edge(i,i+n);
			if (i!=n)
				add_edge(i,i+1),add_edge(i+n,i+n+1),add_edge(i+1,i),add_edge(i+n+1,i+n);
		}
		dfs(1,1);dfs(n+1,1);dfs(n,1);dfs(2*n,1);
		printf("%d\n",ans);
	}
	return 0;
}