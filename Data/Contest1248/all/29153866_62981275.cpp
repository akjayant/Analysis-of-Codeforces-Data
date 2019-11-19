#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	LL t, n, m;
	cin >> t;
	while (t--) {
		cin >> n;
		LL a = 0, b = 0, c = 0, d = 0, x;
		while (n--) {
			cin >> x;
			if (x & 1)
				++a;
			else
				++b;
		}
		cin >> m;
		while (m--) {
			cin >> x;
			if (x & 1)
				++c;
			else
				++d;
		}
		cout << a * c + b * d << "\n";
	}
}