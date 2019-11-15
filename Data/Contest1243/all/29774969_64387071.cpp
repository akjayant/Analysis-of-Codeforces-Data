#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define v vector
#define ALL(x) x.begin(),x.end()
#define rALL(x) x.rbegin(),x.rend()
#define mp make_pair
#define fi first
#define se second
#define endl '\n'

const ll mod = 1e9 + 7;
const ld PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll k;
	cin >> k;
	while(k --) {
		ll n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		v<ll> count(26, 0);
		for(ll i = 0; i < n; i ++) {
			count[s[i]-'a']++;
			count[t[i]-'a']++;
		}
		ll pos = 0;
		for(ll i = 0; i < 26; i ++) {
			pos += (count[i] % 2);
		}
		if(pos) cout << "NO\n";
		else {
			cout << "YES\n";
			ll num = 0;
			v<pair<ll, ll>> moves;
			for(ll i = 0; i < n; i ++) {
				if(s[i] == t[i]) continue;
				num ++;
				ll idx = -1;
				for(ll j = i+1; j < n; j ++) {
					if(s[j] == s[i]) {
						idx = j;
						break;
					}
				}
				if(idx != -1) {
					moves.push_back({idx+1, i+1});
					swap(s[idx], t[i]);
					continue;
				}
				num ++;
				for(ll j = i+1; j < n; j ++) {
					if(t[j] == s[i]) {
						idx = j;
						break;
					}
				}
				moves.push_back({idx+1, idx+1});
				moves.push_back({idx+1, i+1});
				swap(s[idx], t[idx]);
				swap(s[idx], t[i]);
			}
			cout << num << endl;
			for(auto i : moves) {
				cout << i.first << " " << i.second << endl;
			}
		}
	}

	return 0;
}