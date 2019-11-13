#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define sz(a) ((int)a.size())
#define mem(a, b) memset(a, b, sizeof a)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define gmid (l + r >> 1)
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;

ll qpow(ll a, ll b){

	ll ret = 1;
	while(b){

		if(b & 1) ret = ret * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ret;
}

int main() {

	ios::sync_with_stdio(0); cin.tie(0);
	ll n, m; cin >> n >> m;
	ll ret = qpow(2, m) - 1;
	ret = (ret + mod) % mod;
	ret = qpow(ret, n);
	cout << ret << endl;
    return 0;
}
