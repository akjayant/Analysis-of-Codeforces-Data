#include <bits/stdc++.h>
 
using namespace std;
#define ff first
#define ss second
#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target ("avx2")
#define int long long
int  md = 1e9 + 7;
int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}
main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int ii =0;ii < t;ii++) {
		int n;
		cin >> n;
		vector < int > a(n);
		for(int i = 0; i < n;i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		int ans = 1;
		for(int i = 1; i <= n; i++) {
			if(a[i - 1]>=i){
				ans =i;
			} else {
				break;
			}
		}
		cout << ans << "\n";
	}
}