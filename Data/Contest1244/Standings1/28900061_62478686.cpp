#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector<int> AdjList[100001];
int c[100001][4];
int a[100001];
int f[3][3];
int col[100001];
int val[100001];
int deg[100001];
int root;
int z1,z2;

void dfs(int u,int p,int pos)
{
	a[pos] = u;
	for (int i=0;i<AdjList[u].size();i++)
	{
		int v = AdjList[u][i];
		if (v != p)
			dfs(v,u,pos+1);
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int j=1;j<=3;j++)
		for (int i=1;i<=n;i++)
			cin >> c[i][j];
	for (int i=1;i<=n-1;i++)
	{	
		int u,v;
		cin >> u >> v;
		AdjList[u].push_back(v);
		AdjList[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	for (int i=1;i<=n;i++)
	{
		if (deg[i] == 1)
			root = i;
		if (deg[i] >= 3)
		{
			cout << -1;
			return 0;
		}
	}
	dfs(root,-1,1);
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			f[i][j] = 1e18;
	int res = 1e18;
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
			if (i != j)
			{
				val[1] = i;
				val[2] = j;
				f[i][j] = c[a[1]][i] + c[a[2]][j]; 
				for (int k=3;k<=n;k++)
					for (int x=1;x<=3;x++)
						if (x != val[k-2] && x != val[k-1])
						{
							val[k] = x;
							f[i][j] += c[a[k]][x];
						}
				if (f[i][j] < res)
				{
					res = f[i][j];
					z1 = i;
					z2 = j;
				}
			}
	cout << res << '\n';
	val[1] = z1;
	val[2] = z2;
	col[a[1]] = z1;
	col[a[2]] = z2;
   	for (int k=3;k<=n;k++)
   		for (int x=1;x<=3;x++)
   			if (x != val[k-2] && x != val[k-1])
   			{
   				val[k] = x;
   				col[a[k]] = x;
			}
	for (int i=1;i<=n;i++)
		cout << col[i] << ' ';
}