#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;

#define repeat(n) for(register LL ______________ = (n); ______________ > 0; --______________)
#define loop(i, l, r) for(register LL i = (l), ________r = (r); i <= ________r; ++i)
#define iloop(i, l, r) for(register LL i = (l), ________r = (r); i < ________r; ++i)
#define rloop(i, r, l) for(register LL i = (r), ________l = (l); i >= ________l; --i)

typedef long long LL;

#ifdef CAI_WEI_HAN
#include "LOG.h"
#else
#define LOG(...) 1
#endif

bool vis[30][2][2];
LL f(int a, int b, int i, bool d1, bool d2)
{
	static LL memo[30][2][2];
	
	if(i < 0)
		return 1;
	
	if(vis[i][d1][d2])
		return memo[i][d1][d2];
	
	vis[i][d1][d2] = true;
	
	int ta = bool((1<<i) & a);
	int tb = bool((1<<i) & b);
	
	memo[i][d1][d2] = 0;
	loop(x, 0, d1 ? 1 : ta)
	loop(y, 0, d2 ? 1 : tb)
	if(x == 0 || y == 0)
		memo[i][d1][d2] += f(a, b, i-1, d1 || x < ta, d2 || y < tb);
	
	return memo[i][d1][d2];
}

signed main()
{
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
	#define cout cerr
#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	constexpr char endl = '\n';
	
	int z;
	cin >> z;
	
	repeat(z) {
		int l, r;
		cin >> l >> r;
		
		fill(&vis[0][0][0], &vis[29][1][1]+1, false);
		LL x1 = f(r, r, 29, false, false);
		
		fill(&vis[0][0][0], &vis[29][1][1]+1, false);
		LL x2 = l == 0 ? 0 : f(l-1, r, 29, false, false);
		
		fill(&vis[0][0][0], &vis[29][1][1]+1, false);
		LL x3 = l == 0 ? 0 : f(l-1, l-1, 29, false, false);
		
		fill(&vis[0][0][0], &vis[29][1][1]+1, false);
		cout << x1 - 2 * x2 + x3 << endl;
	}
}