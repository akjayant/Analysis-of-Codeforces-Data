#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int h[N];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> h[i];
		sort (h + 1, h + n + 1);
		int i;
		for (i = n; i >= 1; i--) {
			if (h[i] < n - i + 1) {
				i++;
				break;
			}
		}
		if (i == 0)
			i++;
		cout << n - i + 1 << endl;
	}	

	return 0;
}

