
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
#include <sstream>
#include <map>
#include <math.h>
#include <stdio.h>
#include <stack>
#include <set>

using  namespace std;
#define ll long long


int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> x(n);
		int a, b, c;
		cin >> a >> b >> c;
		for (int i = 0; i < n; i++) {
			char cc;
			cin >> cc;
			if (cc == 'R') x[i] = 0;
			if (cc == 'P') x[i] = 1;
			if (cc == 'S') x[i] = 2;
		}
		vector < vector<vector<ll>>> dp(a + 1, vector<vector<ll>>(b + 1, vector<ll>(c + 1, 0))), kek;
		kek = dp;
		dp[0][0][0] = 0;
		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= b; j++) {
				for (int k = 0; k <= c; k++) {
					if (i + j + k > 0) {
						dp[i][j][k] = 0;
						if (x[i + j + k - 1] == 0) {
							if (k > 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
								if (dp[i][j][k] == dp[i][j][k - 1]) kek[i][j][k] = 2;
							}
							if (j > 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + 1);
								if (dp[i][j][k] == dp[i][j - 1][k] + 1) kek[i][j][k] = 1;
							}
							if (i > 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
								if (dp[i][j][k] == dp[i - 1][j][k]) kek[i][j][k] = 0;
							}
						}

						if (x[i + j + k - 1] == 1) {
							if (k > 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1] + 1);
								if (dp[i][j][k] == dp[i][j][k - 1] + 1) kek[i][j][k] = 2;
							}
							if (j > 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
								if (dp[i][j][k] == dp[i][j - 1][k]) kek[i][j][k] = 1;
							}
							if (i > 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
								if (dp[i][j][k] == dp[i - 1][j][k]) kek[i][j][k] = 0;
							}
						}




						if (x[i + j + k - 1] == 2) {
							if (k > 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
								if (dp[i][j][k] == dp[i][j][k - 1]) kek[i][j][k] = 2;
							}
							if (j > 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
								if (dp[i][j][k] == dp[i][j - 1][k]) kek[i][j][k] = 1;
							}
							if (i > 0)
							{
								dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + 1);
								if (dp[i][j][k] == dp[i - 1][j][k] + 1) kek[i][j][k] = 0;
							}
						}

					}
				}
			}
		}


		if (dp[a][b][c] >= (n + 1) / 2) {
			cout << "YES" << '\n';
			string ans = "";
			while (a + b + c != 0) {
				int t = kek[a][b][c];
				if (t == 0) {
					ans = "R" + ans;
					a--;
				}
				if (t == 1) {
					ans = "P" + ans;
					b--;
				}
				if (t == 2) {
					ans = "S" + ans;
					c--;
				}
			}
			cout << ans << '\n';
		}
		else
			cout << "NO" << '\n';
	}

}