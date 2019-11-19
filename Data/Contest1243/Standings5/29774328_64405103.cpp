#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <pii, int> piii;

#define X first
#define Y second
#define int ll

signed main() {
	int n, cnt = 0;
	cin >> n;
	int nn = n;
	for (int i = 2; i * i <= n; i++) {
		if (nn % i == 0) {
			while (nn % i == 0)
				nn /= i;
			if (nn == 1) {
				cout << i;
				return 0;
			} else {
				cout << 1;
				return 0;
			}
		}
	}
	cout << n;
}
