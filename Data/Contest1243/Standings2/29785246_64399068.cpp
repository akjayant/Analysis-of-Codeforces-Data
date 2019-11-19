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
//checkは十分大きければtrueを、小さければfalseを返す
map<ll, ll> insuu;
void insuubunkai(ll n) {
	a = n;
	for (ll i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			insuu[i] = 0;
			while (a % i == 0) {
				insuu[i]++;
				a = a / i;
			}
		}
	}

	if (a != 1)insuu[a]++;
}
void input() {
	cin >> n;
}
void solve() {
	insuubunkai(n);
	if (insuu.size() == 1) {
		auto ite = insuu.begin();
		x = (*ite).first;
		cout << x << endl;
	}
	else {
		cout << 1 << endl;
	}
}

int main() {
	input();
	solve();
}