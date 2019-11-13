#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int gcd(int x, int y) {
	if (x < y)
		swap(x, y);
	return y == 0 ? x : gcd(y, x % y);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		cout << (gcd(x, y) == 1 ? "Finite" : "Infinite") << endl;
	}
}