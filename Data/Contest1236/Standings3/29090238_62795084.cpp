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

const int P = 1e9 + 7;

int qpow(LL a, int b)
{
	LL ans = 1;
	for(int i = 0; 1<<i <= b; i++) {
		if(b & (1<<i))
			ans = ans * a % P;
		
		a = a * a % P;
	}
	
	return ans;
}

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
	
	int n;
	cin >> n;
	
	loop(d, 1, n) {
		loop(i, 0, n-1)
			cout << i*n + (i % 2 == 0 ? d : n-d+1) << ' ';
		cout << endl;
	}
}