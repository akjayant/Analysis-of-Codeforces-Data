#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n, m, MOD = 1e9 + 7;

ll powMod(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1)	res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	ll ans = (powMod(2, m) - 1 + MOD) % MOD;
	ans = powMod(ans, n);
	cout << ans;

	return 0;
}
