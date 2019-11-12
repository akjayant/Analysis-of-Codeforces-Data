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

long long power(long long base, long long exp, int mod=MOD) {
	base = base % mod;
	exp = exp % (mod - 1);
	long long res = 1;
	while(exp > 0LL) {
		if(exp & 1LL) res = (res * base) % mod;
		base = (base * base) % mod;
		exp = exp >> 1LL;
	}
	return res;
}

signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.precision(17);

	ll n,m;
	cin >> n >> m;
	cout << power((power(2, m) - 1), n) %MOD << endl;
	// else
	// 	cout << "0\n";

	debug("\nRuntime = " + to_string((long double)clock()/CLOCKS_PER_SEC));
	return 0;
}