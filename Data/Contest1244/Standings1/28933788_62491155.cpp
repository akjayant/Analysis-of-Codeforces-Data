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
typedef pair<ll, ll> pll;
//typedef pair<pii, int> para;
const ll inf = 1e18 + 7;
const int maxN = 1e5 + 5;

int n;
ll k;
map<ll, ll> cnt;
vector<ll> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	REP(i, n) {
		ll a;
		cin >> a;
		cnt[a]++;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	auto last = unique(v.begin(), v.end());
	v.erase(last, v.end());
	int l = 0, r = v.size() - 1;
	while(l < r) {
		if (cnt[v[l]] < cnt[v[r]] || 
		   (cnt[v[l]] == cnt[v[r]] && (v[l + 1] - v[l]) < (v[r] - v[r - 1]))) {
			int next = v[l + 1];
			ll diff = (next - v[l]);
			if (cnt[v[l]] * diff > k) {
				// TODO
				ll z = k / cnt[v[l]];
				if (z != 0) {
					cnt[v[l] + z] = cnt[v[l]];
					cnt[v[l]] = 0;
				}
				break;
			} else {
				cnt[next] += cnt[v[l]];
				k -= diff * cnt[v[l]];
				cnt[v[l]] = 0;
				l++;
			}
		} else {
			int prev = v[r - 1];
			ll diff = (v[r] - prev);
			if (cnt[v[r]] * diff > k) {
				//cout << "Here!" << endl;
				ll z = k / cnt[v[r]];
				//cout << z << endl;
				if (z != 0) {
					cnt[v[r] - z] = cnt[v[r]];
					cnt[v[r]] = 0;
				}
				break;
			} else {
				cnt[prev] += cnt[v[r]];
				k -= diff * cnt[v[r]];
				cnt[v[r]] = 0;
				r--;
			}
		}
	}
	ll minim = 1e9 + 2;
	ll maxim = -1;
	for (auto x: cnt) {
		if (x.nd != 0) {
			//cout << "Sprawdzam " << x.st << endl;
			maxim = max(maxim, x.st);
			minim = min(minim, x.st);
		}
	}
	cout << maxim - minim << endl;
	return 0;
}
