#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;
const ll Mod = 1e9+7;

int n;
ll ans;
ll x[2010];
ll y[2010];
ll c[2010];
ll k[2010];
vector<pair<ll, pll> > e;
int p[2010];
vector<int> out1;
vector<pll> out2;

int Find(int a) {
	return p[a] = p[a] == a ? a : Find(p[a]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	p[b] = a;
}

ll dist(int a, int b) {
	return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

int main() {
	fast;

	cin >> n;

	for(int i=1; i<=n; i++) p[i] = i;

	for(int i=1; i<=n; i++) {
		cin >> x[i] >> y[i];
	}

	for(int i=1; i<=n; i++) {
		cin >> c[i];

		e.push_back({c[i], {0, i}});
	}

	for(int i=1; i<=n; i++) {
		cin >> k[i];
	}

	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			e.pb({dist(i, j) * (k[i] + k[j]), {i, j}});
		}
	}

	sort(all(e));

	for(auto i : e) {
		if(Find(i.se.fi) == Find(i.se.se)) continue;

		Union(i.se.fi, i.se.se);
		ans += i.fi;
		if(i.se.fi == 0) out1.pb(i.se.se);
		else out2.eb(i.se.fi, i.se.se);
	}

	cout << ans << "\n";
	cout << out1.size() <<"\n";
	for(auto i : out1) cout << i << " ";
	cout << "\n" << out2.size() << "\n";
	for(auto i : out2) {
		cout << i.fi << " " << i.se << "\n";
	}
}