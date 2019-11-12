#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <stack>
#include <map>
#define int long long
#define double long double
using namespace std;
int p = 1000000007;



signed main() {
	int n;
	cin >> n;
	vector<vector<int>> res(n, vector<int>(n));
	bool f = 1;
	for (int i = 1; i <= n; i++) {
		if (f)
			for (int j = 1; j <= n; j++)
				res[j - 1][i - 1] = (i - 1) * n + j;
		else
			for (int j = 1; j <= n; j++)
				res[j - 1][i - 1] = (i - 1) * n + n - j + 1;
		f = 1 - f;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << res[i][j] << ' ';
		cout << endl;
	}
}