#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

#define rep(i,a) for (int i = 0; i < (a); ++i)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vi arr1(n);
		ll even1 = 0;
		ll odd1 = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr1[i];
			if (arr1[i] % 2 == 0)
				even1++;
			else
				odd1++;
		}

		int m; cin >> m;
		vi arr2(m);
		ll even2 = 0;
		ll odd2 = 0;
		for (int i = 0; i < m; ++i) {
			cin >> arr2[i];
			if (arr2[i] % 2 == 0)
				even2++;
			else
				odd2++;
		}
		
		long long sol = even1 * even2 + odd1 * odd2;
		cout << sol << '\n';
	}
	return 0;
}