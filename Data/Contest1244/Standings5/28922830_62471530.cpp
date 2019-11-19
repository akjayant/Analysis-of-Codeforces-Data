#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int l = 0;
		int left = -1;
		int right = -1;
		for (int j = 0; j < n; j++) {
			char k;
			cin >> k;
			if (k == '1') {
				l++;
				if (left == -1) left = j;
				right = j;
			}
		}

		if (l == 0) cout << n << endl;
		else if (l == 1) {
			if (left > n - left - 1) {
				cout << 2 * left + 2 << endl;
			} else {
				cout << 2 * (n - left - 1) + 2 << endl;
			}
		}
		else {
			cout << max(n, max(right * 2 + 2, (n - left - 1) * 2 + 2)) << endl;
		}
	}
}