#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 1e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll dp[50][2][2];

ll get(ll x, ll i) {
	return min(1LL, x & (1ll << i));
}
ll solve(ll ra, ll rb){
	if(min(ra, rb) < 0) return 0;
	memset(dp, 0, sizeof dp);
	dp[40][1][1] = 1;
	for(int i = 40; i > 0; i--){
		for(int ea = 0; ea < 2; ea ++)
			for(int eb = 0; eb < 2; eb ++)
				for(int ba = 0; ba < 2; ba ++)
					for(int bb = 0; bb < 2; bb++){
						if(bb + ba == 2) continue;
						
						if(ea && ba && get(ra, i - 1) == 0) continue;
						if(eb && bb && get(rb, i - 1) == 0) continue;
						dp[i - 1][ea && (ba == get(ra, i - 1))][eb && (bb == get(rb, i - 1))] += dp[i][ea][eb];
						
					}
	}
	return dp[0][0][0] + dp[0][1][0] + dp[0][1][1] + dp[0][0][1];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	ll l, r;
	while(t--) {
		cin >> l >> r;
		cout << solve(r, r) - 2LL*solve(r, l - 1 ) + solve(l - 1, l - 1) << '\n';	
	}
	return 0;
}
