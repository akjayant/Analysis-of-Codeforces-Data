#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
using namespace std;
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define int long long
using pii = pair<int, int>;

ifstream in("in.in");

const int INF = 1e9;

void speed_up() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void loop() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v) {
		cin >> i;
	}
	sort(rall(v));
	int maxs = 0;
	for (int i = 0; i < n; i++) {
		maxs = max(maxs, min(v[i], (i + 1)));
	}
	cout << maxs << "\n";
}

signed main() {
	speed_up();
	int t;
	cin >> t;
	while (t--) {
		loop();
	}	
	return 0;
}