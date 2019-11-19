#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 1;

ll dp[31][2][2][2][2];
string L, R;

ll solve(int cur, int fl1, int fr1, int fl2, int fr2) {
	if (cur > 30) {
		return 1;
	}
	if (dp[cur][fl1][fr1][fl2][fr2] != 0) {
		return dp[cur][fl1][fr1][fl2][fr2];
	}
	if (L[cur] == '0' or fl2) {
		if (L[cur] == '0' or fl1) { // 0 0
			int nfl1 = fl1;
			int nfr1 = fr1 | (R[cur] == '1');
			int nfl2 = fl2;
			int nfr2 = fr2 | (R[cur] == '1');
			dp[cur][fl1][fr1][fl2][fr2] += solve(cur + 1, nfl1, nfr1, nfl2, nfr2);
		}
		if (R[cur] == '1' or fr1) { // 1 0
			int nfl1 = fl1 | (L[cur] == '0');
			int nfr1 = fr1;
			int nfl2 = fl2;
			int nfr2 = fr2 | (R[cur] == '1');
			dp[cur][fl1][fr1][fl2][fr2] += solve(cur + 1, nfl1, nfr1, nfl2, nfr2);
		}
	}
	if (R[cur] == '1' or fr2) {
		if (L[cur] == '0' or fl1) { // 0 1
			int nfl1 = fl1;
			int nfr1 = fr1 | (R[cur] == '1');
			int nfl2 = fl2 | (L[cur] == '0');
			int nfr2 = fr2;
			dp[cur][fl1][fr1][fl2][fr2] += solve(cur + 1, nfl1, nfr1, nfl2, nfr2);
		}
	}
	return dp[cur][fl1][fr1][fl2][fr2];
}

string convert(int x) {
	string res = "";
	for (int i = 30; i >= 0; i--) {
		if (x & (1 << i)) {
			res.push_back('1');
		}
		else {
			res.push_back('0');
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof dp);
		int a, b;
		cin >> a >> b;
		R = convert(b);
		L = convert(a);
		while((int)L.size() < (int)R.size()) L = "0" + L;
		cout << solve(0, 0, 0, 0, 0) << endl;
	}
	return 0;
}