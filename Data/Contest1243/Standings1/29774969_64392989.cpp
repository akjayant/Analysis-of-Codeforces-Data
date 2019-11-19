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

	v<ll> primes;
	v<ll> isPos(1e6+1, 0);
	for(ll i = 2; i < 1e6+1; i ++) {
		if(isPos[i] == 0) {
			primes.push_back(i);
			for(ll j = i+i; j < 1e6+1; j += i) {
				isPos[j] = 1;
			}
		}
	}
	ll n;
	cin >> n;
	ll num = -1;
	for(ll i = 0; primes[i]*primes[i] <= n; i ++) {
		if(n % primes[i]) continue;
		num = primes[i];
		break;
	}
	if(num == -1) {
		cout << n << endl;
	}
	else {
		while((n % num) == 0) {
			n /= num;
		}
		if(n == 1) {
			cout << num << endl;
		}
		else cout << 1 << endl;
	}

	return 0;
}