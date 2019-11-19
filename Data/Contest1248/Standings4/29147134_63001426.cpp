#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define mod 1000000007

int main() {
	
	int n, m;
	cin >> n >> m;
	
	
		
	ll a[100001], b[100001];
	a[1] = 2;
	b[1] = 0;
	
	for(int i = 2; i <= 100000; i++) {
		
		a[i] = a[i-1];
		b[i] = a[i-1];
		
		a[i] = (a[i] + b[i-1]) % mod;
	}
	// for(int i = 1; i <= 5; )
	ll ans = ((a[n] + b[n]) % mod - 2 + mod) % mod;
	ans = (ans + a[m] + b[m]) % mod;
	cout << ans << endl;
	
	return 0;
}