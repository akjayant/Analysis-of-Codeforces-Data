#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[1002];

int main() {

	cin >> t;
	while (t) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		sort(a, a + n);
		int maxi = 0;
		for (int i = n-1; i >= 0; i--) {
			maxi = max(maxi, min(n-i, a[i]));
		}
		
		cout << maxi << endl;
		t --;
	}


	return 0;
}
