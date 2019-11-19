//压行课次
#include<bits/stdc++.h>
#define LD long double
#define LL long long
using namespace std;
const int mod=1e9+7;
const int MAXN=2e3+10; 
int n,s[MAXN][MAXN],k[MAXN],c[MAXN],used[MAXN],g[MAXN],cnta,cntb;
LL ans,w[MAXN][MAXN];
bool book[MAXN];
pair<int,int> p[MAXN];
priority_queue<pair<LL,pair<int,int> > > q;
inline int read(){int sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
inline char R(){char ccc=getchar();while(ccc<'A'||ccc>'Z') ccc=getchar();return ccc;}
pair<LL,pair<int,int> > make(LL A,int B,int C){return make_pair(A,make_pair(B,C));}
int find(int x)
{
	if(x==used[x]) return x;
	return used[x]=find(used[x]);
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		p[i].first=read(),p[i].second=read();
	for(int i=1;i<=n;i++)
		c[i]=read();
	for(int i=1;i<=n;i++)
		k[i]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			w[i][j]=(1ll*abs(p[i].first-p[j].first)+1ll*abs(p[i].second-p[j].second))*(1ll*k[i]+1ll*k[j]);
			q.push(make(-w[i][j],i,j));
		}
	for(int i=1;i<=n;i++)
		q.push(make(-c[i],i,-1));
	for(int i=1;i<=n;i++)
		used[i]=i;
	while(!q.empty())
	{
		LL A=-q.top().first;
		int B=q.top().second.first,C=q.top().second.second;
		q.pop();
		if(C==-1)
		{
			int u=find(B);
			if(book[u]) continue;
			book[u]=true;
			g[B]=true;
			cnta++;
			ans+=A;
		}
		else
		{
			int u=find(B),v=find(C);
			if(u==v) continue;
			if(book[u]&&book[v]) continue;
			used[u]=v;
			book[v]|=book[u];
			ans+=A;
			cntb++;
			s[B][C]=true;
		}
	}
	printf("%lld\n",ans);
	printf("%d\n",cnta);
	for(int i=1;i<=n;i++)
		if(g[i]) printf("%d ",i);
	if(cnta) printf("\n");
	printf("%d\n",cntb);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(s[i][j]) printf("%d %d\n",i,j);
	if(cntb) printf("\n");
}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	int T=1;
	while(T--)
		solve();
	return 0;
}