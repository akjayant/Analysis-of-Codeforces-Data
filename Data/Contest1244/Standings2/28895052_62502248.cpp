#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=110000;
const int INF=0x7f7f7f7f7f7f7f7f;
int a[N][4],dp[N][4][4],mark[N][4][4],pp[N],root,ans=INF;
vector<int> q[N],s;
int n;
void DFS(int x,int before) {s.push_back(x); for(int i=0;i<q[x].size();i++) if(q[x][i]!=before) DFS(q[x][i],x); }
void Solve()
{
	for(int i=3;i<=n;i++)
	{
		int pro=s[i];
		for(int j=1;j<=3;j++)
		{
			for(int k=1;k<=3;k++)
			{
				if(j==k) continue;
				for(int x=1;x<=3;x++)
				{
					if(x==j||x==k||dp[i-1][k][x]==INF) continue;
					if(dp[i-1][k][x]+a[pro][j]<dp[i][j][k])
					{
						dp[i][j][k]=dp[i-1][k][x]+a[pro][j]; mark[i][j][k]=x;
					}
				}
			}
		}
	}
}
signed main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=3;i++) for(int j=1;j<=n;j++) scanf("%I64d",&a[j][i]);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%I64d %I64d",&u,&v);
		q[u].push_back(v); q[v].push_back(u);
	}
	for(int i=1;i<=n;i++) {if(q[i].size()>2) {printf("-1\n"); return 0; } } 
	for(int i=1;i<=n;i++) if(q[i].size()==1) root=i; 
	s.push_back(0); DFS(root,0); memset(dp,0x7f,sizeof(dp));
	for(int i=1;i<=3;i++) {for(int j=1;j<=3;j++) {if(i==j) continue; dp[2][i][j]=a[s[2]][i]+a[s[1]][j]; } }
	Solve(); int xx,yy;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(i==j) continue;
			if(dp[n][i][j]<ans) ans=dp[n][i][j],xx=i,yy=j;
		}
	}printf("%I64d\n",ans);
	for(int i=n;i;i--)
	{
		pp[s[i]]=xx;
		int t=mark[i][xx][yy];
		xx=yy; yy=t;
	}
	for(int i=1;i<n;i++) printf("%I64d ",pp[i]);  printf("%I64d\n",pp[n]);
	return 0;
}