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
const ll INF = 9999999999999;
const ll MOD = 998244353;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, ans = 0, w, l;
vl A;
//checkは十分大きければtrueを、小さければfalseを返す
bool check(ll x) {
	if (A.end() - lower_bound(all(A), x) < x)return true;
	return false;
}
ll nibutan(void) {
	ll ok = INF, ng = -1, mid;
	while (ok - ng > 1) {
		mid = (ok + ng) / 2;
		if (check(mid))ok = mid;
		else ng=mid;
	}
	return ng;
}
void input() {
	cin >> q;
}
void solve() {
	while (q--) {
		A = vl(0);
		cin >> n;
		inputv(A, n);
		sort(all(A));
		cout << nibutan() << endl;
	}
}

int main() {
	input();
	solve();
}