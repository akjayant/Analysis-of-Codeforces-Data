#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
#define REP(i,k,n) for (int i = k; i <= n; ++i)
#define REPR(i,k,n) for (int i = k; i >= n; --i)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	int ret = 0;
	while (t--) {
		int a, b, c;
		ret = 0;
		cin >> a >> b >> c;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				int f1 = i;
				int f2 = 2 * i + j;
				int f3 = j * 2;
				if (f1 <= a && f2 <= b && f3 <= c) {
					ret = max(ret, f1 + f2 + f3);
				}
			}
		}
		cout << ret << '\n';
	}
	return 0;
}
