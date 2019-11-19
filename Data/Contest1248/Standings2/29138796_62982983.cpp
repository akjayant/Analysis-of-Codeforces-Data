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
const ll MOD = 998244353;
ll a, b, c, d, e, f, p, t, x, y, z, q, m, n, r, h, k, ans = 0, w, l;
vl A, B;

void input(){
	cin >> n;
	inputv(A, n);
}
void solve() {
	sort(all(A));
	a = 0;
	rep(i, n) {
		a += A[i];
		if (i == n / 2 - 1)b = a;
	}

	cout << b * b + (a - b) * (a - b) << endl;
}

int main() {
	input();
	solve();
}