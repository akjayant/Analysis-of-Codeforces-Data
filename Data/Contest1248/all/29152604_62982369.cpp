#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int na = 0, nb = 0, ma = 0, mb = 0;

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			if (p % 2) {
				na++;
			}
			else {
				nb++;
			}
		}

		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
			int p;
			cin >> p;
			if (p % 2) {
				ma++;
			}
			else {
				mb++;
			}
		}

		unsigned long long res = 0;
		res += (unsigned long long)na * ma;
		res += (unsigned long long)nb * mb;

		cout << res << "\n";
	}
}