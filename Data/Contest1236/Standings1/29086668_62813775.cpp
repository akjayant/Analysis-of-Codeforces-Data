#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>

#define FOR_LT(i, beg, end) for (int i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (int i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (int i = beg; end <= i; i--)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int64_t n, m; cin >> n >> m;

	vector<vector<int>> osx(n + 1);
	vector<vector<int>> osy(m + 1);
	int64_t k; cin >> k;
	FOR_LT(i, 0, k) {
		int x, y; cin >> x >> y;
		osx[x].push_back(y);
		osy[y].push_back(x);
	}
	FOR_LT(i, 0, n) {
		sort(osx[i].begin(), osx[i].end());
	}
	FOR_LT(i, 0, m) {
		sort(osy[i].begin(), osy[i].end());
	}

	int xu = 1, xb = n, yu = 1, yb = m;

	int d = 1;
	int x = 1, y = 1;
	int64_t s = 1;
	while (true) {
		if (d == 1) {
			auto lim = lower_bound(osx[x].begin(), osx[x].end(), y);
			int limy = (lim != osx[x].end()) ? *lim : m + 1;
			limy = min(limy - 1, yb);
			if (limy == y) {
				if (x == 1 && y == 1) {
					d = 2;
					continue;
				}
				break;
			}

			s += limy - y;
			y = limy;
			xu = x + 1;
			d = 2;
		}
		else if (d == 2) {
			auto lim = lower_bound(osy[y].begin(), osy[y].end(), x);
			int limx = (lim != osy[y].end()) ? *lim : n + 1;
			limx = min(limx - 1, xb);
			if (limx == x) break;

			s += limx - x;
			x = limx;
			yb = y - 1;
			d = 3;
		}
		else if (d == 3) {
			auto lim = lower_bound(osx[x].begin(), osx[x].end(), y);
			int limy = (lim != osx[x].begin()) ? *(lim - 1) : 0;
			limy = max(limy + 1, yu);
			if (limy == y) break;

			s += y - limy;
			y = limy;
			xb = x - 1;
			d = 4;
		}
		else if (d == 4) {
			auto lim = lower_bound(osy[y].begin(), osy[y].end(), x);
			int limx = (lim != osy[y].begin()) ? *(lim - 1) : 0;
			limx = max(limx + 1, xu);
			if (limx == x) break;

			s += x - limx;
			x = limx;
			yu = y + 1;
			d = 1;
		}
	}

	if (s == (n * m) - k) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}