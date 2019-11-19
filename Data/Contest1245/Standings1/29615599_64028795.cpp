#include <bits/stdc++.h>
using namespace std;
typedef long double dbl;

pair<int, int> _get(int x, int y, int k) {
	if (k == 0) return {x, y};
	if (x&1) {	
		if (y < 9) {
			return _get(x, y + 1, k-1);
		} else {
			return _get(x - 1, y, k-1);
		} 
	} else {
		if (y > 0) {
			return _get(x, y - 1, k - 1);
		} else {
			return _get(x - 1, y, k - 1);
		}
	}
}

int h[20][20];
dbl memo[20][20];
bool vis[20][20];
dbl dp(int x, int y) {
	if (x == 0 and y == 0) return 0;
	if (vis[x][y]) return memo[x][y];
	vis[x][y] = 1;
	if (x == 0) {
		int den = 6;
		dbl num = 6;
		for (int k = 1; k <= 6; ++k) {
			if (y - k < 0) den -= 1;
			else num += dp(x, y - k);
		}
		return memo[x][y] = num / den;
	} else {
		int den = 6;
		dbl num = 6;		
		for (int k = 1; k <= 6; ++k) {		
			auto q = _get(x, y, k);
			dbl temp = dp(q.first, q.second);
			if (h[q.first][q.second] > 0) {
				int up = h[q.first][q.second];
				temp = min(temp, dp(q.first - up, q.second));
				//temp /= 2;
			}
			num += temp;
		}
		return memo[x][y] = num / den;
	}
}

int main() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cin >> h[i][j];
		}
	}
	cout << fixed << setprecision(9) << dp(9, 0) << endl;
	return 0;
}