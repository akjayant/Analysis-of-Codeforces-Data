#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

#define repeat(n) for(register LL ________________ = (n); ________________ > 0; --________________)
#define loop(i, l, r) for(register LL i = (l), ________r = (r); i <= ________r; ++i)
#define iloop(i, l, r) for(register LL i = (l), ________r = (r); i < ________r; ++i)
#define rloop(i, r, l) for(register LL i = (r), ________l = (l); i >= ________l; --i)

typedef long long LL;

#ifdef CAI_WEI_HAN
#include "my_print.h"
#include "LOG.h"
#else
#define LOG(...) 1
#endif

signed main()
{
#ifdef CAI_WEI_HAN
	freopen("test.in", "r", stdin);
	#define cout cerr
#else
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	constexpr char endl = '\n';
#endif
	
	int z;
	cin >> z;
	
	repeat(z) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int x = min(b, c/2);
		cout << (x + min(a, (b-x) / 2)) * 3 << endl;
	}
}