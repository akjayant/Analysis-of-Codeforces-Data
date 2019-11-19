#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n;
	cin >> n;
	std::vector<ll> v;
	for(ll i = 2; i * i <= n; i++){
		if(n % i == 0){
			v.push_back(i);
			if(n / i != i) v.push_back(n / i);
		}
	}
	if(v.size() == 0) return cout << n, 0;
	ll gg = v[0];
	for(int i = 1; i < v.size(); i++){
		gg = __gcd(gg, v[i]);
	}
	cout << gg;
	
	return 0;
}
