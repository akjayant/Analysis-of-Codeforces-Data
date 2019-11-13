#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10000;
int a[MAXN];
int n, T;
int main() {
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];

		sort(a + 1, a + n + 1);
		int ans = 1;
		for (int i = n; i >= 1; --i)
		{
			ans = max(ans, min(a[i], n - i + 1));
		}
		cout << ans << "\n";
	}
	return 0;
}