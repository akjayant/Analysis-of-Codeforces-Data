#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+100;

int n, a[N];
ll k;

deque<pair<int,ll>> q;

ll cnt(pair<int,ll> a, pair<int,ll> b) {
	ll del = abs(b.first - a.first);
	return del * a.second;
}

int main() {
	scanf("%d %lld", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}	
	sort(a, a + n);
	for(int i = 0; i < n; ) {
		int j = i;
		while(j + 1 < n && a[j + 1] == a[i])
			j++;
		q.push_back({a[i], j - i + 1});
		i = j + 1;
	}
	while(k) {
		if((int)q.size() < 2) break;
		if(q[0].second <= q[(int)q.size() - 1].second) {
			ll need = (ll)(q[1].first - q[0].first) * q[0].second;
			if(need > k) break;

			k -= need;
			auto x = q[0];
			q.pop_front();
			q[0].second += x.second;
		}
		else {
			int sz = (int)q.size();
			ll need = (ll)(q[sz - 1].first - q[sz - 2].first) * q[sz - 1].second;
			if(need > k) break; 

			k -= need;
			auto y = q.back();
			q.pop_back();
			q.back().second += y.second;
		}
	}

	while(k) {
		if(q[0].second <= q[(int)q.size() - 1].second) {
			if(k < q[0].second) break;
			ll ty = k / q[0].second;
			q[0].first += ty;
			k -= ty * q[0].second;
		}
		else {
			if(k < q.back().second) break;
			ll ty = k / q.back().second;
			q.back().first -= ty;
			k -= q.back().second * ty;
		}
	}
	printf("%d\n", q.back().first - q[0].first);
	return 0;
}