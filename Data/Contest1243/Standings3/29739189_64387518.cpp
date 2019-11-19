#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define tc(t) int t;cin >> t; while(t--)
#define pb push_back
#define fi first
#define se second
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cerr << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

int main() {_
	ll n;
	cin >> n;
	
	vector<ll> v;
	
	for(ll i = 2; i*i <= n; i++) {
		if(n%i == 0) {
			if(i == n/i) {
				v.pb(i);
			}
			else {
				v.pb(i);
				v.pb(n/i);
			}
		}
	} 
	
	int si = int(v.size());
	if(si == 0) {
		cout << n << '\n';
	}
	
	else {
		ll g = v[0];
		
		for(int i = 1; i<si; i++) {
			g = __gcd(g, v[i]);
		}
		
		cout << g << '\n';
	}
	return 0;
}

