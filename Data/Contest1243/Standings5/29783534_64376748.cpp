#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <queue>
#include <set>
#include <iterator>
#include <queue>
#include <string>
#include <functional>
#include <array>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

signed main() {
	int k, n;
	int a[1000];
	vector<int> ans;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int max_v = 0;
		int v = 0;
		for (int j = 0; j < n; j++) {
			v = min(a[j], n - j);
			max_v = max(v, max_v);
		}
		ans.push_back(max_v);
	}
	for (auto e : ans) {
		cout << e << "\n";
	}
    return 0;
}

