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
	string a, b;
	cin >> a >> b;
	int cnt = 0;
	vector<int> d;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			cnt++;
			d.push_back(i);
		}
	}
	if (cnt == 2) {
		if (a[d[0]] == a[d[1]] && b[d[1]] == b[d[0]]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	} else {
		cout << "No\n";
	}
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