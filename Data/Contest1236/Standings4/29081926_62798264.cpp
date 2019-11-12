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
	int n, cur = 1, idx = 0, inc = 1;
	cin >> n;
	vector<vector<int> > ret(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			ret[idx].push_back(cur++), idx += inc;
		idx = max(0, min(idx, n - 1)), inc *= -1;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cout << ret[i][j] << " \n"[j == n - 1];
	return 0;
}

void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
