#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin >> n;
	vector<ll> d;
	for(ll i=2; i*i<=n; i++)
		if (n%i == 0) {
			d.push_back(i);
			if (i * i != n)
				d.push_back(n / i);
		}
	d.push_back(n); 
	ll res = 0;
    for(ll i=0; i<d.size(); i++)
		res = __gcd(res, d[i]);
	cout << res << "\n";
    return 0;
}