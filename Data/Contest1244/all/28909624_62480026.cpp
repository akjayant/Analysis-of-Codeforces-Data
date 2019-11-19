#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define lowbit(x) ((x)&(-x))
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define pdi pair<double,int>
#define ull unsigned long long
#define clr(a,b) memset(a,b,sizeof(a))
#define Endl '\n'
#define caze(T) for(cin>>T;T;T--)
#define i16 __int128
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=1<<17;
int c[N][3];
vector<int>G[N];
int a[N],ass[N];
void dfs(int u,int fa,int cnt)
{
	a[cnt]=u;
	for(int v:G[u])
		if(v!=fa)
			dfs(v,u,cnt+1);
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;++i)
			G[i].clear();
		for(int i=0;i<3;++i)
			for(int j=1;j<=n;++j)
				scanf("%d",&c[j][i]);
		int md=0;
		for(int i=1,u,v;i<n;++i)
		{
			scanf("%d%d",&u,&v);
			G[u].pb(v);G[v].pb(u);
			md=max((int)G[u].size(),md);
			md=max((int)G[v].size(),md);
		}
		if(md>2){puts("-1");continue;}
		int t[3]={0,1,2};
		int as[3];
		int rt=0;
		for(int i=1;i<=n;++i)
			if(G[i].size()==1)
			{
				rt=i;
				break;
			}
		dfs(rt,rt,0);
		ll ans=1LL<<61;
		do
		{
			ll tp=0;
			for(int i=0;i<n;++i)
				tp+=c[a[i]][t[i%3]];
			if(tp<ans)
			{
				ans=tp;
				for(int i=0;i<3;++i)
					as[i]=t[i];
			}
		}while(next_permutation(t,t+3));
		printf("%lld\n",ans);
		for(int i=0;i<n;++i)
			ass[a[i]]=as[i%3];
		for(int i=1;i<=n;++i)
			printf("%d%c",ass[i]+1," \n"[i==n]);
	}
}