#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset((a), 0, sizeof(a))
#define str(a) strlen(a)
#define pii pair<int, int>
#define int long long
typedef long long LL;

const int maxn = 1010;
const int N = 40;

int f[maxn][2][2], T, l, r;

inline int calc(int n, int m)
{
	mem(f); f[N][0][0] = 1;
	if ( n < 0 || m < 0 ) return 0;
	for ( int i = N - 1; i >= 0; -- i ) REP(j, 0, 1) REP(k, 0, 1)
	{
		int x = (n & (1ll << i)) || j, y = (m & (1ll << i)) || k;
		f[i][x][y] += f[i + 1][j][k];
		if ( (n & (1ll << i)) || j ) f[i][j][y] += f[i + 1][j][k];
		if ( (m & (1ll << i)) || k ) f[i][x][k] += f[i + 1][j][k];
	}
	return f[0][0][0] + f[0][0][1] + f[0][1][0] + f[0][1][1];
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> T;
	while ( T --  ) { cin >> l >> r; cout << calc(r, r) - 2 * calc(l - 1, r) + calc(l - 1, l - 1) << endl; }
	return 0;
}
