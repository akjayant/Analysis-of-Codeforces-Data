// A
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end(), greater<int>());

		int ans = 1;
		for (int i = 0; i < n; i++) {
			int t = min(i + 1, a[i]);
			ans = max(ans, t);
		}
		cout << ans << endl;
	}

	return 0;
}
