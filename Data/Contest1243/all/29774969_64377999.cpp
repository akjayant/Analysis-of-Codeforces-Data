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
		ll idx = -1;
		for(ll i = 0; i < n; i ++) {
			if(s[i] != t[i]) {
				idx = i;
				break;
			}
		}
		for(ll i = 0; i < n; i ++) {
			if(i == idx) continue;
			if((t[i] == t[idx]) && (t[i] != s[i])) {
				swap(t[i], s[idx]);
				break;
			}
		}
		if(s == t) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}