#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset((a), 0, sizeof(a))
#define str(a) strlen(a)
#define int long long
#define pii pair<int, int>
typedef long long LL;

const int maxn = 100010;
const int Mod = 1e9 + 7;

int n, ans = 1, fac[maxn], inv[maxn];
char s[maxn];

inline int power(int a, int b)
{
	int r = 1;
	while ( b ) { if ( b & 1 ) r = r * a % Mod; a = a * a % Mod; b >>= 1; }
	return r;
}

inline int C(int n, int m) { return n >= m ? (fac[n] * inv[m] % Mod) * inv[n - m] % Mod : 0; }

inline int Solve(int x)
{
	int ret = 1, last = 1;
	REP(i, 2, x) { int p = ret; ret = (ret + last) % Mod; last = p; }
	return ret;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s + 1);
	n = str(s + 1);
	fac[0] = inv[0] = 1; REP(i, 1, n) fac[i] = fac[i - 1] * i % Mod;
	inv[n] = power(fac[n], Mod - 2); for ( int i = n - 1; i >= 1; -- i ) inv[i] = inv[i + 1] * (i + 1) % Mod;
	for ( int i = 1; i <= n; ++ i )
	{
		if ( s[i] == 'm' || s[i] == 'w' ) { puts("0"); return 0; }
		if ( s[i] != 'u' && s[i] != 'n' ) continue ;
		int j = i;
		while ( s[i] == s[j] && (s[j] == 'u' || s[j] == 'n') ) ++ j;
		-- j; ans = ans * Solve(j - i + 1) % Mod;
		i = j;
	}
	cout << ans << endl;
	return 0;
}
