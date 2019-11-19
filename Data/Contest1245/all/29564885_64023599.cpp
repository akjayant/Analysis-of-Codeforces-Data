#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset((a), 0, sizeof(a))
#define str(a) strlen(a)
#define pii pair<int, int>
#define int long long
typedef long long LL;

const int maxn = 5010;
const int INF = 1e18;

int n, X[maxn], Y[maxn], k[maxn], dis[maxn], f[maxn], ans, sum1, g[maxn];
bool vis[maxn];
vector<pii> p;

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	REP(i, 1, n) cin >> X[i] >> Y[i];
	REP(i, 1, n) cin >> dis[i];
	REP(i, 1, n) cin >> k[i];
	REP(o, 1, n)
	{
		int Min = INF, x;
		REP(i, 1, n) if ( dis[i] < Min && !vis[i] ) { Min = dis[i]; x = i; }
		ans += Min; vis[x] = true;
		if ( f[x] == 0 ) g[++ sum1] = x;
		else p.push_back(pii(f[x], x));
		REP(i, 1, n)
		{
			int ret = (k[i] + k[x]) * (abs(X[i] - X[x]) + abs(Y[i] - Y[x]));
			if ( dis[i] > ret )
			{
				dis[i] = ret; f[i] = x;
			}
		}
	}
	cout << ans << endl;
	cout << sum1 << endl;
	REP(i, 1, sum1) cout << g[i] << " "; cout << endl;
	cout << p.size() << endl;
	REP(i, 0, (LL)p.size() - 1)
	    cout << p[i].first << " " << p[i].second << endl;
	return 0;
}
