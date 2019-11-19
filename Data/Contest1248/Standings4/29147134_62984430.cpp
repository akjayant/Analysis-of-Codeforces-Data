#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	
	int n;
	cin >> n;
	ll a[n];
	for(int i = 0; i < n; i++) 
		cin >> a[i];
		
	sort(a, a+n, cmp);
	
	ll x = 0, y = 0;
	for(int i = 0; i < n/2; i++) {
		x += a[i];
		y += a[n-1-i];
	}
	
	if(n % 2) 
		x += a[n/2];
		
	ll ans = x*x + y*y;
	cout << ans;
	return 0;
}