#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
vector<int> G[100010];
ll c[100010][3];
int vis[100010];
ll sc[100010][3]; // sequenced_cost
ll sn[100010];
int main()
{
	int n;
	scanf("%d", &n);
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &c[i][j]);
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for (int i = 0; i < n; i++)
	{
		if (G[i].size() > 2)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	int s;
	for (s = 0; s < n; s++)
	{
		if (G[s].size() == 1)
		{
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		vis[s] = true;
		sn[s] = i;
		sc[i][0] = c[s][0];
		sc[i][1] = c[s][1];
		sc[i][2] = c[s][2];
		for (auto x:G[s])
		{
			if (!vis[x]) s = x;
		}
	}

	ll ans = LLONG_MAX;
	int pat[3];
	pat[0] = 0; pat[1] = 1; pat[2] = 2;
	int best_pat[3];
	do
	{
		ll now = 0;
		for (int i = 0; i < n; i++)
		{
			now += sc[i][pat[i % 3]];
		}
		if (now < ans)
		{
			ans = now;
			for (int k = 0; k < 3; k++) best_pat[k] = pat[k];
		}
	} while (next_permutation(pat, pat + 3));
	cout << ans << endl;
	for (int i = 0; i < n; i++)
	{
		cout << best_pat[sn[i] % 3] + 1 << ' ';
	}
}