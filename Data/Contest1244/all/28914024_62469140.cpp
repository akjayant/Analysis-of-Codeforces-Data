#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		string s; cin >> s;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == '1') ans = max(ans, 2 * max(i + 1, n - i));
		} 
		cout << max(ans, n) << endl;
	}
	return 0;
}