#include<bits/stdc++.h>

using namespace std;

#define N 2005
typedef long long ll;

int n, pre[N];

ll px[N], py[N], c[N], K[N], dis[N][N];

ll dist[N];

bool vis[N];

ll prim()
{
	memset(dist, 63, sizeof(dist));
	dist[0] = 0;
	int node = 0;
	ll ans = 0;
	while(node <= n)
	{
		ll k, minn = INT_MAX;
		for(int i = 0; i <= n; i++)
			if(!vis[i] && dist[i] < minn)
			{
				minn = dist[i];
				k = i;
			}
		vis[k] = 1;
		ans += minn;
		node++;
		for(int i = 0; i <= n; i++)
		{
			if(!vis[i])
			{
				if(dis[k][i] < dist[i]) dist[i] = dis[k][i], pre[i] = k;
			}
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld%lld", &px[i], &py[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &dis[0][i]);
		dis[i][0] = dis[0][i];
	}
	for(int i = 1; i <= n; i++)
		scanf("%lld", &K[i]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i - 1; j++)
		{
			dis[i][j] = (labs(px[i] - px[j]) + labs(py[i] - py[j])) * (K[i] + K[j]);
			dis[j][i] = dis[i][j];
		}
	}
	cout << prim() << endl;
	int cntv = 0;
	for(int i = 1; i <= n; i++) if(pre[i] == 0) cntv++;
	cout << cntv << endl;
	for(int i = 1; i <= n; i++) if(pre[i] == 0) cout << i << ' ';
	cout << endl;
	int cnte = 0;
	for(int i = 1; i <= n; i++) if(pre[i] != 0) cnte++;
	cout << cnte << endl;
	for(int i = 1; i <= n; i++) if(pre[i] != 0) cout << pre[i] << ' ' << i << endl;
	return 0;
}