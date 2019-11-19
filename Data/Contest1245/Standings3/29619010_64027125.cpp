#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll ((ll) 1e18 + 10)

#define endl '\n'
#define fi first
#define se second
#define pb emplace_back
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define repd(i, a, b) for(int i = (a)-1; i >= (b); i--)

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

const int N = 2020;
ll ans, sum;
vector<pii> ansE;
vector<int> ansV;
int n, x[N], y[N], c[N], k[N];
vector<pair<ll, pii>> e;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	rep(i, 0, n) cin >> x[i] >> y[i];
	rep(i, 0, n) {
		cin >> c[i];
		sum += c[i];
	}
	rep(i, 0, n) cin >> k[i];
	rep(i, 0, n) rep(j, 0, i) {
		ll w = (abs(x[i] - x[j]) + abs(y[i] - y[j]))*1ll*(k[i]+k[j]);
		e.pb(w, make_pair(j, i));
	}
	rep(i, 0, n) e.pb(c[i], make_pair(i, n));
	sort(all(e));
	UF uf(n+1);
	trav(x, e) {
		int u = x.se.fi;
		int v = x.se.se;
		if (!uf.same_set(u, v)) {
			if (u == n) ansV.pb(v);
			else if (v == n) ansV.pb(u);
			else ansE.pb(v, u);
			uf.join(u, v);
			ans += x.fi;
		}
	}
	if (sum <= ans) {
		cout << sum << endl << n << endl;
		rep(i, 0, n) cout << i+1 << " ";
		cout << endl << 0 << endl;
	} else {
		cout << ans << endl;
		cout << sz(ansV) << endl;
		trav(v, ansV) cout << v+1 << " ";
		cout << endl << sz(ansE) << endl;
		trav(e, ansE) cout << e.fi+1 << " " << e.se+1 << endl;
	}
}
