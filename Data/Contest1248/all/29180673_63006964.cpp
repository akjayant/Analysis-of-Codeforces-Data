#include<bits/stdc++.h>
#define ll long long
#define clr(x,i) memset(x,i,sizeof(x))
using namespace std;
const int N=2000005;
const ll mod=1e9+7;
inline int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f; 
}
vector<int> G[N];
int n,m,q[N];
bool vis[N];
void solve()
{
	n=read(); m=read();
	for(int i=0;i<=n*2+2;i++) G[i].clear();
	memset(vis, 0, sizeof(bool)*(n*2+2));
	
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		if(u==v) continue;
		G[u].push_back(v+n);
		G[v+n].push_back(u);
	}
	int s=0,t=0;
	q[t++]=1;
	while(s<t){
		int x=q[s++]; vis[x]=1;
		for(auto v:G[x]){
			v-=n;
			if(!vis[v]) vis[v]=1,q[t++]=v;
		}
	}
	if(t<n){
		puts("Yes");
		printf("%d %d\n",t,n-t);
		for(int i=1;i<=n;i++) if(vis[i]) printf("%d ",i); puts("");
		for(int i=1;i<=n;i++) if(!vis[i]) printf("%d ",i); puts("");
		return;
	}
	s=0; t=0; q[t++]=1+n;
	memset(vis, 0, sizeof(bool)*(n*2+2));
	while(s<t){
		int x=q[s++]; vis[x-n]=1;
		for(auto v:G[x]){
//			v-=n;
			if(!vis[v])
			  vis[v]=1,q[t++]=v+n;
		}
	}
	if(t<n){
		puts("Yes");
		printf("%d %d\n",n-t,t);
		for(int i=1;i<=n;i++) if(!vis[i]) printf("%d ",i); puts("");
		for(int i=1;i<=n;i++) if(vis[i]) printf("%d ",i); puts("");
		return;
	}
	puts("No");
}
int main()
{
	int T=read();
	while(T--) solve();
}