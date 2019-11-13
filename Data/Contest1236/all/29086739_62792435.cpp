#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

const long long MOD=1000000007;

long long fastpow(long long n, long long m) {
	long long res=1, p=n;
	while (m) {
		if (m&1) res=(res*p)%MOD;
		m>>=1;
		p=(p*p)%MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long i, j, k, m, n, c=0, x, y, z;
	cin>>n>>m;
	
	cout<<fastpow((fastpow(2, m)+MOD-1)%MOD, n);

	
	return 0;
}