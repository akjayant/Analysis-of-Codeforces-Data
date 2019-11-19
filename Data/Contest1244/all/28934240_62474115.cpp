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
	while(t--) {
		int n;
		cin >> n;
		string stairs;
		cin >> stairs;
		int first = -1;
		int last = -1;
		int num = 0;
		rep(i, 0, n) {
			if (stairs[i] == '1') {
				first = i;
				break;
			}
		}
		rep(i, 0, n) {
			if (stairs[i] == '1') {
				last = i;
				num++;
			}
		}

		if (first == -1) {
			cout << n << endl;
			continue;
		}
		int ans = n + num;
		ans = max(ans, (last+1)*2);
		ans = max(ans, (n-first) * 2);
		cout << ans << endl;
	}
}
