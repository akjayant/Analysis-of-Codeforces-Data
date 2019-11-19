#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int T, a, b, c, d, k;
int main () {
	for (cin >> T; T; --T) {
		cin >> a >> b >> c >> d >> k;
		bool ok = 0;
		for (int i = 0, x, y; i <= k; ++i) {
			x = i, y = k - i;
			if (x * c >= a && y * d >= b) {
				printf("%d %d\n", x, y);
				ok = 1;
				break;
			}
		}
		if (!ok) {
			puts("-1");
		}
	}
	return 0;
}