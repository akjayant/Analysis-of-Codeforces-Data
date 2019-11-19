#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 2;
int n,a[N][4],num,to[N],ne[N],first[N],du[N],col[N],anscol[N];
vector <int> V;
void addE(int u,int v)
{
	to[++num] = v,ne[num] = first[u],first[u] = num,du[v]++;
}
int dfs(int x,int fa)
{
	V.push_back(x);
	for(int i = first[x];i;i = ne[i])
		if(to[i] != fa)
			dfs(to[i],x);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i][1];
	for(int i = 1;i <= n;i++)
		cin >> a[i][2];
	for(int i = 1;i <= n;i++)
		cin >> a[i][3];
	for(int u,v,i = 1;i < n && cin >> u >> v;i++,addE(u,v),addE(v,u));
	for(int i = 1;i <= n;i++)
		if(du[i] >= 3)
		{
			cout << -1 << endl;
			return 0;
		}
	for(int i = 1;i <= n;i++)
		if(du[i] == 1)
		{
			dfs(i,0);
			break;
		}
	int ans = 1e18;
	for(int i = 1;i <= 3;i++)
		for(int j = 1;j <= 3;j++)
			if(j != i)
			{
				int ret = 0;
				col[V[0]] = i,col[V[1]] = j;
				for(int k = 2;k < n;k++)
					col[V[k]] = 6 - col[V[k - 1]] - col[V[k - 2]];
				for(int k = 1;k <= n;k++)
					ret += a[k][col[k]];
				if(ret < ans)
				{
					ans = ret;
					memcpy(anscol,col,sizeof(col));
				}
			}
	cout << ans << endl;
	for(int i = 1;i <= n;i++)
		cout << anscol[i] << " ";
	cout << endl;
	return 0;
}