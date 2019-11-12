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

	ll t;
	cin >> t;
	while(t --) {
		ll n;
		cin >> n;
		v<ll> count(n+1, 0);
		for(ll i = 0; i < n; i ++) {
			ll x;
			cin >> x;
			count[x] ++; 
		}
		for(ll i = n-1; i >= 0; i --) {
			count[i] += count[i+1];
		}
		ll ans = 0;
		for(ll i = 0; i <= n; i ++) {
			ans = max(ans, min(i, count[i]));
		}
		cout << ans << endl;
	}	

	return 0;
}