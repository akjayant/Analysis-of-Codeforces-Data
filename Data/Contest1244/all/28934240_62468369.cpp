#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;
	while (t--) {
		int a,b,c,d,k;
		cin >> a >> b >> c >> d >> k;

		int cNeeded = (a+c-1) / c;
		int dNeeded = (b+d-1) / d;
		if (cNeeded + dNeeded <= k) {
			cout << cNeeded << " " << dNeeded << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}
}
