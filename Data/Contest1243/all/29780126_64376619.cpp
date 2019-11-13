#include <bits/stdc++.h>
using namespace std;

int tc, n, id[10004], cnt;
string a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> a >> b;

		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				id[cnt] = i;
				cnt++;
			}
		}

		if (cnt == 0 || (cnt == 2 && a[id[0]] == a[id[1]] && b[id[0]] == b[id[1]])) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}