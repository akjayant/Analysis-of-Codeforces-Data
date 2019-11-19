#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef pair<ll, ll> PP;
#define rep(i,n) for(ll i = 0; i < ll(n); i++)
#define all(v) v.begin() , v.end()
#define inputv(v,n) rep(i,n){\
    ll x;\
    cin>>x;\
    v.push_back(x);\
    }
const ll INF = 99999999999999;
const ll MOD = 1000000007;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, ans = 0, w, l;
vl A, B;

void input(){
	cin >> n >> m;
}

void solve() {
	vl dp(100010, 0);
	dp[0] = 2;
	dp[1] = 4;
	for (ll i = 2; i < 100001; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2])%MOD;
	}

	cout << (dp[n - 1] + dp[m - 1] + MOD - 2)%MOD << endl;
	
}

int main() {
	input();
	solve();
}