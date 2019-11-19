#include <bits/stdc++.h>
#define mp make_pair
#define debug(x) cout << #x << ": " << x << endl
#define pb push_back
typedef long long LL;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const LL INF = 0x3f3f3f3f3f3f3f3f;
using namespace std;
LL n, ans, m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	m = n;
	LL k = sqrt(n);
	vector<LL> p;
	for (int i = 2; i <= k; ++i) {
		if (n % i == 0) {
			p.pb(i);
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		p.pb(n);
	if (p.size() == 1)
		cout << p.front();
	else
		cout << 1;
}