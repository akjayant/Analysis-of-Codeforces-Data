#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
	
	int t;
	cin >> t;
	while(t--) {
		
		int n;
		cin >> n;
		ll a[n];
		
		ll odd = 0, even = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] % 2) 
				odd++;
			else 
				even++;
		}
		
		int m;
		cin >> m;
		ll b[m];
		ll odd1 = 0, even1 = 0;
		for(int i = 0; i < m; i++) {
			cin >> b[i];
			if(b[i] % 2) 
				odd1++;
			else 
				even1++;
		}
		ll ans = odd1 * odd + even1 * even;
		cout << ans << endl;
			
		
	}
	return 0;
}