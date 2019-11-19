/*
 * Author: apikdech
 * Time: 16:13:12 20-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007, N = 1e5 + 5;
ll a[N], x = 0, y = 0;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n; i++) {
		if (i < n/2) x += a[i];
		else y += a[i];
	}
	cout << x*x + y*y << "\n";
	return 0;
}
