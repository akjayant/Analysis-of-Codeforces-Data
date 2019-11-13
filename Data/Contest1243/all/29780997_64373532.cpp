#include <bits/stdc++.h>

#define N 1000010 

using namespace std;

int a[N];

int main() {
	int t;
	cin >> t;
	while (t -- ) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++ ) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		int ans = 0;
		for (int i = n; i; i -- ) {
			if (a[i] >= n - i + 1) {
				ans = max(ans, n - i + 1);
			}
		}
		cout << ans << endl ;
	}
	return 0;
}