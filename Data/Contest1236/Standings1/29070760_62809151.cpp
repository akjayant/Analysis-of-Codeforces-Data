#include <bits/stdc++.h>

using namespace std;

int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<int>> rows(n, vector<int>());
	vector<vector<int>> cols(m, vector<int>());

	for(int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		rows[x].push_back(y);
		cols[y].push_back(x);
	}

	for(int i = 0; i < n; i++) {
		sort(rows[i].begin(), rows[i].end());
	}
	for(int i = 0; i < m; i++) {
		sort(cols[i].begin(), cols[i].end());
	}

	long long count = 1;

	int r = 0;
	int c = 0;
	int dir = 0;

	int r_max = n;
	int r_min = -1;
	int c_max = m;
	int c_min = -1;

	bool first = true;

	while(true) {
		int dist;
		if(dir == 0) {
			auto endi = lower_bound(rows[r].begin(), rows[r].end(), c);
			int end = c_max;
			if(endi != rows[r].end()) {
				end = min(end, *endi);
			}

			dist = (end-1) - c;
			c = end-1;
			r_min = r;
		}
		else if(dir == 1) {
			auto endi = lower_bound(cols[c].begin(), cols[c].end(), r);
			int end = r_max;
			if(endi != cols[c].end()) {
				end = min(end, *endi);
			}

			dist = (end-1) - r;
			r = end-1;
			c_max = c;
		}
		else if(dir == 2) {
			auto endi = lower_bound(rows[r].begin(), rows[r].end(), c);
			int end = c_min;
			if(endi != rows[r].begin()) {
				endi--;
				end = max(end, *endi);
			}

			dist = c - (end+1);
			c = end+1;
			r_max = r;
		}
		else if(dir == 3) {
			auto endi = lower_bound(cols[c].begin(), cols[c].end(), r);
			int end = r_min;
			if(endi != cols[c].begin()) {
				endi--;
				end = max(end, *endi);
			}

			dist = r - (end+1);
			r = end+1;
			c_min = c;
		}

		dir = (dir + 1) % 4;

		//cout << r << " " << c << endl;

		if(dist <= 0) {
			if(first) {
				first = false;
				continue;
			}

			break;
		}
		count += dist;
		//cout << "count : " << count << endl;

		first = false;
	}

	//cout << "final count : " << count << endl;

	long long total = n;
	total *= m;
	total -= k;

	cout << (count == total ? "YES" : "NO") << endl;

	return 0;
}
