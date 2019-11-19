#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <set>

using namespace std;

typedef long long ll;


int main() {
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
#else
//	freopen("input.txt","r",stdin);
//	freopen("output.txt", "w",stdout);
#endif
        int tc;
	cin >> tc;
	for (int t = 0 ; t < tc; ++t) {
		int n, m;
		ll p[2] = {0, 0};
		ll q[2] = {0, 0};
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			p[x % 2]++;
		}
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int x;
			cin >> x;
			q[x % 2]++;
		}
		cout << q[0] * p[0] + q[1] * p[1] << endl;
	}
	return 0;
}