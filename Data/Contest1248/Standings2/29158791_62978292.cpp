#include <iostream> 
#include <algorithm>  
#include <vector>
#include <stdio.h>
#include <string>
#include <map>
#include <numeric>
#include <stack>
#include <set>
#include <math.h>
#include <iomanip>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int odd1 = 0, even1 = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x % 2) odd1++;
			else even1++;
		}
		int m; cin >> m;
		int odd2 = 0, even2 = 0;
		for (int i = 0; i < m; i++) {
			int x; cin >> x;
			if (x % 2) odd2++;
			else even2++;
		}
		cout << (long long)even1 * even2 + (long long) odd1 * odd2 << endl;
	}

	return 0;
}