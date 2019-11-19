#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cassert>
#include<vector>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<deque>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string.h>
#include<string>
#include<iomanip>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FOR(i,k,n) for(int i = k ; i < n ; ++i)
#define REP(i,k,n) for(int i = k ; i <= n ; ++i)
#define sz(x) (int)x.size()
#define VAR(x) #x << " " << x
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<ll> vll;

vi t;

map<int,ll> il;

int main() {
	boost;
	int n;
	ll k;
	cin >> n >> k;
	for (int i = 0; i < n ; ++i) {
		ll a;
		cin >> a;
		t.pb(a);
	}

	sort(all(t));
	for (int i = 0; i < n; ++i) il[t[i]]++;

	ll ileZurz = 0;
	ll roz = t.back() - t[0];
	while (ileZurz < k && roz > 0) {
		if (il.begin()->second < il.rbegin()->second) {
			ll cnt = il.begin()->second;
			int co = il.begin()->first;
			int co2 = next(il.begin())->first;
			if ((ll)(co2 - co) * cnt + ileZurz <= k) {
				ileZurz += (ll)(co2 - co) * cnt;
				il.erase(il.begin());
				il.begin()->second += cnt;
			} else {
				il.erase(il.begin());
				il.insert({co + (k-ileZurz)/(ll)(cnt), cnt});
				ileZurz = k;
			}
		} else {
			ll cnt = prev(il.end())->second;
			ll co = prev(il.end())->first;
			ll co2 = prev(prev(il.end()))->first;
			if ((ll)(co - co2) * cnt + ileZurz <= k) {
				ileZurz += (ll)(co - co2) * cnt;
				il.erase(prev(il.end()));
				prev(il.end())->second += cnt;
			} else {
				il.erase(prev(il.end()));
				il.insert({co - (k-ileZurz)/(ll)(cnt), cnt});
				ileZurz = k;
			}
		}

		roz = il.rbegin()->first - il.begin()->first;
	}
	cout << roz << "\n";
}