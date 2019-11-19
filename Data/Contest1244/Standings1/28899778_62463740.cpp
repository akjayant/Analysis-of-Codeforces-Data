//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

int t;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int p = (a + c - 1) / c, q = (b + d - 1) / d;
		if (p + q <= k)
			cout << p << " " << q << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
