#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 9;
int n;
pair<long long , long long > a[MAXN];
long long  c[MAXN];
long long k[MAXN];
long long d[MAXN];
int dd[MAXN],T[MAXN];
long long Ans;
int Res1, Res2;
long long Dist(int u, int v)
{
	return abs(a[u].first - a[v].first) + abs(a[u].second - a[v].second);
}
const long long INF = long long(1e18);
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	for (int i = 1; i <= n; ++i)
		cin >> k[i];
	for (int i = 0; i <= n; ++i)
		d[i] = INF;
	d[0] = 0;
	while (1)
	{
		int u = -1;

		long long maxDist = INF;
		for (int i = 0;i<=n;++i)
			if (dd[i] == 0)
			if (d[i] < maxDist)
			{
				maxDist = d[i];
				u = i;
			}

		if (u == -1) break;
		dd[u] = 1;
		Ans = Ans + d[u];

		for (int v = 0; v <= n; ++v)
			if (dd[v]==0)
			{
				if (u == 0)
				{
					if (d[v] > c[v])
					{
						d[v] = c[v];
						T[v] = u;
					}
				}
				else
				{
					if (d[v] > (k[u] + k[v])*(Dist(u, v)))
					{
						d[v] = (k[u] + k[v])*(Dist(u, v));
						T[v] = u;
					}
				}
			}
	}

	cout << Ans << "\n";

	for (int i = 1; i <= n; ++i)
	{
		if (T[i] == 0) Res1++;
		else Res2++;
	}

	cout << Res1 << "\n";
	for (int i = 1; i <= n; ++i)
		if (T[i] == 0) cout << i << " ";
	cout << "\n";

	cout << Res2 << "\n";
	for (int i = 1; i <= n; ++i)
		if (T[i] != 0) cout << i <<  " " << T[i]<< "\n";

	return 0;

}