#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x),end(x)
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	for (; t > 0; t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int num1 = (a + c - 1) / c;
		int num2 = (b + d - 1) / d;
		if (num1 + num2 > k)
			cout << "-1\n";
		else
			cout << num1 << " " << num2 << "\n";
	}
}
