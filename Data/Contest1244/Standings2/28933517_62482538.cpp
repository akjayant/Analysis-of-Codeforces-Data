#include <bits/stdc++.h>

#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
#define pb 	push_back
#define ff 	first
#define ss 	second
#define nl 	"\n"
#define rep(i, a, b) for(int i=a; i<b; i++)
typedef	long long ll;
typedef	long double	ld;
typedef unsigned long long ull;

using namespace std;

vector<int> g[1000005];
int vis[1000005];

vector<int> arr;

void dfs(int cur)
{
	arr.pb(cur);
	vis[cur] = 1;

	for(int x : g[cur])
		if(!vis[x])
			dfs(x);
}

int main()
{
	fastio();
	int n;
	cin >> n;

	ll c[n+1][3];

	for(int i=1; i<=n; i++)
		cin >> c[i][0];

	for(int i=1; i<=n; i++)
		cin >> c[i][1];
	
	for(int i=1; i<=n; i++)
		cin >> c[i][2];

	int deg[n+1] = {0};

	int flag = 0;

	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		deg[u]++;
		deg[v]++;

		if(deg[u] > 2 || deg[v] > 2)
			flag = 1;
	}

	if(flag)
	{
		cout << "-1\n";
		return 0;
	}

	int st = 0;
	for(int i = 1; i<=n; i++)
		if(deg[i] == 1)
			st = i;

	dfs(st);	

	// for(int x: arr)
	// 	cout << x << " ";
	// cout << nl;

	ll dp[n][3][3];

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(i != j)
				dp[0][i][j] = c[arr[0]][j];
		}
	}

	for(int i=1; i<n; i++)
	{
		dp[i][0][1] = dp[i-1][2][0] + c[arr[i]][1];
		dp[i][0][2] = dp[i-1][1][0] + c[arr[i]][2];
		dp[i][1][0] = dp[i-1][2][1] + c[arr[i]][0];
		dp[i][1][2] = dp[i-1][0][1] + c[arr[i]][2];
		dp[i][2][0] = dp[i-1][1][2] + c[arr[i]][0];
		dp[i][2][1] = dp[i-1][0][2] + c[arr[i]][1];
	}

	ll ans = dp[n-1][0][1];
	int a1, b1=0, c1=1;

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(i != j)
			{
				if(ans > dp[n-1][i][j])
				{
					ans = dp[n-1][i][j];
					c1 = j;
					b1 = i;
				}
			}
		}
	}

	a1 = 3 - b1 -c1;

	int col[n+1];

	int in = n-1;

	while(in >= 0)
	{
		col[arr[in]] = c1;
		in--;

		if(in >= 0)
			col[arr[in]] = b1;
		in--;

		if(in >= 0)
			col[arr[in]] = a1;
		in--;
	}

	cout << ans << endl;
	for(int i=1; i<=n; i++)
		cout << col[i] + 1 << " "; 
	cout << nl;
}