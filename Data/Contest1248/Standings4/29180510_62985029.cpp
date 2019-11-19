#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int p[maxn], q[maxn];
signed main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, m1;
		cin >> n;
		int temp = 0, temp2 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
			if (p[i] % 2 == 0)	temp++;
		}
		cin >> m1;
		for (int i = 1; i <= m1; i++) {
			cin >> q[i];
			if (q[i] % 2 == 0)	temp2++;
		}
		cout << temp * temp2 + (n - temp) * (m1 - temp2) << endl;
	}
	return 0;
}