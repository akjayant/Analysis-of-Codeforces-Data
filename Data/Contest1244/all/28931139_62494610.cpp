#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
const int maxn=1e5+10;
ll c[3][maxn];
ll dp[3][3],tmp[3][3];
int fr[maxn][3][3];
vector<int> g[maxn];
int fa[maxn],to[maxn];
vector<int> lst;
bool vis[maxn];
queue<int> que;
int col[maxn];
void build(int x)
{
	que.push(x);
	while(!que.empty())
	{
		int y=que.front();
		que.pop();
		lst.emplace_back(y);
		vis[y]=1;
		for(int i=0;i<g[y].size();i++)
			if(!vis[g[y][i]])
			{
				que.push(g[y][i]);
			}
	}
}
inline void upd(ll &a,ll b)
{
	if(b<a)a=b;
}
vector<int> cs;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++)
			scanf("%I64d",&c[i][j]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	for(int i=1;i<=n;i++)
		if(g[i].size()>2)
		{
			printf("-1\n");
			return 0;
		}
	int rt=0;
	for(int i=1;i<=n;i++)
		if(g[i].size()==1)
		{
			rt=i;
			break;
		}
	if(!rt)
	{
		printf("-1\n");
		return 0;
	}
	build(rt);
	memset(dp,0x3f,sizeof(dp));
	for(int c1=0;c1<3;c1++)for(int c2=0;c2<3;c2++)if(c1!=c2)
		upd(dp[c1][c2],c[c1][lst[0]]+c[c2][lst[1]]);
		
	for(int i=3;i<=n;i++)
	{
		memset(tmp,0x3f,sizeof(tmp));
		for(int c1=0;c1<3;c1++)for(int c2=0;c2<3;c2++)if(c1!=c2&&dp[c1][c2]<linf)
			for(int c3=0;c3<3;c3++)if(c3!=c1&&c3!=c2)
			{
				if((dp[c1][c2]+c[c3][lst[i-1]])<tmp[c2][c3])
				{
					tmp[c2][c3]=dp[c1][c2]+c[c3][lst[i-1]];
					fr[i][c2][c3]=c1;
				}
			}
			
		for(int c1=0;c1<3;c1++)for(int c2=0;c2<3;c2++)dp[c1][c2]=tmp[c1][c2];
	}
	ll ans=linf;
	ll b1,b2;
	for(int c1=0;c1<3;c1++)for(int c2=0;c2<3;c2++)if(c1!=c2)
	{
		if(dp[c1][c2]<ans)
		{
			ans=dp[c1][c2];
			b1=c1;
			b2=c2;
		}
	}
	int i=n;
	col[lst[n-1]]=b2;
	col[lst[n-2]]=b1;
//	cs.push_back(b2);
//	cs.push_back(b1);
	while(i>2)
	{
		int t=fr[i][b1][b2];
		if(t==b1||t==b2||b1==b2)
		{
			printf("-1\n");
			return 0;
		}
		b2=b1;
		b1=t;
		col[lst[i-3]]=t;
		cs.push_back(t);
		i--;
	}
	reverse(cs.begin(),cs.end());
	printf("%I64d\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",col[i]+1);
	return 0;
}