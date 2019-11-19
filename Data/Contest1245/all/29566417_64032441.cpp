#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f, N = 2e3 + 5;
int n, x[N], y[N], c[N], k[N], from[N];
//prim O(n^2) 适于稠密图
ll dis[N], e[N][N];
bool vis[N];
vector <int> op1;
vector <pii> op2;
void build()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) e[i][j] = 1ll*(k[i]+k[j])*(abs(x[i]-x[j]) + abs(y[i]-y[j]));
			else e[i][j] = 0;
	e[0][0] = 0;
	for(int i=1;i<=n;i++) e[0][i] = e[i][0] = c[i];
}
ll prim()
{
	for(int i=0;i<=n;i++) dis[i] = e[0][i], from[i] = 0;
	vis[0] = 1;
	int cnt = 1;
	ll sum = 0;
	while(cnt<=n)
	{
		ll minn = 1e18, u;
		for(int i=0;i<=n;i++)
		{
			if(vis[i]==0&&dis[i]<minn) minn = dis[i], u = i;
		}
		if(minn==1e18) return -1; //非连通图
		vis[u] = 1, cnt++, sum += dis[u];
		if(from[u]) op2.push_back({from[u],u});
		else op1.push_back(u);
		for(int v=0;v<=n;v++)
		{
			if(vis[v]==0&&dis[v]>e[u][v]) dis[v] = e[u][v], from[v] = u;
		}
	}
	return sum;
}
int main()
{
 	cin >> n;
 	for(int i=1;i<=n;i++) cin >> x[i] >> y[i];
 	for(int i=1;i<=n;i++) cin >> c[i];
 	for(int i=1;i<=n;i++) cin >> k[i];
 	build();
 	ll ans = prim();
 	cout << ans << '\n';
 	cout << op1.size() << '\n';
 	for(auto it : op1) cout << it << ' ';
 	cout << '\n';
 	cout << op2.size() << '\n';
 	for(auto it : op2) cout << it.first << ' ' << it.second << '\n';
	return 0;
}
