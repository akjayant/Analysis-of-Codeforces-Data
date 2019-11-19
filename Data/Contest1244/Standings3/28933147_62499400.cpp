// youngjinp20
// 2019 10

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

int main() {
	vii X;
	int n;
	int ma=0, mi=1e9;
	int a[100005];
	ll k;
	cin >> n >> k;

	for (int i=0; i<n; i++) {
		cin >> a[i];
		ma = max(a[i], ma);
		mi = min(a[i], mi);
	}

	sort(a, a+n);

	int l=0, r=n-1;

	while ( l < r ) {
		if ( l <= n-1-r ) {
			int st = a[l];
			int ed = a[l+1];
			int diff = ed - st;
			X.push_back({l+1, diff});
			l ++;
			while (l+1 < n && a[l+1] == a[l]) {
				l ++;
			}
		} else {
			int st = a[r];
			int ed = a[r-1];
			int diff = st - ed;
			X.push_back({n-r, diff});
			r --;
			while (r >= 0 && a[r-1] == a[r]) {
				r --;
			}
		}
	}

	int d = ma-mi;
	for (auto e : X) {
		int ct = min(k/(ll) e.first, (ll) e.second);
		d -= ct;
		k -= (ll) ct * e.first;
	}

	if (d < 0) d = 0;
	printf("%d\n", d);

	return 0;
}
