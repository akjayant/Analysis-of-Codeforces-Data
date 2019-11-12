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
	vector<pii> ans;
	for (int i = 0; i < n; i++) {
		//cout << "i = " << i << endl << a << endl << b << endl << endl;
		if (a[i] == b[i]) {
			continue;
		}
		int j;
		for (j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				break;
			}
		}
		if (j == n) {
			j = 0;
			for (j = i + 1; j < n; j++) {
				if (b[j] == a[i]) {
					swap(b[j], a[j]);
					ans.push_back({j, j});
					break;
				}
			}
			if (j == n) {
				cout << "No" << endl;
				return;
			}
		}
		swap(b[i], a[j]);
		ans.push_back({j, i});
	}
	cout << "Yes\n";
	cout << ans.size() << endl;
	for (pii p : ans) {
		cout << p.first + 1 << " " << p.second + 1 << endl;
	}
}

signed main() {
	speed_up();
	int k;
	cin >> k;
	while (k--) {
		loop();
	}	
	return 0;
}