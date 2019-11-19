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

#define int long long

using namespace std;

signed main() {
	int n;
	cin >> n;
	int nn = n;
	set<int> p;
	int sqrt_n = sqrt(n) + 1;
	p.insert(1);
	for (int i = 2; i <= min(sqrt_n, n); i++) {
		if (n % i == 0) {
			p.insert(i);
			while (n % i == 0 && n != 1) {
				n /= i;
				// cout << n;
			}
		}
	}
	p.insert(n);
	cout << "\n";
	if (p.size() == 2) {
		int v;
		for (auto e : p) {
			v = e;
		}
		cout << v;
	} else {
		cout << 1;
	}
    return 0;
}

