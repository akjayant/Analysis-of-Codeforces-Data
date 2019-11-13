#include <bits/stdc++.h>
using namespace std;

int k, n;
string s, t;

int main() {

	cin >> k;
	while (k--) {
		cin >> n;
		cin >> s;
		cin >> t;
		
		int da = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				if (da == 1) {
					da = 0;
					cout << "No\n";
					break;
				}
				
				for (int j = i+1; j < n; j++) {
					if (s[i] == s[j] && s[j] != t[j]) {
						da = 1;
						swap(t[i], s[j]);
						break;
					}
				}
				
				if (da == 0) {
					cout << "No\n";
					break;
				}
			}
		}
		if (da) cout << "Yes\n";
	}


	return 0;
}
