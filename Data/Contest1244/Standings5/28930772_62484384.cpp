//Code of C#oder Born_Clear
#include <bits/stdc++.h>
using namespace std;
#define loop(n) for(int i=0;i<n;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define ll long long
#define s(x) scanf("%d", &x)
#define sd(x) scanf("%lf", &x)
#define sl(x) scanf("%lld", &x)
#define mod 1000000007
#define fi first
#define se second
#define p(x) printf("%d",x)
#define pl(x) printf("%lld", x)
#define pd(x) printf("%lf", x)
#define pn() printf("\n")
#define vi(v) vector<int>v
#define vl(v) vector<long long int>v
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define len(s) s.length()
void input(int n,int a[]){loop(n)cin>>a[i];}
ll bin_expo(ll A, ll B, ll M){ll res = 1LL;while (B > 0){if(B % 2 == 1){res = (res * A) % M;}A = (A * A) % M; B = B / 2;}return res;}
vector<int>v[4];
int col[100006];
vector<int>adj[100005];
void dfs(int node,int prev,int col)
{
	v[col].pb(node);
	for(auto i:adj[node])
	{
		if(i!=prev)
		{
			if(col==1)
				dfs(i,node,2);
			if(col==2)
				dfs(i,node,3);
			if(col==3)
				dfs(i,node,1);
		}
	}
}
int main()
{
	memset(col,-1,sizeof(col));
	int n;
	cin>>n;
	ll a[n+5][4];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][2];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][3];
	}
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);

	}
	int r;
	for(int i=1;i<=n;i++)
	{
		if(adj[i].size()>2)
		{
			cout<<-1<<endl;
			return 0;
		}
		if(adj[i].size()==1)
		{
			r=i;
		}
	}
	dfs(r,-1,1);
	ll sum[4][4];
	memset(sum,0,sizeof(sum));
	for(int i=0;i<v[1].size();i++)
	{
		sum[1][1]+=a[v[1][i]][1];
		sum[1][2]+=a[v[1][i]][2];
		sum[1][3]+=a[v[1][i]][3];
	}
	for(int i=0;i<v[2].size();i++)
	{
		sum[2][1]+=a[v[2][i]][1];
		sum[2][2]+=a[v[2][i]][2];
		sum[2][3]+=a[v[2][i]][3];
	}
	for(int i=0;i<v[3].size();i++)
	{
		sum[3][1]+=a[v[3][i]][1];
		sum[3][2]+=a[v[3][i]][2];
		sum[3][3]+=a[v[3][i]][3];
	}
	ll ans=LLONG_MAX,xx,yy,zz;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=3;k++)
			{
				if(i==j || j==k || i==k)
				{
					continue;
				}
				if(sum[1][i]+sum[2][j]+sum[3][k]<ans)
				{
					ans=sum[1][i]+sum[2][j]+sum[3][k];
					xx=i;yy=j;zz=k;
				}
			}
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<v[1].size();i++)
	{
		col[v[1][i]]=xx;
	}
	for(int i=0;i<v[2].size();i++)
	{
		col[v[2][i]]=yy;
	}
	for(int i=0;i<v[3].size();i++)
	{
		col[v[3][i]]=zz;
	}
	for(int i=1;i<=n;i++)
		cout<<col[i]<<" ";
	cout<<endl;
	return 0;	
}