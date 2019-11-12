#include <bits/stdc++.h>
using namespace std; typedef long long ll;
typedef vector<int> vi; typedef pair<int,int> pii;
const ll MOD = 1e9+7;

ll power(ll b, ll e) {
	ll r=1; while(e) {
		if (e&1) r = (r*b) % MOD;
		b = (b*b) % MOD;
		e >>= 1;
	}
	return r;
}

int main() { ios_base::sync_with_stdio(0);cin.tie(0);
	ll n, m, ans;
	cin >> n >> m;
	ans = power(2,m)-1;
	if (ans < 0) ans += MOD;
	cout << power(ans,n) << endl;
	return 0;
}