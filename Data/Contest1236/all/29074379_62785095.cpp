#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int N = 5e4 + 5;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, ans = 0;
		cin >> a >> b >> c;
		for (int i = 0; i <= a; ++i) {
			if (2 * i <= b) {
				int tmp = 0;
				tmp = 3 * i;
				tmp += 3 * min(b - 2 * i, c / 2);
				ans = max(ans, tmp);
			}
		}
		cout << ans << endl;
	}
}
