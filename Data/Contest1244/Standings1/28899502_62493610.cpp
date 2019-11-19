#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define mkp make_pair
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
typedef long double ld;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=(1LL<<62);
const int inf=(1<<30);
const int nmax=1e5+50;
const int mod=1e9+7;
using namespace std;
int n,i,j,t,p,x,y,rs[nmax],b[nmax],bl;
ll c[5][nmax],f[nmax][5][5],ans;
pair<int,int>mn;
pair<ll,pair<int,int> >m;
vector<int>a[nmax];
void dfs(int x,int p)
{
	b[++j]=x;
	int nr=0;
	for(int i=0;i<a[x].size();i++)
	{
		int y=a[x][i];
		if(y==p)continue;
		nr++;
		dfs(y,x);
	}
	if(nr>1)bl=1;
}
int main()
{
	//freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=3;i++)for(j=1;j<=n;j++)cin>>c[i][j];
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
	}
	mn=mkp(n,n);
	for(i=1;i<=n;i++)mn=min(mn,mkp((int)a[i].size(),i));
	j=0;
	dfs(mn.sc,0);
	if(bl)rc(-1);
	for(i=1;i<=n;i++)for(j=1;j<=3;j++)for(t=1;t<=3;t++)f[i][j][t]=llinf;
	for(i=1;i<=3;i++)for(j=1;j<=3;j++)if(i!=j)f[1][i][j]=c[i][b[1]];
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=3;j++)
		{
			for(t=1;t<=3;t++)
			{
				if(t==j)continue;
				p=6-j-t;
				if(f[i-1][t][p]==llinf)continue;
				f[i][j][t]=min(f[i][j][t],f[i-1][t][p]+c[j][b[i]]);
			}
		}
	}
	for(i=n;i>=1;i--)
	{
		m=mkp(llinf,mkp(n,n));
		if(i==n)
		{
			for(j=1;j<=3;j++)
			{
				for(t=1;t<=3;t++)
				{
					m=min(m,mkp(f[i][j][t],mkp(j,t)));
				}
			}
			ans=m.fr;
		}
		else
		{
			for(j=1;j<=3;j++)if(j!=t && j!=rs[b[i+1]])m=min(m,mkp(f[i][t][j],mkp(t,j)));
		}
		t=m.sc.sc;
		rs[b[i]]=m.sc.fr;
	}
	cout<<ans<<endl;
	for(i=1;i<=n;i++)cout<<rs[i]<<" ";
	cout<<endl;
	return 0;
}
