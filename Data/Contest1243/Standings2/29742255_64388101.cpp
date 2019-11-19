#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	ll ans = n;

	for(ll i=2;i*i<=n;i++) {

		if(n % i > 0) continue;

		ll a = i;
		ll b = n / i;

		if(a > 1) ans = __gcd(ans, a);
		if(b > 1) ans = __gcd(ans, b);

	}

	cout<<ans<<endl;

}