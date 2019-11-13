#include <bits/stdc++.h>
using namespace std;
#if DEBUG && !ONLINE_JUDGE
	#include "debug.h"
#else
	#define debug(args...)
	#define DBG(x...)
#endif

typedef long long ll; typedef long double ld;
#define fi first
#define se second
#define sz(x) ((int)((x).size()))
#define REP(i,a) for(int i=0;i<(a);i++)
#define MOD 1000000007
const double PI=acos(-1.0);
#define N 100005


signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.precision(17);

	int t;
	cin >> t;
	while(t--) {
		int a, b, c, ans = 0;
		cin >> a >> b >> c;

		while(b >= 1 and c >= 2)
			ans += 3, b--, c-=2;

		while(a >= 1 and b >= 2)
			ans += 3, a--, b-=2;

		cout << ans <<endl;
	}

	debug("\nRuntime = " + to_string((long double)clock()/CLOCKS_PER_SEC));
	return 0;
}