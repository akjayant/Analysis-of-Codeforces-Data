
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
#define ld long double

vector<int> next(int a, int b) {
	if (a % 2 == 0) {
		if (b != 9) return { a,b + 1 };
		return { a + 1,9 };
	}
	if (b != 0) return { a,b - 1 };
	return { a + 1,0 };
}



int main() {
	cout.precision(200);
	vector<vector<int>> x(10, vector<int>(10));
	vector<vector<ld>> dp(10, vector<ld>(10));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) cin >> x[9 - i][j];
	}
	dp[9][0] = 0;
	dp[9][1] = 6;
	dp[9][2] = 6;
	dp[9][3] = 6;
	dp[9][4] = 6;
	dp[9][5] = 6;
	for (int i = 9; i >= 0; --i) {
		if(i%2==0)
		for (int j = 9; j >= 0; --j) {
			if (i *10+j<90 || i*10+j>95) {
				ld t = 0;
				int a = i, b = j;
				for (int k = 0; k < 6; k++) {
						auto f = next(a, b);
						a = f[0];
						b = f[1];
						t += min(dp[a][b], dp[a + x[a][b]][b]);
				}
				dp[i][j] = t / 6 + 1;
			}
		}
		else

			for (int j = 0; j <= 9; ++j) {
				if (i * 10 + j < 90 || i * 10 + j>95) {
					ld t = 0;
					int a = i, b = j;
					for (int k = 0; k < 6; k++) {
						auto f = next(a, b);
						a = f[0];
						b = f[1];
						t += min(dp[a][b], dp[a + x[a][b]][b]);
					}
					dp[i][j] = t / 6 + 1;
				}
			}



	}
	cout << dp[0][0];
}