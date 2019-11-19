#include "bits/stdc++.h"
using namespace std;
 
const int N = 1e5 + 5;

void solve() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		int n; 
		cin >> n;
		vector<int> p(n);
		for(int i = 0; i < n; ++i) {
			cin >> p[i];
		}
		int m; cin >> m;
		vector<int> q(m);
		int o = 0, e = 0;
		for(int i = 0; i < m; ++i) {
			cin >> q[i];
			o += q[i] % 2;
			e += !(q[i] % 2);
		}	
		long long ans = 0;
		for(int i = 0; i < n; ++i) {
			if(p[i] & 1) {
				ans += o;
			} else {
				ans += e;
			}
		}
		cout << ans << endl;
	}
	
}
 
int main() {
	solve();
	return 0;  
}
