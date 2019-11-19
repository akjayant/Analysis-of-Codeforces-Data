#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> row(n + 1);
	vector<vector<int>> col(m + 1);
	map<pair<int, int>, bool> a;
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		row[x].push_back(y);
		col[y].push_back(x);
		a[{x, y}] = true;
	}
	for (int i = 1; i <= n; ++i) {
		sort(row[i].begin(), row[i].end());
	}
	for (int i = 1; i <= m; ++i) {
		sort(col[i].begin(), col[i].end());
	}
	int x_from = 1, x_to = n, y_from = 1, y_to = m, direct = 1;
	long long sum = 0;
	while (1) {
//		cerr << x_from << ' ' << x_to << ' ' << y_from << ' ' << y_to << '\n';
		if (y_from > y_to) {
			break;
		}
		if (row[x_from].empty()) {
			sum += y_to - y_from + 1;
		} else {
			int pos = (int) (lower_bound(row[x_from].begin(), row[x_from].end(), y_from) - row[x_from].begin());
			if (pos >= (int) row[x_from].size()) {
				sum += y_to - y_from + 1;
			} else {
				y_to = min(y_to, row[x_from][pos] - 1);
				sum += y_to - y_from + 1;
			}
		}
		if (x_from + 1 > n || a.find({x_from + 1, y_to}) != a.end()) {
			break;
		}
		x_from += 1;
//cerr << x_from << ' ' << x_to << ' ' << y_from << ' ' << y_to << '\n';
		if (x_from > x_to) {
			break;
		}
		if (col[y_to].empty()) {
			sum += x_to - x_from + 1;
		} else {
			int pos = (int) (lower_bound(col[y_to].begin(), col[y_to].end(), x_from) - col[y_to].begin());
			if (pos >= (int) col[y_to].size()) {
				sum += x_to - x_from + 1;
			} else {
				x_to = min(x_to, col[y_to][pos] - 1);
				sum += x_to - x_from + 1;
			}
		}
		if (y_to - 1 < 1 || a.find({x_to, y_to - 1}) != a.end()) {
			break;
		}
		y_to -= 1;
//cerr << x_from << ' ' << x_to << ' ' << y_from << ' ' << y_to << '\n';
		if (y_from > y_to) {
			break;
		}
		if (row[x_to].empty()) {
			sum += y_to - y_from + 1;
		} else {
			int pos = (int) (lower_bound(row[x_to].begin(), row[x_to].end(), y_to) - row[x_to].begin()) - 1;
			if (pos == -1) {
				sum += y_to - y_from + 1; 
			} else {
				y_from = max(y_from, row[x_to][pos] + 1);
				sum += y_to - y_from + 1;
			}
		}
		if (x_to - 1 < 1 || a.find({x_to - 1, y_from}) != a.end()) {
			break;
		}
		x_to -= 1;
	//	cerr << x_from << ' ' << x_to << ' ' << y_from << ' ' << y_to << '\n';
		if (x_from > x_to) {
			break;
		}
		if (col[y_from].empty()) {
			sum += x_to - x_from + 1;
		} else {
			int pos = (int) (lower_bound(col[y_from].begin(), col[y_from].end(), x_to) - col[y_from].begin()) - 1;
			if (pos == -1) {
				sum += x_to - x_from + 1;
			} else {
				x_from = max(x_from, col[y_from][pos] + 1);
				sum += x_to - x_from + 1;
			}
		}
		if (y_from + 1 > m || a.find({x_from, y_from + 1}) != a.end()) {
			break;
		}
		y_from += 1;
	}	
	cout << (sum + k == 1LL * n * m ? "Yes" : "No") << '\n';
	return 0;
}