#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI(i,n) FOR(i,1,(n))
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define sz(w) (int) w.size()
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, char> pic;
typedef pair<int, pii> para;
const int inf = 1e9 + 7;
const int maxN = 2e5 + 5;

ll n, p, w, d;
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> p >> w >> d;
	ll mod = p % d;
	//ll x = -1;
	REP(i, d + 1) {
		ll c = (i * w) % d;
		if (c == mod) {
			v.pb(i);
		}
	}
	for (auto x: v) {
		ll k = (p - x * w) / (d * w);
		//if (k > 0) k++;
		k = x + (k * d);
		ll ile_draw = (p - (k * w)) / d;
		//cout << x << " " << k << " " << ile_draw << endl;
		if (k * w + ile_draw * d == p &&
			ile_draw + k <= n &&
			ile_draw >= 0) {
				cout << k  << " " << ile_draw << " " << n - k - ile_draw << endl;
				return 0;
			}
	}
	cout << -1 << endl;
	return 0;
}
