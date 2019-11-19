#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		long long n, e1 = 0, e2 = 0, o1 = 0, o2 = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x % 2 == 0)
				e1++;
			else
				o1++;
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x % 2 == 0)
				e2++;
			else
				o2++;
		}
		cout << (e1 * e2 + o1 * o2) << "\n";
	}
}