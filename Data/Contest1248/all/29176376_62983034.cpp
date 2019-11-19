#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	
	ll n, i, x = 0, y = 0;
	cin >> n; 
	vector<ll> a(n);
	for(i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	for(i = 0; i < n / 2; i++) {
		x += a[i];
	}
	for(i = n / 2; i < n; i++) {
		y += a[i];
	}
	cout << x * x + y * y;
}


