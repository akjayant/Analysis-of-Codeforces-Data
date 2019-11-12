#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int k;
	cin >> k;

	for (int t = 0; t < k; t++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());

		int best = 0;
		for (int i = 0; i < n; i++) {
			int count = n - i;
			int mins = a[i];
			int square = min(mins, count);
			best = max(best, square);
		}

		cout << best << endl;
	}

	return 0;
}
