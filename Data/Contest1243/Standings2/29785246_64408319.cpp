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
string S1, S2;
char c1, c2;
//checkは十分大きければtrueを、小さければfalseを返す
void input() {
	cin >> q;
}
void solve() {
	while (q--) {
		ans = 0;
		cin >> n;
		cin >> S1 >> S2;
		a = 0;
		rep(i, n) {
			if (S1[i] != S2[i]) {
				a++;
				if (a == 2) {
					if (c1 == S1[i] && c2 == S2[i])ans = 1;
				}
				c1 = S1[i];
				c2 = S2[i];
			}
		}

		if ((a == 2) && ans == 1) {
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
}

int main() {
	input();
	solve();
}