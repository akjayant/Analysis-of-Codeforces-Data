#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3+5;
const long long mod = 1e9+7;
ll binaryPow(ll a, ll b) {
	ll ans = 1;
	while(b > 0) {
		if(b & 1) {
			ans = ans * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}
int main() {
	ll a, b;
	cin>>a>>b;
	ll ans = 0;
	ll k = binaryPow(2LL, b) + mod - 1;
	k %= mod;
	ans = binaryPow(k, a);
	cout<<ans<<endl; 
	


	   return 0;
}