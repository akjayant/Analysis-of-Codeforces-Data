#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define M 500005
#define mod 1000000007
#define inf LLONG_MAX
using namespace std;
ll a[M], b[M], c[M], f[6][M],ans[6];
vector<int> g[M],vis;

ll dfs(int s,int p, int d){
	ll l=0;
	for(auto u: g[s]){
		if(u!=p){
			if(f[d][s]!=0 && f[d][p]!=0){
				f[d][u]=0;
				l = dfs(u,s,d)+ a[u];
			}
			if(f[d][s]!=1 && f[d][p]!=1){
				f[d][u]=1;
				l = dfs(u,s,d) + b[u];
			}
			if(f[d][s]!=2 && f[d][p]!=2){
				f[d][u]=2;
				l = dfs(u,s,d)+ c[u];
			}
		}
	}
	return l;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t,n,m,q,i,j,k,x,y,z;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(i=1;i<n;i++){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(i=1;i<=n;i++){
		if(g[i].size()==1){
			x = i;
			y = g[i][0];
		}
		else if(g[i].size()>2){
			cout<<-1<<"\n";
			return 0;
		}
	}
	
	f[0][x] = 0;
	f[0][y] = 1;
	ans[0] = a[x]+b[y];
	ans[0] += dfs(y,x,0);
	f[1][x] = 0;
	f[1][y] = 2;
	ans[1] = a[x]+c[y];
	ans[1] += dfs(y,x,1);
	f[2][x] = 1;
	f[2][y] = 2;
	ans[2] = b[x]+c[y];
	ans[2] += dfs(y,x,2);
	f[3][x] = 1;
	f[3][y] = 0;
	ans[3] = b[x]+a[y];
	ans[3]+= dfs(y,x,3);
	f[4][x] = 2;
	f[4][y] = 1;
	ans[4] = c[x]+b[y];
	ans[4] += dfs(y,x,4);
	f[5][x] = 2;
	f[5][y] = 0;
	ans[5] = c[x]+a[y];
	ans[5] += dfs(y,x,5);
	
	x = 0;
	for(i=0;i<6;i++)
	{
//		cout<<ans[i]<<"\n";
//		for(j=1;j<=n;j++)
//		cout<<f[i][j]+1<<" ";
//		cout<<"\n";
		if(ans[x]>ans[i])
		x = i;
	}
	cout<<ans[x]<<"\n";
	for(i=1;i<=n;i++)
	cout<<f[x][i]+1<<" ";
	
}

// Name - Hemant Chowdhury
// Arise, Awake And Stop Not Till The Goal Is Reached!
// If I fail,I will stand again;If I win,I will move farther





