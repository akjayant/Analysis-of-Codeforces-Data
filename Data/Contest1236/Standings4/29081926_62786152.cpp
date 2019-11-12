#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fastInOut();

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	fastInOut();
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		int fsOp = 0, ret = 0;
		while (fsOp <= a && 2 * fsOp <= b) {
			int remB = b - (2 * fsOp);
			ret = max(ret, 3 * (fsOp + min(remB, c / 2)));
			++fsOp;
		}
		cout << ret << "\n";
	}
	return 0;
}

void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
