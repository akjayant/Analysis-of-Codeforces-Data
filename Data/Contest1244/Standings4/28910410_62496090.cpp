#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);

	ll n, k; cin >> n >> k;

	ll a, i;
	map<ll, ll> s;
	map<ll, ll>::iterator it;

	for(i = 0; i < n; i++) {
		cin >> a;
		it = s.find(a);
		if(it == s.end()) {
			s.insert(make_pair(a,1));
		}
		else {
			it->second = it->second+1;
		}
	}
	it = s.end(); it--;
	ll mx = it->first;
	ll mn = s.begin()->first;

	vector<pair<ll, ll> > v;
	for(it = s.begin(); it != s.end(); it++) {
		v.push_back(*it);
	}
	n = v.size();

	ll ml = v[0].first, mr = v[n-1].first;
	ll l = 0, r = n-1;
	while(k) {
		if(ml == mr) break;
		if(v[l].second <= v[r].second){
			if((v[l].second) * (v[l+1].first - v[l].first) <= k) {
				k -= (v[l].second) * (v[l+1].first - v[l].first);
				v[l+1].second += v[l].second;
				ml = v[l+1].first;
			} else {
				ml += k / v[l].second;
				k = 0;
			}
			l++;
		} else {
			if((v[r].second) * (v[r].first - v[r-1].first) <= k) {
				k -= (v[r].second) * (v[r].first - v[r-1].first);
				v[r-1].second += v[r].second;
				mr = v[r-1].first;
			} else {
				mr -= k / v[r].second;
				k = 0;
			}
			r--;
		}
	}

	cout << mr - ml << "\n";
}