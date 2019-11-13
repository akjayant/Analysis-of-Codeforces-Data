#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

ll fexp(ll base, ll pot){
	ll ans = 1;
	while(pot){
		if(pot&1) ans = (ans*base)%MOD;
		base = (base*base)%MOD;
		pot >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll N, M;
	cin >> N >> M;

	ll ans = fexp(2, M);
	ans = (ans+MOD-1)%MOD;

	ans = fexp(ans, N);

	cout << ans << '\n';

	return 0;
}