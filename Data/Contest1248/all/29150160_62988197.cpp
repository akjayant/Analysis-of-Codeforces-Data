// *** creator : cfmasterr *** //
#include <bits/stdc++.h>

using namespace std;

long long int a[1000000];

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	long long int n;
	cin >> n;
	long long int ans1 = 0, ans2 = 0;
	for (long long int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for(long long int i = 0; i < n / 2; i++)
					 ans1 += a[i];
 for (long long int i = n / 2; i < n; i++)
		 ans2 += a[i];
	ans1 *= ans1;
	ans2 *= ans2;
	ans1 += ans2;
	cout << ans1;
  return 0;
}

