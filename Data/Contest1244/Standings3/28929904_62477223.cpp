#include <bits/stdc++.h>

using namespace std;

int T, k;
string s;

int main() {
//	freopen("in", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
			int MAX = -1, cnt = 0;
		cin >> k >> s;
		for (int i = 0; i < k; ++i)
			if (s[i] == '1') ++cnt, MAX = max(MAX, max(i, k - i - 1));
		if (MAX == -1) cout << k << endl;
		else if (cnt == 1) cout << MAX * 2 + 2 << endl;
		else cout << max(MAX * 2 + 2, k + 2) << endl;
	}
	return 0;
}
