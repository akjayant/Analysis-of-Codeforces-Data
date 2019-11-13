#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n, greater<int>());
		int mx = 0;
		for (int i = 0; i < n; i++) {
			if (i + 1 <= a[i])
				mx = i + 1;
		}
		cout << mx << endl;
	}
}
