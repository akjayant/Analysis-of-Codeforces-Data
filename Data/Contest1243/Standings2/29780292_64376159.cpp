#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int ans = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= n - i) {
			ans = max(ans, n - i);
		}
	}

	cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
    	solve();
    }

    return 0;
}