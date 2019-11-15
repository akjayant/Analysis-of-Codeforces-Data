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

	int n;
	cin >> n ;
	vector<vector<int>> a(n, vector<int>(n));
	REP(i, n)
		REP(j, n)
			a[i][j] = i*n + j + 1;
	DBG(a);
	REP(i, n)
		if(i%2)
			reverse(a[i].begin(), a[i].end());
	REP(j, n) {
		REP(i, n)
			cout << a[i][j] << " ";
		cout << "\n";
	}


	debug("\nRuntime = " + to_string((long double)clock()/CLOCKS_PER_SEC));
	return 0;
}