#include <bits/stdc++.h>
 
#define pb push_back
#define fst first
#define snd second
#define ios ios_base::sync_with_stdio(0); cin.tie(0);
#define open freopen("anime.in", "r", stdin); freopen("anime.out", "w", stdout);

typedef long long ll;
typedef long double ld;
 
using namespace std;

signed main(){
	ios;
	ll n;
	ll k;
	cin >> n >> k;
	ll a[n];
	set<pair<ll, ll>> st;
	map<ll, ll> mp;
	for (ll i = 0; i < n; i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	for (auto u : mp){
		st.insert(u);
	}
	while(st.size() != 1){
		auto one = *(st.begin());
		auto two = *(--st.end());
		if (one.snd < two.snd){
			auto need = *(++st.begin());
			if (abs(need.fst - one.fst) * one.snd > k){
				k /= one.snd;
				cout << abs(two.fst - (one.fst + k)) << endl;
				return 0;
			}else{
				k -= abs(need.fst - one.fst) * one.snd;
				st.erase(one);
				ll cnt = need.fst;
				ll count = need.snd + one.snd;
				st.erase(need);
				st.insert({cnt, count});
			}
		}else{
			auto need = *(--(--st.end()));
			if (abs(two.fst - need.fst) * two.snd > k){
				k /= two.snd;
				cout << abs(one.fst - (two.fst - k)) << endl;
				return 0;
			}else{
				k -= abs(two.fst - need.fst) * two.snd;
				st.erase(two);
				ll cnt = need.fst;
				ll count = need.snd + two.snd;
				st.erase(need);
				st.insert({cnt, count});
			}
		}
	}
	cout << 0 << endl;
}