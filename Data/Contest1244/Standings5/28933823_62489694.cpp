#include<bits/stdc++.h>
using namespace std ;
#define int long long
inline int read()
{
    int x=0;
    char c=getchar();
    bool flag=0;
    while(c<'0'||c>'9') {if(c=='-')flag=1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x+(x<<2)<<1)+ c-'0';c=getchar();}
    return flag?-x:x;
}
const int N=1e5+5;
int n,a[N][4];
vector<int>G[N];
int deg[N],p[4],ans[4];
int tmp,cnt=1,pp[N];
inline void Dfs(int u,int fa) 
{
  tmp+=a[u][p[(cnt++-1)%3+1]];
  for(int i=0;i<G[u].size();++i) 
  {
  	int v=G[u][i];
  	if(v==fa) continue;
  	else Dfs(v,u);
  }
}
inline void Get(int u,int fa) 
{
  pp[u]=ans[(cnt ++ - 1) % 3 + 1] ;
  for(int i=0;i<G[u].size();++i) 
  {
  	int v=G[u][i];
  	if(v==fa) continue;
  	else Get(v,u);
  }
}
signed main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i][1]=read();
	for(int i=1;i<=n;++i) a[i][2]=read();
	for(int i=1;i<=n;++i) a[i][3]=read();
	for(int i=1;i<=n-1;++i)
	{
		int u=read(),v=read();
		G[u].push_back(v),G[v].push_back(u);
        ++deg[u],++deg[v];
        if(deg[u]>2) {printf("-1\n");return 0;}
        if(deg[v]>2) {printf("-1\n");return 0;}
	}
	int bg=0;
    for(int i=1;i<=n;++i) if(G[i].size()==1) {bg=i;break;}
    for(int i=1;i<=3;++i) p[i]=i;
    int val=LLONG_MAX;
    do
    {
    	tmp=0,cnt=1;
    	Dfs(bg,0);
    	if(tmp<val) {val=tmp;for(int i=1;i<=3;++i) ans[i]=p[i];
		}
	}while(next_permutation(p+1,p+4));
	printf("%lld\n",val);
	cnt=1,Get(bg,0);
	for(int i=1;i<=n;++i) printf("%lld ",pp[i]);
}
