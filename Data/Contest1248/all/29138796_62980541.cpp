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
	cin >> t;
}
void solve() {
	while (t--) {
		vl A(0), B(0);
		cin >> m;
		inputv(A, m);
		cin >> n;
		inputv(B, n);

		a = 0;
		b = 0;
		c = 0;
		d = 0;
		rep(i, m) {
			if (A[i] % 2 == 1)a++;
			else b++;
		}
		rep(i, n) {
			if (B[i] % 2 == 1)c++;
			else d++;
		}
		cout << a * c + b * d << endl;
	}
}

int main() {
	input();
	solve();
}