#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

set <pair<ll, int> > s;

int main() {
	ll n,k;
	scanf("%I64d%I64d", &n, &k);
	for (int i=0 ; i<n ; i++) {
		ll x;
		scanf("%I64d", &x);
		set<pair<ll, int> > :: iterator it = s.lower_bound(make_pair(x, 0));
		int br = 1;
		if (it!=s.end() and it->first == x) {
			br += it->second;
			s.erase(it);
		}
		s.insert(make_pair(x, br));
	}
	ll uk = 0;
	while (1) {
	/*	cout <<"k="<<k<<endl;
		for (set <pair<ll, int> > :: iterator it = s.begin() ; it!=s.end() ; it++) {
			printf("(%I64d, %d) ", it->first, it->second);
		}
		printf("\n");*/
		if (s.size() == 1) {
			printf("0\n");
			return 0;
		}
		set<pair<ll, int> > :: iterator st = s.begin(), en = s.end();
		en--;
		if (st->second <= en->second) {
			set<pair<ll, int> > :: iterator nxt = st;
			nxt++;
			ll cost = (nxt->first - st->first) * st->second;
			if (cost>k) {
				ll move = k/(st -> second);
				printf("%I64d\n", en->first - st->first - move);
				return 0;
			}
			ll br = st -> second + nxt -> second;
			ll val = nxt -> first;
			s.erase(st);
			s.erase(nxt);
			s.insert(make_pair(val, br));
			k -= cost;
		} else {
			set<pair<ll, int> > :: iterator prev = en;
			prev--;
			ll cost = (en -> first - prev -> first) * en -> second;
			if (cost>k) {
				ll move = k/(en -> second);
				printf("%I64d\n", en->first - st->first - move);
				return 0;
			}
			ll br = en -> second + prev -> second;
			ll val = prev -> first;
			s.erase(en);
			s.erase(prev);
			s.insert(make_pair(val, br));
			k -= cost;
		}
	}
	set<pair<ll, int> > :: iterator st = s.begin(), en = s.end();
	en--;
	printf("%I64d\n", en->first - st->first);
	return 0;
}